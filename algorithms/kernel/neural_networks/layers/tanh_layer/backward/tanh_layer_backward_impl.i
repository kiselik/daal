/* file: tanh_layer_backward_impl.i */
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
//++
//  Implementation of hyperbolic tangent algorithm
//--
*/

#ifndef __TANH_LAYER_BACKWARD_IMPL_I__
#define __TANH_LAYER_BACKWARD_IMPL_I__

using namespace daal::services;

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace tanh
{
namespace backward
{
namespace internal
{

template<typename algorithmFPType, Method method, CpuType cpu>
services::Status TanhKernel<algorithmFPType, method, cpu>::compute(const Tensor &inputTensor, const Tensor &forwardOutputTensor, Tensor &resultTensor)
{
    __DAAL_MAKE_TENSOR_THREADSAFE(const_cast<Tensor *>(&forwardOutputTensor))
    __DAAL_MAKE_TENSOR_THREADSAFE(&resultTensor)


    Status s = computeImpl<cpu>(inputTensor, [=, &inputTensor, &forwardOutputTensor, &resultTensor](size_t fDimN, size_t *fDims, size_t nRowsToProcess, const TensorOffsetLayout &layout) -> Status
    {
        ReadSubtensor<algorithmFPType, cpu, Tensor> inputBlock(const_cast<Tensor &>(inputTensor), fDimN, fDims, 0, nRowsToProcess, layout);
        DAAL_CHECK_BLOCK_STATUS(inputBlock);
        const algorithmFPType *inputArray = inputBlock.get();

        ReadSubtensor<algorithmFPType, cpu, Tensor> forwardBlock(const_cast<Tensor &>(forwardOutputTensor), fDimN, fDims, 0, nRowsToProcess, layout);
        DAAL_CHECK_BLOCK_STATUS(forwardBlock);
        const algorithmFPType *forwardOutputArray = forwardBlock.get();

        WriteSubtensor<algorithmFPType, cpu, Tensor> resultBlock(resultTensor, fDimN, fDims, 0, nRowsToProcess, layout);
        DAAL_CHECK_BLOCK_STATUS(resultBlock);
        algorithmFPType *resultArray = resultBlock.get();

        size_t nDataElements = inputBlock.getSize();

       PRAGMA_IVDEP
       PRAGMA_VECTOR_ALWAYS
        for(size_t i = 0; i < nDataElements; i++)
        {
            resultArray[i] = inputArray[i] * ( (algorithmFPType)1 - forwardOutputArray[i] * forwardOutputArray[i] );
        }
        return Status();
    });
    return s;
}

} // namespace internal
} // namespace backward
} // namespace tanh
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal

#endif