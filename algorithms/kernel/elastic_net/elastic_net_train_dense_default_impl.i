/* file: elastic_net_train_dense_default_impl.i */
/*******************************************************************************
* Copyright 2014-2020 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of auxiliary functions for elastic net classification
//  (defaultDense) method.
//--
*/

#ifndef __ELASTIC_NET_TRAIN_DENSE_DEFAULT_IMPL_I__
#define __ELASTIC_NET_TRAIN_DENSE_DEFAULT_IMPL_I__

#include "algorithms/kernel/elastic_net/elastic_net_train_kernel.h"
#include "algorithms/kernel/elastic_net/elastic_net_model_impl.h"
#include "algorithms/kernel/service_error_handling.h"
#include "service/kernel/service_algo_utils.h"
#include "algorithms/optimization_solver/objective_function/mse_batch.h"
#include "algorithms/optimization_solver/coordinate_descent/coordinate_descent_batch.h"

#include "service/kernel/data_management/service_numeric_table.h"
#include "externals/service_math.h"

using namespace daal::algorithms::elastic_net::training::internal;
using namespace daal::algorithms::optimization_solver;
using namespace daal;

namespace daal
{
namespace algorithms
{
namespace elastic_net
{
namespace training
{
namespace internal
{
//////////////////////////////////////////////////////////////////////////////////////////
// TrainBatchKernel
//////////////////////////////////////////////////////////////////////////////////////////
template <typename algorithmFPType, elastic_net::training::Method method, CpuType cpu>
services::Status TrainBatchKernel<algorithmFPType, method, cpu>::compute(
    const HostAppIfacePtr & pHost, const NumericTablePtr & x, const NumericTablePtr & y, elastic_net::Model & m, Result & res, const Parameter & par,
    services::SharedPtr<daal::algorithms::optimization_solver::mse::Batch<algorithmFPType> > & objFunc)
{
    services::Status s;
    const size_t nFeatures           = x->getNumberOfColumns();
    const size_t nRows               = x->getNumberOfRows();
    const size_t p                   = nFeatures + 1;
    const size_t nDependentVariables = m.getBeta()->getNumberOfRows();
    DAAL_ASSERT(p == m.getNumberOfBetas());

    algorithmFPType * xMeansPtr;
    daal::internal::TArray<algorithmFPType, cpu> xMeans;

    algorithmFPType * yMeansPtr;
    daal::internal::TArray<algorithmFPType, cpu> yMeans;

    NumericTablePtr xTrain = x;
    NumericTablePtr yTrain = y;
    if (par.interceptFlag == true)
    {
        if (par.dataUseInComputation == doNotUse)
        {
            int result = 0;
            xTrain     = daal::internal::HomogenNumericTableCPU<algorithmFPType, cpu>::create(nFeatures, nRows, &s);
            DAAL_CHECK_STATUS_VAR(s);
            yTrain = daal::internal::HomogenNumericTableCPU<algorithmFPType, cpu>::create(nDependentVariables, nRows, &s);
            DAAL_CHECK_STATUS_VAR(s);
            daal::internal::WriteRows<algorithmFPType, cpu> xTrainBD(xTrain.get(), 0, nRows);
            DAAL_CHECK_BLOCK_STATUS(xTrainBD);
            daal::internal::WriteRows<algorithmFPType, cpu> yTrainBD(yTrain.get(), 0, nRows);
            DAAL_CHECK_BLOCK_STATUS(yTrainBD);
            algorithmFPType * xTrainPtr = xTrainBD.get();
            algorithmFPType * yTrainPtr = yTrainBD.get();

            daal::internal::WriteRows<algorithmFPType, cpu> xBD(x.get(), 0, nRows);
            DAAL_CHECK_BLOCK_STATUS(xBD);
            daal::internal::WriteRows<algorithmFPType, cpu> yBD(y.get(), 0, nRows);
            DAAL_CHECK_BLOCK_STATUS(yBD);
            algorithmFPType * xPtr = xBD.get();
            algorithmFPType * yPtr = yBD.get();
            result |= daal::services::internal::daal_memcpy_s(xTrainPtr, nFeatures * nRows * sizeof(algorithmFPType), xPtr,
                                                              nFeatures * nRows * sizeof(algorithmFPType));
            result |= daal::services::internal::daal_memcpy_s(yTrainPtr, nDependentVariables * nRows * sizeof(algorithmFPType), yPtr,
                                                              nDependentVariables * nRows * sizeof(algorithmFPType));
            DAAL_CHECK(!result, services::ErrorMemoryCopyFailedInternal);
        }

        daal::internal::WriteRows<algorithmFPType, cpu> xBD(xTrain.get(), 0, nRows);
        DAAL_CHECK_BLOCK_STATUS(xBD);
        daal::internal::WriteRows<algorithmFPType, cpu> yBD(yTrain.get(), 0, nRows);
        DAAL_CHECK_BLOCK_STATUS(yBD);
        algorithmFPType * xPtr = xBD.get();
        algorithmFPType * yPtr = yBD.get();

        algorithmFPType inversedNRows = (algorithmFPType)1.0 / (algorithmFPType)nRows;
        yMeans.reset(nDependentVariables);
        yMeansPtr = yMeans.get();
        DAAL_CHECK_MALLOC(yMeansPtr);
        for (size_t i = 0; i < nDependentVariables; i++) //[TBD] do in parallel
        {
            yMeansPtr[i] = 0;
        }
        for (size_t i = 0; i < nRows; i++)
        {
            PRAGMA_IVDEP
            PRAGMA_VECTOR_ALWAYS
            for (size_t id = 0; id < nDependentVariables; ++id)
            {
                yMeansPtr[id] += yPtr[i * nDependentVariables + id];
            }
        }
        for (size_t i = 0; i < nDependentVariables; ++i)
        {
            yMeansPtr[i] *= inversedNRows;
        }
        for (size_t i = 0; i < nRows; i++)
        {
            for (size_t id = 0; id < nDependentVariables; ++id)
            {
                yPtr[i * nDependentVariables + id] -= yMeansPtr[id];
            }
        }

        xMeans.reset(nFeatures);
        xMeansPtr = xMeans.get();
        DAAL_CHECK_MALLOC(xMeansPtr);

        for (size_t i = 0; i < nFeatures; ++i) xMeansPtr[i] = 0;

        const size_t blockSize = 256;
        size_t nBlocks         = nRows / blockSize;
        nBlocks += (nBlocks * blockSize != nRows);

        DAAL_OVERFLOW_CHECK_BY_MULTIPLICATION(size_t, nFeatures, sizeof(algorithmFPType));

        TlsMem<algorithmFPType, cpu, services::internal::ScalableCalloc<algorithmFPType, cpu> > tlsData(nFeatures);
        daal::threader_for(nBlocks, nBlocks, [&](const size_t iBlock) {
            algorithmFPType * sum  = tlsData.local();
            const size_t startRow  = iBlock * blockSize;
            const size_t finishRow = (iBlock + 1 == nBlocks ? nRows : (iBlock + 1) * blockSize);
            for (size_t i = startRow; i < finishRow; i++)
            {
                PRAGMA_IVDEP
                PRAGMA_VECTOR_ALWAYS
                for (size_t j = 0; j < nFeatures; j++)
                {
                    sum[j] += xPtr[i * nFeatures + j];
                }
            }
        });
        tlsData.reduce([&](algorithmFPType * localSum) {
            PRAGMA_IVDEP
            PRAGMA_VECTOR_ALWAYS
            for (size_t j = 0; j < nFeatures; j++)
            {
                xMeansPtr[j] += localSum[j];
            }
        });

        for (size_t i = 0; i < nFeatures; ++i)
        {
            xMeansPtr[i] *= inversedNRows;
        }

        daal::threader_for(nBlocks, nBlocks, [&](const size_t iBlock) {
            const size_t startRow  = iBlock * blockSize;
            const size_t finishRow = (iBlock + 1 == nBlocks ? nRows : (iBlock + 1) * blockSize);
            for (size_t i = startRow; i < finishRow; i++)
            {
                PRAGMA_IVDEP
                PRAGMA_VECTOR_ALWAYS
                for (size_t j = 0; j < nFeatures; j++)
                {
                    xPtr[i * nFeatures + j] -= xMeansPtr[j];
                }
            }
        });
    }
    services::SharedPtr<optimization_solver::iterative_solver::Batch> pSolver(par.optimizationSolver); //par.optimizationSolver->clone();
    if (!pSolver.get())
    {
        //create cd solver
        services::SharedPtr<optimization_solver::coordinate_descent::Batch<algorithmFPType> > cdAlgorithm =
            optimization_solver::coordinate_descent::Batch<algorithmFPType>::create();
        NumericTablePtr pArg = daal::internal::HomogenNumericTableCPU<algorithmFPType, cpu>::create(nDependentVariables, p, &s);
        DAAL_CHECK_STATUS_VAR(s);
        daal::internal::WriteRows<algorithmFPType, cpu> pArgBD(pArg.get(), 0, p);
        DAAL_CHECK_BLOCK_STATUS(pArgBD);
        algorithmFPType * pArgPtr = pArgBD.get();
        daal::services::internal::service_memset<algorithmFPType, cpu>(pArgPtr, 0, nDependentVariables * p);

        cdAlgorithm->input.set(optimization_solver::iterative_solver::inputArgument, pArg);

        cdAlgorithm->parameter().nIterations            = 10000;
        cdAlgorithm->parameter().accuracyThreshold      = 0.00001;
        cdAlgorithm->parameter().selection              = optimization_solver::coordinate_descent::cyclic;
        cdAlgorithm->parameter().positive               = false;
        cdAlgorithm->parameter().skipTheFirstComponents = true;
        pSolver                                         = cdAlgorithm;
    }

    objFunc->input.set(mse::data, xTrain);
    objFunc->input.set(mse::dependentVariables, yTrain);
    objFunc->parameter().interceptFlag = false;

    objFunc->parameter().penaltyL1 = par.penaltyL1;
    objFunc->parameter().penaltyL2 = par.penaltyL2;

    pSolver->getParameter()->function = objFunc;

    if (!(pSolver->getInput()->get(optimization_solver::iterative_solver::inputArgument).get()))
    {
        NumericTablePtr pArg = daal::internal::HomogenNumericTableCPU<algorithmFPType, cpu>::create(nDependentVariables, p, &s);
        DAAL_CHECK_STATUS_VAR(s);
        daal::internal::WriteRows<algorithmFPType, cpu> pArgBD(pArg.get(), 0, p);
        DAAL_CHECK_BLOCK_STATUS(pArgBD);
        algorithmFPType * pArgPtr = pArgBD.get();
        daal::services::internal::service_memset<algorithmFPType, cpu>(pArgPtr, 0, nDependentVariables * p);
        DAAL_CHECK_STATUS_VAR(s);
        pSolver->getInput()->set(optimization_solver::iterative_solver::inputArgument, pArg);
    }

    if (!s) return s;
    DAAL_CHECK_STATUS(s, pSolver->compute());

    //write data to model
    daal::internal::ReadRows<algorithmFPType, cpu> ar(*(pSolver->getResult()->get(optimization_solver::iterative_solver::minimum)), 0, p);
    daal::internal::WriteRows<algorithmFPType, cpu> br(*m.getBeta(), 0, nDependentVariables);
    DAAL_CHECK_BLOCK_STATUS(ar);
    DAAL_CHECK_BLOCK_STATUS(br);
    const algorithmFPType * a = ar.get();
    algorithmFPType * pBeta   = br.get();

    for (size_t i = 0; i < nDependentVariables; i++)
    {
        for (size_t j = 1; j < p; j++)
        {
            pBeta[i * p + j] = a[j * nDependentVariables + i];
        }
    }
    if (par.interceptFlag)
    {
        daal::internal::TArray<algorithmFPType, cpu> dotPtr(nDependentVariables);
        algorithmFPType * dot = dotPtr.get();
        for (size_t i = 0; i < nDependentVariables; i++) dot[i] = 0;

        for (size_t i = 0; i < nDependentVariables; i++)
        {
            for (size_t j = 0; j < nFeatures; j++)
            {
                dot[i] += xMeansPtr[j] * pBeta[i * p + j + 1];
            }
        }
        for (size_t j = 0; j < nDependentVariables; ++j) pBeta[p * j + 0] = yMeansPtr[j] - dot[j];
    }
    else
    {
        for (size_t j = 0; j < nDependentVariables; ++j) pBeta[p * j + 0] = 0;
    }

    return s;
}

} /* namespace internal */
} /* namespace training */
} /* namespace elastic_net */
} /* namespace algorithms */
} /* namespace daal */

#endif
