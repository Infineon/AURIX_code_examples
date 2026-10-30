# ONNX2C Model Report

**Input file:** C:\Users\PetreaC\ACS-v1.0.22-workspace\TC4D7_DEEPCRAFT_Profiler\illd_tc4d7_acs_deepcraft_ml_profiler_PPU\models\mnist_mlp.onnx

ONNX IR version: 13
## Memory Options
- **-p greedy** true

- **--memconfig** 105 
- **--quant16c** 16777216 bytes
- **--quant8c** 16777216 bytes

- **Total Size Variables (Layouted):** 3944 bytes
- **Total Size Variables (No-Layout):** 0 bytes
- **Total Size Constants:** 437560 bytes

## Target Configuration
- **--arcppu256** true
- **--arcmw** true

## Compiler Options
- **--comp_nlquant_0** false
- **--comp_direct** false
- **--comp_pattern** 0

## Experimental Options (do not use yet)
- **--comp_runtime_node** false
- **--comp_runtime_net** false


## Active Nodes

| Node ID | Operation | T | Runtime | Consts (bytes) | Vars (bytes) | ONNX Name                                       |
|---------|-----------|---|---------|----------------|--------------|-------------------------------------------------|
| 1       | Reshape   | 0 | 0       | 3152           | 3136         | StatefulPartitionedCall/MLP_1/flatten_1/Reshape |
| 2       | MatMul    | 1 | 0       | 401408         | 3648         | StatefulPartitionedCall/MLP_1/dense_1/MatMul    |
| 3       | Add       | 1 | 0       | 512            | 1024         | StatefulPartitionedCall/MLP_1/dense_1/BiasAdd   |
| 5       | MatMul    | 1 | 0       | 32768          | 768          | StatefulPartitionedCall/MLP_1/dense_1_2/MatMul  |
| 6       | Add       | 1 | 0       | 256            | 512          | StatefulPartitionedCall/MLP_1/dense_1_2/BiasAdd |
| 8       | MatMul    | 1 | 0       | 2560           | 296          | StatefulPartitionedCall/MLP_1/dense_2_1/MatMul  |
| 9       | Add       | 1 | 0       | 40             | 80           | StatefulPartitionedCall/MLP_1/dense_2_1/BiasAdd |
| 10      | Softmax   | 1 | 0       | 0              | 80           | StatefulPartitionedCall/MLP_1/dense_2_1/Softmax |

## Removed Nodes

| Node ID | Operation | ONNX Name                                    |
|---------|-----------|----------------------------------------------|
| 4       | Relu      | StatefulPartitionedCall/MLP_1/dense_1/Relu   |
| 7       | Relu      | StatefulPartitionedCall/MLP_1/dense_1_2/Relu |

## I/O Tensors

| Tensor ID | Type  | Dimensions | Size (bytes) | Section | Attribute | Name     |
|-----------|-------|------------|--------------|---------|-----------|----------|
| 7         | float | (1,28,28)  | 3136         | 1       | .csm.data |          |
| 17        | float | (1,10)     | 40           | 1       |           |  __vccm  |

## Constant Tensors

| Tensor ID | Type    | Dimensions | Size (bytes) | Section   | Attribute | Name                                                             |
|-----------|---------|------------|--------------|-----------|-----------|------------------------------------------------------------------|
| 0         | int64_t | (2)        | 16           | .csm.data |           | StatefulPartitionedCall/MLP_1/flatten_1/Reshape_shape__19        |
| 1         | float   | (64,10)    | 2560         | .csm.data |           | StatefulPartitionedCall/MLP_1/dense_2_1/Cast/ReadVariableOp:0    |
| 2         | float   | (10)       | 40           | .csm.data |           | StatefulPartitionedCall/MLP_1/dense_2_1/BiasAdd/ReadVariableOp:0 |
| 3         | float   | (128,64)   | 32768        | .csm.data |           | StatefulPartitionedCall/MLP_1/dense_1_2/Cast/ReadVariableOp:0    |
| 4         | float   | (64)       | 256          | .csm.data |           | StatefulPartitionedCall/MLP_1/dense_1_2/BiasAdd/ReadVariableOp:0 |
| 5         | float   | (784,128)  | 401408       | .csm.data |           | StatefulPartitionedCall/MLP_1/dense_1/Cast/ReadVariableOp:0      |
| 6         | float   | (128)      | 512          | .csm.data |           | StatefulPartitionedCall/MLP_1/dense_1/BiasAdd/ReadVariableOp:0   |

## Variable Tensors

| Tensor ID | Type  | Dimensions | Size (bytes) | Section | Attribute | Name                                              |
|-----------|-------|------------|--------------|---------|-----------|---------------------------------------------------|
| 8         | float | (1,784)    | 3136         |         |  __vccm   | StatefulPartitionedCall/MLP_1/flatten_1/Reshape:0 |
| 9         | float | (1,128)    | 512          |         |  __vccm   | StatefulPartitionedCall/MLP_1/dense_1/MatMul:0    |
| 12        | float | (1,64)     | 256          |         |  __vccm   | StatefulPartitionedCall/MLP_1/dense_1_2/MatMul:0  |
| 15        | float | (1,10)     | 40           |         |  __vccm   | StatefulPartitionedCall/MLP_1/dense_2_1/MatMul:0  |


