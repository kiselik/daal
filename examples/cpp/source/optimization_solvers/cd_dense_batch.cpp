/* file: cd_dense_batch.cpp */
/*******************************************************************************
* Copyright 2014-2019 Intel Corporation.
*
* This software and the related documents are Intel copyrighted  materials,  and
* your use of  them is  governed by the  express license  under which  they were
* provided to you (License).  Unless the License provides otherwise, you may not
* use, modify, copy, publish, distribute,  disclose or transmit this software or
* the related documents without Intel's prior written permission.
*
* This software and the related documents  are provided as  is,  with no express
* or implied  warranties,  other  than those  that are  expressly stated  in the
* License.
*******************************************************************************/

/*
!  Content:
!    C++ example of the Coordinate descent algorithm
!******************************************************************************/

/**
 * <a name="DAAL-EXAMPLE-CPP-CD_BATCH"></a>
 * \example cd_dense_batch.cpp
 */

#include "daal.h"
#include "service.h"

using namespace std;
using namespace daal;
using namespace daal::algorithms;
using namespace daal::data_management;

string datasetFileName = "../data/batch/mse.csv";

const size_t nIterations = 1000;
const size_t nFeatures = 3;

const double accuracyThreshold = 0.000001;

float initialPoint[nFeatures + 1] = {0, 0, 0, 0};

int main(int argc, char *argv[])
{
    /* Initialize FileDataSource<CSVFeatureManager> to retrieve the input data from a .csv file */
    FileDataSource<CSVFeatureManager> dataSource(datasetFileName,
            DataSource::notAllocateNumericTable,
            DataSource::doDictionaryFromContext);

    /* Create Numeric Tables for data and values for dependent variable */
    NumericTablePtr data(new HomogenNumericTable<>(nFeatures, 0, NumericTable::doNotAllocate));
    NumericTablePtr dependentVariables(new HomogenNumericTable<>(1, 0, NumericTable::doNotAllocate));
    NumericTablePtr mergedData(new MergedNumericTable(data, dependentVariables));

    /* Retrieve the data from the input file */
    dataSource.loadDataBlock(mergedData.get());

    size_t nVectors = data->getNumberOfRows();

    services::SharedPtr<optimization_solver::mse::Batch<> > mseObjectiveFunction(new optimization_solver::mse::Batch<>(nVectors));
    mseObjectiveFunction->input.set(optimization_solver::mse::data, data);
    mseObjectiveFunction->input.set(optimization_solver::mse::dependentVariables, dependentVariables);

    /* Create objects to compute the Coordinate descent result using the default method */
    optimization_solver::coordinate_descent::interface1::Batch<>* cdAlgorithm = new optimization_solver::coordinate_descent::interface1::Batch<>(mseObjectiveFunction);

    /* Set input objects for the the Coordinate descent algorithm */
    cdAlgorithm->input.set(optimization_solver::iterative_solver::inputArgument,
                           NumericTablePtr(new HomogenNumericTable<>(initialPoint, 1, nFeatures + 1)));

    cdAlgorithm->parameter().nIterations = nIterations;
    cdAlgorithm->parameter().accuracyThreshold = accuracyThreshold;
    cdAlgorithm->parameter().selection = optimization_solver::coordinate_descent::cyclic;

    /* Compute the Coordinate descent result */
    cdAlgorithm->compute();

    /* Print computed the Coordinate descent result */
    printNumericTable(cdAlgorithm->getResult()->get(optimization_solver::iterative_solver::minimum), "Minimum:");
    printNumericTable(cdAlgorithm->getResult()->get(optimization_solver::iterative_solver::nIterations), "Number of iterations performed:");

    return 0;
}