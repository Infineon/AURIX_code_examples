# ONNX2C Model Report

**Input file:** C:\Users\PetreaC\ACS-v1.0.22-workspace\TC4D7_DEEPCRAFT_Profiler\illd_tc4d7_acs_deepcraft_ml_profiler_TC4\models\KeywordDetectionModel.onnx

ONNX IR version: 18
## Memory Options
- **-p greedy** true

- **--memconfig** 22 
- **--quant16c** 16777216 bytes
- **--quant8c** 16777216 bytes

- **Total Size Variables (Layouted):** 27200 bytes
- **Total Size Variables (No-Layout):** 0 bytes
- **Total Size Constants:** 388704 bytes

## Target Configuration
- **--mtc18** true

## Compiler Options
- **--comp_nlquant_0** false
- **--comp_direct** false
- **--comp_pattern** 0

## Experimental Options (do not use yet)
- **--comp_runtime_node** false
- **--comp_runtime_net** false


## Active Nodes

| Node ID | Operation | T | Runtime | Consts (bytes) | Vars (bytes) | ONNX Name                                                  |
|---------|-----------|---|---------|----------------|--------------|------------------------------------------------------------|
| 1       | Unsqueeze | 0 | 0       | 8008           | 8000         | conv1d-large-balanced-2_1/layer_0_1/convolution/ExpandDims |
| 2       | Transpose | 0 | 0       | 0              | 16000        | conv1d-large-balanced-2_1/layer_0_1/convolution__9         |
| 3       | Conv      | 0 | 0       | 7680           | 11200        | conv1d-large-balanced-2_1/layer_0_1/convolution            |
| 4       | Conv      | 0 | 0       | 3072           | 6400         | conv1d-large-balanced-2_1/layer_1_1/convolution            |
| 5       | Conv      | 0 | 0       | 3072           | 6400         | conv1d-large-balanced-2_1/layer_2_1/convolution            |
| 7       | Mul       | 0 | 0       | 64             | 6400         | conv1d-large-balanced-2_1/layer_3_1/batchnorm/mul_1        |
| 8       | Add       | 0 | 0       | 64             | 6400         | conv1d-large-balanced-2_1/layer_3_1/batchnorm/add_1        |
| 11      | MaxPool   | 0 | 0       | 0              | 8000         | conv1d-large-balanced-2_1/layer_5_1/MaxPool1d              |
| 12      | Conv      | 0 | 0       | 6144           | 4800         | conv1d-large-balanced-2_1/layer_6_1/convolution            |
| 13      | Conv      | 0 | 0       | 12288          | 6400         | conv1d-large-balanced-2_1/layer_7_1/convolution            |
| 15      | Mul       | 0 | 0       | 128            | 6400         | conv1d-large-balanced-2_1/layer_8_1/batchnorm/mul_1        |
| 16      | Add       | 0 | 0       | 128            | 6400         | conv1d-large-balanced-2_1/layer_8_1/batchnorm/add_1        |
| 19      | MaxPool   | 0 | 0       | 0              | 7808         | conv1d-large-balanced-2_1/layer_10_1/MaxPool1d             |
| 20      | Conv      | 0 | 0       | 12288          | 3072         | conv1d-large-balanced-2_1/layer_11_1/convolution           |
| 21      | Conv      | 0 | 0       | 12288          | 3072         | conv1d-large-balanced-2_1/layer_12_1/convolution           |
| 23      | Mul       | 0 | 0       | 128            | 3072         | conv1d-large-balanced-2_1/layer_13_1/batchnorm/mul_1       |
| 24      | Add       | 0 | 0       | 128            | 3072         | conv1d-large-balanced-2_1/layer_13_1/batchnorm/add_1       |
| 27      | MaxPool   | 0 | 0       | 0              | 3840         | conv1d-large-balanced-2_1/layer_15_1/MaxPool1d             |
| 29      | Transpose | 0 | 0       | 0              | 1536         | conv1d-large-balanced-2_1/layer_15_1/MaxPool1d__83         |
| 31      | MatMul    | 0 | 0       | 276480         | 2208         | conv1d-large-balanced-2_1/layer_17_1/MatMul                |
| 32      | Mul       | 0 | 0       | 1440           | 2880         | conv1d-large-balanced-2_1/layer_18_1/batchnorm/mul_1       |
| 33      | Add       | 0 | 0       | 1440           | 2880         | conv1d-large-balanced-2_1/layer_18_1/batchnorm/add_1       |
| 35      | MatMul    | 0 | 0       | 51840          | 1584         | conv1d-large-balanced-2_1/layer_21_1/MatMul                |
| 36      | Softmax   | 0 | 0       | 0              | 288          | conv1d-large-balanced-2_1/layer_22_1/Softmax               |

## Removed Nodes

| Node ID | Operation | ONNX Name                                                 |
|---------|-----------|-----------------------------------------------------------|
| 6       | Squeeze   | conv1d-large-balanced-2_1/layer_2_1/convolution/Squeeze   |
| 9       | Relu      | conv1d-large-balanced-2_1/layer_4_1/Relu                  |
| 10      | Unsqueeze | conv1d-large-balanced-2_1/layer_5_1/MaxPool1d/ExpandDims  |
| 14      | Squeeze   | conv1d-large-balanced-2_1/layer_7_1/convolution/Squeeze   |
| 17      | Relu      | conv1d-large-balanced-2_1/layer_9_1/Relu                  |
| 18      | Unsqueeze | conv1d-large-balanced-2_1/layer_10_1/MaxPool1d/ExpandDims |
| 22      | Squeeze   | conv1d-large-balanced-2_1/layer_12_1/convolution/Squeeze  |
| 25      | Relu      | conv1d-large-balanced-2_1/layer_14_1/Relu                 |
| 26      | Unsqueeze | conv1d-large-balanced-2_1/layer_15_1/MaxPool1d/ExpandDims |
| 28      | Squeeze   | conv1d-large-balanced-2_1/layer_15_1/MaxPool1d/Squeeze    |
| 30      | Reshape   | conv1d-large-balanced-2_1/layer_16_1/Reshape              |
| 34      | Relu      | conv1d-large-balanced-2_1/layer_19_1/Relu                 |

## I/O Tensors

| Tensor ID | Type  | Dimensions | Size (bytes) | Section | Attribute     | Name |
|-----------|-------|------------|--------------|---------|---------------|------|
| 20        | float | (1,50,40)  | 8000         | 1       | .lmudata_cpu0 |      |
| 56        | float | (1,36)     | 144          | 1       | .bss          |      |

## Constant Tensors

| Tensor ID | Type    | Dimensions  | Size (bytes) | Section       | Attribute | Name                                                            |
|-----------|---------|-------------|--------------|---------------|-----------|-----------------------------------------------------------------|
| 0         | float   | (1,32,1)    | 128          | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_8_1/batchnorm/mul:0             |
| 1         | float   | (32,32,1,3) | 12288        | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_7_1/convolution/ExpandDims_1:0  |
| 2         | float   | (32,16,1,3) | 6144         | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_6_1/convolution/ExpandDims_1:0  |
| 3         | float   | (1,16,1)    | 64           | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_3_1/batchnorm/mul:0             |
| 4         | float   | (16,16,1,3) | 3072         | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_2_1/convolution/ExpandDims_1:0  |
| 5         | float   | (360,36)    | 51840        | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_21_1/Cast/ReadVariableOp:0      |
| 6         | float   | (16,16,1,3) | 3072         | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_1_1/convolution/ExpandDims_1:0  |
| 7         | float   | (1,360)     | 1440         | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_18_1/batchnorm/sub:0            |
| 8         | float   | (1,360)     | 1440         | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_18_1/batchnorm/mul:0            |
| 9         | float   | (192,360)   | 276480       | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_17_1/Cast/ReadVariableOp:0      |
| 10        | int64_t | (2)         | 16           | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_16_1/Reshape_shape__153         |
| 11        | float   | (1,32,1)    | 128          | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_13_1/batchnorm/mul:0            |
| 12        | float   | (32,32,1,3) | 12288        | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_12_1/convolution/ExpandDims_1:0 |
| 13        | float   | (32,32,1,3) | 12288        | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_11_1/convolution/ExpandDims_1:0 |
| 14        | float   | (16,40,1,3) | 7680         | .lmudata_cpu0 |           | conv1d-large-balanced-2_1/layer_0_1/convolution/ExpandDims_1:0  |
| 15        | int64_t | (1)         | 8            | .lmudata_cpu0 |           | const_fold_opt__151__161                                        |
| 16        | int64_t | (1)         | 8            | .lmudata_cpu0 |           | const_fold_opt__151                                             |
| 17        | float   | (1,32,1)    | 128          | .lmudata_cpu0 |           | const_fold_opt__144                                             |
| 18        | float   | (1,16,1)    | 64           | .lmudata_cpu0 |           | const_fold_opt__143                                             |
| 19        | float   | (1,32,1)    | 128          | .lmudata_cpu0 |           | const_fold_opt__139                                             |

## Variable Tensors

| Tensor ID | Type  | Dimensions  | Size (bytes) | Section | Attribute | Name                                                         |
|-----------|-------|-------------|--------------|---------|-----------|--------------------------------------------------------------|
| 21        | float | (1,1,50,40) | 8000         | .bss    |           | conv1d-large-balanced-2_1/layer_0_1/convolution/ExpandDims:0 |
| 22        | float | (1,40,1,50) | 8000         | .bss    |           | conv1d-large-balanced-2_1/layer_0_1/convolution__9:0         |
| 23        | float | (1,16,1,50) | 3200         | .bss    |           | conv1d-large-balanced-2_1/layer_0_1/convolution:0            |
| 24        | float | (1,16,1,50) | 3200         | .bss    |           | conv1d-large-balanced-2_1/layer_1_1/convolution:0            |
| 25        | float | (1,16,1,50) | 3200         | .bss    |           | conv1d-large-balanced-2_1/layer_2_1/convolution:0            |
| 31        | float | (1,16,1,25) | 1600         | .bss    |           | conv1d-large-balanced-2_1/layer_5_1/MaxPool1d:0              |
| 32        | float | (1,32,1,25) | 3200         | .bss    |           | conv1d-large-balanced-2_1/layer_6_1/convolution:0            |
| 33        | float | (1,32,1,25) | 3200         | .bss    |           | conv1d-large-balanced-2_1/layer_7_1/convolution:0            |
| 39        | float | (1,32,1,12) | 1536         | .bss    |           | conv1d-large-balanced-2_1/layer_10_1/MaxPool1d:0             |
| 40        | float | (1,32,1,12) | 1536         | .bss    |           | conv1d-large-balanced-2_1/layer_11_1/convolution:0           |
| 41        | float | (1,32,1,12) | 1536         | .bss    |           | conv1d-large-balanced-2_1/layer_12_1/convolution:0           |
| 47        | float | (1,32,1,6)  | 768          | .bss    |           | conv1d-large-balanced-2_1/layer_15_1/MaxPool1d:0             |
| 49        | float | (1,6,32)    | 768          | .bss    |           | conv1d-large-balanced-2_1/layer_15_1/MaxPool1d__83:0         |
| 51        | float | (1,360)     | 1440         | .bss    |           | conv1d-large-balanced-2_1/layer_17_1/MatMul:0                |
| 55        | float | (1,36)      | 144          | .bss    |           | conv1d-large-balanced-2_1/layer_21_1/MatMul:0                |


