from keras.layers import Dense, Conv2D, MaxPooling2D, GlobalAveragePooling2D, Input
from keras.models import Model
from keras.layers import Conv2D, MaxPooling2D
from keras.layers.merge import concatenate
import numpy as np


def add_inseption_module(input_tensor):
    act_func = "relu"
    paths = [
        [Conv2D(filters=64, kernel_size=(1, 1), padding="same", activation=act_func)],
        [
            Conv2D(filters=96, kernel_size=(1, 1), padding="same", activation=act_func),
            Conv2D(
                filters=128, kernel_size=(3, 3), padding="same", activation=act_func
            ),
        ],
        [
            Conv2D(filters=16, kernel_size=(1, 1), padding="same", activation=act_func),
            Conv2D(filters=32, kernel_size=(5, 5), padding="same", activation=act_func),
        ],
        [
            MaxPooling2D(pool_size=(3, 3), strides=1, padding="same"),
            Conv2D(filters=32, kernel_size=(1, 1), padding="same", activation=act_func),
        ],
    ]
    for_concat = []
    for path in paths:
        output_tensor = input_tensor
        for layer in path:
            output_tensor = layer(output_tensor)
        for_concat.append(output_tensor)
    return concatenate(for_concat)


kernel_size = (3, 3)
act_func = "selu"
class_cnt = y_train.shape[1]
output_tensor = input_tensor = Input(X_train.shape[1:])
layers = [
    add_inseption_module(input_tensor),
    Dense(class_cnt, activation="softmax"),
]
output_tensor = input_tensor = Input(X_train.shape[1:])
for layer in layers:
    output_tensor = layer(output_tensor)

output_tensor = input_tensor = Input(X_train.shape[1:])
insept_module_cnt = 2
for i in range(insept_module_cnt):
    output_tensor = add_inseption_module(output_tensor)
    output_tensor = GlobalAveragePooling2D()(output_tensor)
    output_tensor = Dense(class_cnt, activation="softmax")(output_tensor)


ANN = Model(inputs=input_tensor, outputs=output_tensor)
ANN.compile(loss="categorical_crossentropy", metrics="accuracy", optimizer="adam")
