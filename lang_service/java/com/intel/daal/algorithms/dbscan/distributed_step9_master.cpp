/* file: distributed_step9_master.cpp */
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
#include "daal.h"
#include "com_intel_daal_algorithms_dbscan_DistributedStep9Master.h"

#include "common_helpers.h"

USING_COMMON_NAMESPACES()
using namespace daal::algorithms::dbscan;

JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_dbscan_DistributedStep9Master_cInit
(JNIEnv *, jobject, jint prec, jint method)
{
    return jniDistributed<step9Master, dbscan::Method, Distributed, defaultDense>::newObj(prec, method);
}

JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_dbscan_DistributedStep9Master_cGetInput
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniDistributed<step9Master, dbscan::Method, Distributed, defaultDense>::getInput(prec, method, algAddr);
}

JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_dbscan_DistributedStep9Master_cGetResult
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniDistributed<step9Master, dbscan::Method, Distributed, defaultDense>::getResult(prec, method, algAddr);
}

JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_dbscan_DistributedStep9Master_cSetResult
(JNIEnv *, jobject, jlong algAddr, jint prec, jint method, jlong resultAddr)
{
    jniDistributed<step9Master, dbscan::Method, Distributed, defaultDense>::
        setResult<dbscan::DistributedResultStep9>(prec, method, algAddr, resultAddr);
}

JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_dbscan_DistributedStep9Master_cGetPartialResult
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniDistributed<step9Master, dbscan::Method, Distributed, defaultDense>::getPartialResult(prec, method, algAddr);
}

JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_dbscan_DistributedStep9Master_cSetPartialResult
(JNIEnv *, jobject, jlong algAddr, jint prec, jint method, jlong partialResultAddr)
{
    jniDistributed<step9Master, dbscan::Method, Distributed, defaultDense>::
        setPartialResult<dbscan::DistributedPartialResultStep9>(prec, method, algAddr, partialResultAddr);
}

JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_dbscan_DistributedStep9Master_cClone
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniDistributed<step9Master, dbscan::Method, Distributed, defaultDense>::getClone(prec, method, algAddr);
}