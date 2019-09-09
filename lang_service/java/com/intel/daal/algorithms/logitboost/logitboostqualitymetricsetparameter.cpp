/* file: logitboostqualitymetricsetparameter.cpp */
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

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "daal.h"
#include "com_intel_daal_algorithms_logitboost_quality_metric_set_QualityMetricSetParameter.h"

using namespace daal::algorithms::logitboost::quality_metric_set;

/*
 * Class:     com_intel_daal_algorithms_logitboost_quality_metric_set_QualityMetricSetParameter
 * Method:    cSetNClasses
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_logitboost_quality_1metric_1set_QualityMetricSetParameter_cSetNClasses
(JNIEnv *, jobject, jlong parAddr, jlong nClasses)
{
    (*(Parameter *)parAddr).nClasses = nClasses;
}

/*
 * Class:     com_intel_daal_algorithms_logitboost_quality_metric_set_QualityMetricSetParameter
 * Method:    cGetNClasses
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_logitboost_quality_1metric_1set_QualityMetricSetParameter_cGetNClasses
(JNIEnv *, jobject, jlong parAddr)
{
    return(jlong)(*(Parameter *)parAddr).nClasses;
}