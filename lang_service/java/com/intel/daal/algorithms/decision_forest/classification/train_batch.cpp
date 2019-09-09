/* file: train_batch.cpp */
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
#include "com_intel_daal_algorithms_decision_forest_classification_training_TrainingBatch.h"
#include "common_helpers.h"

USING_COMMON_NAMESPACES()
namespace dfct = daal::algorithms::decision_forest::classification::training;

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_training_TrainingBatch
* Method:    cInit
* Signature: (IIJ)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_training_TrainingBatch_cInit
(JNIEnv *, jobject thisObj, jint prec, jint method, jlong nClasses)
{
    return jniBatch<dfct::Method, dfct::Batch, dfct::defaultDense>::newObj(prec, method, nClasses);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_training_TrainingBatch
* Method:    cInitParameter
* Signature: (JIII)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_training_TrainingBatch_cInitParameter
(JNIEnv *, jobject thisObj, jlong algAddr, jint prec, jint method, jint cmode)
{
    return jniBatch<dfct::Method, dfct::Batch, dfct::defaultDense>::getParameter(prec, method, algAddr);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_classification_training_TrainingBatch
* Method:    cClone
* Signature: (JII)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_classification_training_TrainingBatch_cClone
(JNIEnv *, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniBatch<dfct::Method, dfct::Batch, dfct::defaultDense>::getClone(prec, method, algAddr);
}