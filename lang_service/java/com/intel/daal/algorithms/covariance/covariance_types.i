/* file: covariance_types.i */
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

#include "daal.h"

using namespace daal::algorithms;

/* Covariance computation methods */
#include "com_intel_daal_algorithms_covariance_Method.h"
#define DefaultDense    com_intel_daal_algorithms_covariance_Method_DefaultDense
#define SinglePassDense com_intel_daal_algorithms_covariance_Method_SinglePassDense
#define SumDense        com_intel_daal_algorithms_covariance_Method_SumDense
#define FastCSR         com_intel_daal_algorithms_covariance_Method_FastCSR
#define SinglePassCSR   com_intel_daal_algorithms_covariance_Method_SinglePassCSR
#define SumCSR          com_intel_daal_algorithms_covariance_Method_SumCSR