/* file: OptionalDataId.java */
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
 * @ingroup sgd
 * @{
 */
package com.intel.daal.algorithms.optimization_solver.sgd;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__OPTIMIZATION_SOLVER__OPTIONALDATAID"></a>
 * @brief Available identifiers of OptionalData objects for the algorithm
 */
public final class OptionalDataId {
    private int _value;

    /**
     * Constructs the optional data object identifier using the provided value
     * @param value     Value corresponding to the optional data object identifier
     */
    public OptionalDataId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the optional data object identifier
     * @return Value corresponding to the optional data object identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int pastUpdateVectorId = 0;

    public static final OptionalDataId pastUpdateVector = new OptionalDataId(pastUpdateVectorId); /*!< NumericTable of size p x 1 with vector update from past iteration. Applied for momentum method */
}
/** @} */