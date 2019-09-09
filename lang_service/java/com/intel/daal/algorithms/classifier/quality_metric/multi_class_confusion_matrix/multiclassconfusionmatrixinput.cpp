/* file: multiclassconfusionmatrixinput.cpp */
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
#include "com_intel_daal_algorithms_classifier_quality_metric_multi_class_confusion_matrix_MultiClassConfusionMatrixInput.h"

#include "common_helpers.h"

#include "com_intel_daal_algorithms_classifier_quality_metric_multi_class_confusion_matrix_MultiClassConfusionMatrixInputId.h"
#define PredictedLabels com_intel_daal_algorithms_classifier_quality_metric_multi_class_confusion_matrix_MultiClassConfusionMatrixInputId_PredictedLabels
#define GroundTruthL com_intel_daal_algorithms_classifier_quality_metric_multi_class_confusion_matrix_MultiClassConfusionMatrixInputId_GroundTruthLabels

USING_COMMON_NAMESPACES();
using namespace daal::algorithms::classifier::quality_metric::multiclass_confusion_matrix;
using namespace daal::algorithms::classifier::quality_metric;

/*
 * Class:     com_intel_daal_algorithms_classifier_quality_metric_multi_class_confusion_matrix_MultiClassConfusionMatrixInput
 * Method:    cSetInputTable
 * Signature: (JIJ)V
 */
JNIEXPORT void
 JNICALL Java_com_intel_daal_algorithms_classifier_quality_1metric_multi_1class_1confusion_1matrix_MultiClassConfusionMatrixInput_cSetInputTable
  (JNIEnv *, jobject, jlong inputAddr, jint id, jlong ntAddr)
{
    if(id != PredictedLabels && id != GroundTruthL) return;

    jniInput<multiclass_confusion_matrix::Input>::set<multiclass_confusion_matrix::InputId, NumericTable>(inputAddr, id, ntAddr);
}

/*
 * Class:     com_intel_daal_algorithms_classifier_quality_metric_multi_class_confusion_matrix_MultiClassConfusionMatrixInput
 * Method:    cGetInputTable
 * Signature: (JI)J
 */
JNIEXPORT jlong
 JNICALL Java_com_intel_daal_algorithms_classifier_quality_1metric_multi_1class_1confusion_1matrix_MultiClassConfusionMatrixInput_cGetInputTable
  (JNIEnv *, jobject, jlong inputAddr, jint id)
{
    if(id != PredictedLabels && id != GroundTruthL) return (jlong)-1;

    return jniInput<multiclass_confusion_matrix::Input>::get<multiclass_confusion_matrix::InputId, NumericTable>(inputAddr, id);

}