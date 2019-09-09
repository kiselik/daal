/* file: quality_metric_set_parameter.cpp */
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
#include "com_intel_daal_algorithms_linear_regression_quality_metric_set_QualityMetricSetParameter.h"

using namespace daal::algorithms::linear_regression::quality_metric_set;

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_set_QualityMetricSetParameter
* Method:    cSetNBeta
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_1set_QualityMetricSetParameter_cSetNBeta
(JNIEnv *, jobject, jlong parAddr, jlong nBeta)
{
    (*(Parameter *)parAddr).numBeta = nBeta;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_set_QualityMetricSetParameter
* Method:    cGetNBeta
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_1set_QualityMetricSetParameter_cGetNBeta
(JNIEnv *, jobject, jlong parAddr)
{
    return(jlong)(*(Parameter *)parAddr).numBeta;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_set_QualityMetricSetParameter
* Method:    cSetNBetaReducedModel
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_1set_QualityMetricSetParameter_cSetNBetaReducedModel
(JNIEnv *, jobject, jlong parAddr, jlong nBetaReducedModel)
{
    (*(Parameter *)parAddr).numBetaReducedModel = nBetaReducedModel;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_set_QualityMetricSetParameter
* Method:    cGetNBetaReducedModel
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_1set_QualityMetricSetParameter_cGetNBetaReducedModel
(JNIEnv *, jobject, jlong parAddr)
{
    return(jlong)(*(Parameter *)parAddr).numBetaReducedModel;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_set_QualityMetricSetParameter
* Method:    cSetAlpha
* Signature: (JD)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_1set_QualityMetricSetParameter_cSetAlpha
(JNIEnv *, jobject, jlong parAddr, jdouble alpha)
{
    (*(Parameter *)parAddr).alpha = alpha;
}


/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_set_QualityMetricSetParameter
* Method:    cGetAlpha
* Signature: (J)D
*/
JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_1set_QualityMetricSetParameter_cGetAlpha
(JNIEnv *, jobject, jlong parAddr)
{
    return(jdouble)(*(Parameter *)parAddr).alpha;
}

/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_set_QualityMetricSetParameter
* Method:    cSetAccuracyThreshold
* Signature: (JD)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_1set_QualityMetricSetParameter_cSetAccuracyThreshold
(JNIEnv *, jobject, jlong parAddr, jdouble accuracyThreshold)
{
    (*(Parameter *)parAddr).accuracyThreshold = accuracyThreshold;
}
/*
* Class:     com_intel_daal_algorithms_linear_regression_quality_metric_set_QualityMetricSetParameter
* Method:    cGetAccuracyThreshold
* Signature: (J)D
*/
JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_linear_1regression_quality_1metric_1set_QualityMetricSetParameter_cGetAccuracyThreshold
(JNIEnv *, jobject, jlong parAddr)
{
    return(jdouble)(*(Parameter *)parAddr).accuracyThreshold;
}