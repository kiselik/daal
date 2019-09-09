/* file: decision_tree_regression_predict_dense_default_batch_fpt_dispatcher.cpp */
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
//  Implementation of Decision tree algorithm container - a class that contains fast Decision tree prediction kernels for supported
//  architectures.
//--
*/

#include "decision_tree_regression_predict_dense_default_batch_container.h"

namespace daal
{
namespace algorithms
{
__DAAL_INSTANTIATE_DISPATCH_CONTAINER_KM(decision_tree::regression::prediction::BatchContainer, batch, DAAL_FPTYPE, \
                                      decision_tree::regression::prediction::defaultDense)
} // namespace algorithms
} // namespace daal