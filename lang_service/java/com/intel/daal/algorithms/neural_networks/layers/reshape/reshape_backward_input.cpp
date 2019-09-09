/* file: reshape_backward_input.cpp */
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

#include <jni.h>
#include "com_intel_daal_algorithms_neural_networks_layers_reshape_ReshapeBackwardInput.h"

#include "daal.h"

#include "common_helpers.h"

#include "com_intel_daal_algorithms_neural_networks_layers_reshape_ReshapeLayerDataId.h"
#define auxDataId com_intel_daal_algorithms_neural_networks_layers_reshape_ReshapeLayerDataId_auxDataId

USING_COMMON_NAMESPACES()
using namespace daal::algorithms::neural_networks::layers::reshape;

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_reshape_ReshapeBackwardInput
 * Method:    cSetInput
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_reshape_ReshapeBackwardInput_cSetInput
  (JNIEnv *env, jobject thisObj, jlong inputAddr, jint id, jlong ntAddr)
{
    if (id == auxDataId)
    {
        jniInput<backward::Input>::set<LayerDataId, NumericTable>(inputAddr, id, ntAddr);
    }
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_reshape_ReshapeBackwardInput
 * Method:    cGetInput
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_reshape_ReshapeBackwardInput_cGetInput
  (JNIEnv *env, jobject thisObj, jlong inputAddr, jint id)
{
    if (id == auxDataId)
    {
        return jniInput<backward::Input>::get<LayerDataId, NumericTable>(inputAddr, id);
    }

    return (jlong)0;
}