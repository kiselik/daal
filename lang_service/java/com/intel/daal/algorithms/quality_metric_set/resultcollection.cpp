/* file: resultcollection.cpp */
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
#include "com_intel_daal_algorithms_quality_metric_set_ResultCollection.h"

using namespace daal;
using namespace daal::algorithms;
using namespace daal::data_management;
using namespace daal::algorithms::quality_metric_set;

/*
 * Class:     com_intel_daal_algorithms_ResultCollection
 * Method:    cInit
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_quality_1metric_1set_ResultCollection_cInit
(JNIEnv *, jobject, jlong algAddr)
{
    ResultCollectionPtr *shPtr = new ResultCollectionPtr();
    *shPtr = ((Batch *)algAddr)->getResultCollection();
    return (jlong)shPtr;
}

/*
 * Class:     com_intel_daal_algorithms_ResultCollection
 * Method:    cAddResult
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_quality_1metric_1set_ResultCollection_cAddResult
(JNIEnv *, jobject, jlong colAddr, jint key, jlong resAddr)
{
    ResultCollectionPtr *shPtr = (ResultCollectionPtr *)colAddr;
    ResultCollection *resCol = shPtr->get();
    resCol->add(key, *(ResultPtr *)resAddr);
}

/*
 * Class:     com_intel_daal_algorithms_quality_metric_set_ResultCollection
 * Method:    cGetResult
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_quality_1metric_1set_ResultCollection_cGetResult
(JNIEnv *, jobject, jlong colAddr, jint key)
{
    SerializationIfacePtr *resShPtr = new SerializationIfacePtr();
    ResultCollectionPtr shPtr = (*(ResultCollectionPtr *)colAddr);
    *resShPtr = shPtr->getResult((size_t)key);
    return (jlong)(resShPtr);
}