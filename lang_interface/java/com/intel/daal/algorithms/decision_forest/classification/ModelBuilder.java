/* file: ModelBuilder.java */
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
 * @defgroup decision_forest_classification Classification
 * @brief Contains classes for decision forest classification algorithm
 * @ingroup decision_forest
 * @{
 */

package com.intel.daal.algorithms.decision_forest.classification;

import com.intel.daal.utils.*;
import com.intel.daal.data_management.data.SerializableBase;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__DECISION_FOREST__CLASSIFICATION__MODEL__BUILDER"></a>
 * @brief %Class for building model of the decision forest classification algorithm
 */
public class ModelBuilder extends SerializableBase {
    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    /*!< %Reserved value for root nodes */
    public static final long noParent = -1;

    /**
     * Constructs the decision forest classification model builder
     * @param context   Context to manage decision forest classification model builder
     * @param nClasses  Number of classes
     * @param nTrees    Number of trees
     */
    public ModelBuilder(DaalContext context, long nClasses, long nTrees) {
        super(context);
        this.cObject = cInit(nClasses, nTrees);
    }

    /**
     * Creates certain tree in the decision forest model
     * @param nNodes   Number of nodes in created tree
     * @return         Positive number tree identifier
     */
    public long createTree(long nNodes) {
        return cCreateTree(this.cObject, nNodes);
    }

    /**
     * Create Split node and add it to certain tree
     * @param treeId        Tree to which new node is added
     * @param parentId      Parent node to which new node is added (use noParent for root node)
     * @param position      Position in parent (e.g. 0 for left and 1 for right child in a binary tree)
     * @param featureIndex  Feature index for spliting
     * @param featureValue  Feature value for spliting
     * @return              Positive number node identifier
     */
    public long addSplitNode(long treeId, long parentId, long position, long featureIndex, double featureValue) {
        return cAddSplitNode(this.cObject, treeId, parentId, position, featureIndex, featureValue);
    }

    /**
     * Create Leaf node and add it to certain tree
     * @param treeId        Tree to which new node is added
     * @param parentId      Parent node to which new node is added (use noParent for root node)
     * @param position      Position in parent (e.g. 0 for left and 1 for right child in a binary tree)
     * @param classLabel    Class label to be predicted
     * @return              Positive number node identifier
     */
    public long addLeafNode(long treeId, long parentId, long position, long classLabel) {
        return cAddLeafNode(this.cObject, treeId, parentId, position, classLabel);
    }

    /**
     * Get built model of decision forest classification
     * @return Model of decision forest classification
     */
    public Model getModel() {
        return new Model(getContext(), cGetModel(this.cObject));
    }


    private native long cInit(long nClasses, long nTrees);
    private native long cCreateTree(long algAddr, long nNodes);
    private native long cAddSplitNode(long algAddr, long treeId, long parentId, long position, long featureIndex, double featureValue);
    private native long cAddLeafNode(long algAddr, long treeId, long parentId, long position, long classLabel);
    private native long cGetModel(long algAddr);
}
/** @} */