/* file: BackwardInputLayerDataId.java */
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
 * @ingroup layers_backward
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers;

import java.lang.annotation.Native;

import com.intel.daal.utils.*;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__BACKWARDINPUTLAYERDATAID"></a>
 * \brief Available identifiers of input objects for the backward layer
 */
public final class BackwardInputLayerDataId {
    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    private int _value;

    /**
     * Constructs the input object identifier using the provided value
     * @param value     Value corresponding to the input object identifier
     */
    public BackwardInputLayerDataId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the input object identifier
     * @return Value corresponding to the input object identifier
     */
    public int getValue() {
        return _value;
    }

    @Native private static final int inputFromForwardId = 1;

    public static final BackwardInputLayerDataId inputFromForward = new BackwardInputLayerDataId(inputFromForwardId);
            /*!< Input structure retrieved from the result of the forward layer */
}
/** @} */