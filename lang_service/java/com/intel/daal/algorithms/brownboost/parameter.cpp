/* file: parameter.cpp */
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
#include <jni.h>/* Header for class com_intel_daal_algorithms_brownboost_Batch */

#include "daal.h"
#include "com_intel_daal_algorithms_brownboost_Parameter.h"

using namespace daal;
using namespace daal::algorithms;

JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_brownboost_Parameter_cSetAccuracyThreshold
(JNIEnv *env, jobject thisObj, jlong parAddr, jdouble acc)
{
    (*(brownboost::Parameter *)parAddr).accuracyThreshold = acc;
}

JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_brownboost_Parameter_cGetAccuracyThreshold
(JNIEnv *env, jobject thisObj, jlong parAddr)
{
    return(jdouble)(*(brownboost::Parameter *)parAddr).accuracyThreshold;
}

JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_brownboost_Parameter_cSetnewtonRaphsonAccuracyThreshold
(JNIEnv *env, jobject thisObj, jlong parAddr, jdouble acc)
{
    (*(brownboost::Parameter *)parAddr).newtonRaphsonAccuracyThreshold = acc;
}

JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_brownboost_Parameter_cGetnewtonRaphsonAccuracyThreshold
(JNIEnv *env, jobject thisObj, jlong parAddr)
{
    return(jdouble)(*(brownboost::Parameter *)parAddr).newtonRaphsonAccuracyThreshold;
}

JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_brownboost_Parameter_cSetThr
(JNIEnv *env, jobject thisObj, jlong parAddr, jdouble acc)
{
    (*(brownboost::Parameter *)parAddr).degenerateCasesThreshold = acc;
}

JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_brownboost_Parameter_cGetThr
(JNIEnv *env, jobject thisObj, jlong parAddr)
{
    return(jdouble)(*(brownboost::Parameter *)parAddr).degenerateCasesThreshold;
}

JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_brownboost_Parameter_cSetMaxIterations
(JNIEnv *env, jobject thisObj, jlong parAddr, jlong nIter)
{
    (*(brownboost::Parameter *)parAddr).maxIterations = nIter;
}

JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_brownboost_Parameter_cGetMaxIterations
(JNIEnv *env, jobject thisObj, jlong parAddr)
{
    return(jlong)(*(brownboost::Parameter *)parAddr).maxIterations;
}

JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_brownboost_Parameter_cSetnewtonRaphsonMaxIterations
(JNIEnv *env, jobject thisObj, jlong parAddr, jlong nIter)
{
    (*(brownboost::Parameter *)parAddr).newtonRaphsonMaxIterations = nIter;
}

JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_brownboost_Parameter_cGetnewtonRaphsonMaxIterations
(JNIEnv *env, jobject thisObj, jlong parAddr)
{
    return(jlong)(*(brownboost::Parameter *)parAddr).newtonRaphsonMaxIterations;
}