/* file: CorDenseDistr.java */
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

/*
 //  Content:
 //     Java example of dense correlation matrix computation in the
 //     distributed processing mode
 ////////////////////////////////////////////////////////////////////////////////
 */

/**
 * <a name="DAAL-EXAMPLE-JAVA-CORRELATIONDENSEDISTRIBUTED">
 * @example CorDenseDistr.java
 */

package com.intel.daal.examples.covariance;

import com.intel.daal.algorithms.covariance.*;
import com.intel.daal.data_management.data.HomogenNumericTable;
import com.intel.daal.data_management.data.NumericTable;
import com.intel.daal.data_management.data_source.DataSource;
import com.intel.daal.data_management.data_source.FileDataSource;
import com.intel.daal.examples.utils.Service;
import com.intel.daal.services.DaalContext;


class CorDenseDistr {

    /* Input data set parameters */
    private static final String datasetFileNames[] = new String[] { "../data/distributed/covcormoments_dense_1.csv",
            "../data/distributed/covcormoments_dense_2.csv", "../data/distributed/covcormoments_dense_3.csv",
            "../data/distributed/covcormoments_dense_4.csv" };

    private static final int nBlocks         = 4;

    private static PartialResult[] partialResult = new PartialResult[nBlocks];
    private static Result          result;

    private static DaalContext context = new DaalContext();

    public static void main(String[] args) throws java.io.FileNotFoundException, java.io.IOException {

        for (int i = 0; i < nBlocks; i++) {
            computeOnLocalNode(i);
        }

        computeOnMasterNode();

        HomogenNumericTable correlation = (HomogenNumericTable) result.get(ResultId.correlation);
        HomogenNumericTable mean = (HomogenNumericTable) result.get(ResultId.mean);

        Service.printNumericTable("Correlation matrix:", correlation);
        Service.printNumericTable("Mean vector:", mean);

        context.dispose();
    }

    private static void computeOnLocalNode(int block) {
        /* Retrieve the input data from a .csv file */
        FileDataSource dataSource = new FileDataSource(context, datasetFileNames[block],
                DataSource.DictionaryCreationFlag.DoDictionaryFromContext,
                DataSource.NumericTableAllocationFlag.DoAllocateNumericTable);
        /* Retrieve the data from the input file */
        dataSource.loadDataBlock();

        /* Create algorithm objects to compute a correlation matrix in the distributed processing mode using the default method */
        DistributedStep1Local algorithm = new DistributedStep1Local(context, Float.class, Method.defaultDense);

        /* Set input objects for the algorithm */
        NumericTable input = dataSource.getNumericTable();
        algorithm.input.set(InputId.data, input);

        /* Compute partial estimates on nodes */
        partialResult[block] = algorithm.compute();
    }

    private static void computeOnMasterNode() {
        /* Create algorithm objects to compute a correlation matrix in the distributed processing mode using the default method */
        DistributedStep2Master algorithm = new DistributedStep2Master(context, Float.class, Method.defaultDense);

        /* Set input objects for the algorithm */
        for (int i = 0; i < nBlocks; i++) {
            algorithm.input.add(DistributedStep2MasterInputId.partialResults, partialResult[i]);
        }

        /* Set the parameter to choose the type of the output matrix */
        algorithm.parameter.setOutputMatrixType(OutputMatrixType.correlationMatrix);

        /* Compute a partial estimate on the master node from the partial estimates on local nodes */
        algorithm.compute();

        /* Finalize the result in the distributed processing mode */
        result = algorithm.finalizeCompute();
    }
}