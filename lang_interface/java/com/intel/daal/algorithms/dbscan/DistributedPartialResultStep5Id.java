/* file: DistributedPartialResultStep5Id.java */
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

/**
 * @ingroup dbscan_distributed
 * @{
 */
package com.intel.daal.algorithms.dbscan;

import com.intel.daal.utils.*;
/**
 * <a name="DAAL-CLASS-ALGORITHMS__DBSCAN__DISTRIBUTEDPARTIALRESULTSTEP5ID"></a>
 * @brief Available identifiers of partial results of the DBSCAN training algorithm obtained
 * in the fifth step of the distributed processing mode
 */
public final class DistributedPartialResultStep5Id {
    private int _value;

    static {
        LibUtils.loadLibrary();
    }

    /**
     * Constructs the partial result object identifier using the provided value
     * @param value     Value corresponding to the partial result object identifier
     */
    public DistributedPartialResultStep5Id(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the partial result object identifier
     * @return Value corresponding to the partial result object identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int partitionedHaloDataValue        = 0;
    private static final int partitionedHaloDataIndicesValue = 1;
    private static final int partitionedHaloWeightsValue     = 2;

    public static final DistributedPartialResultStep5Id partitionedHaloData = new DistributedPartialResultStep5Id(partitionedHaloDataValue);
        /*!< Collection of tables containing halo observations */
    public static final DistributedPartialResultStep5Id partitionedHaloDataIndices = new DistributedPartialResultStep5Id(partitionedHaloDataIndicesValue);
        /*!< Collection of tables containing indices of halo observations */
    public static final DistributedPartialResultStep5Id partitionedHaloWeights = new DistributedPartialResultStep5Id(partitionedHaloWeightsValue);
        /*!< Collection of tables containing weights of halo observations */
}
/** @} */