from keras.layers import (
    Dense,
    Conv2D,
    MaxPooling2D,
    GlobalAveragePooling2D,
    Input,
    Flatten,
    Reshape,
    BatchNormalization,
    Average,
)
from keras.models import Model
from keras.layers import Conv2D, MaxPooling2D
from keras.layers import concatenate
from keras.regularizers import l2
import tensorflow as tf
import numpy as np
import pandas as pd

from keras.datasets import mnist

data = mnist.load_data()
X_train, y_train = data[0][0], data[0][1]
X_test, y_test = data[1][0], data[1][1]
X_train = np.expand_dims(X_train, axis=-1)
X_test = np.expand_dims(X_test, axis=-1)
y_train = pd.get_dummies(pd.Categorical(y_train)).values
y_test = pd.get_dummies(pd.Categorical(y_test)).values


def add_inseption_module(input_tensor):
    act_func = "relu"
    paths = [
        # [
        #     Conv2D(
        #         filters=128, kernel_size=(3, 3), padding="same", activation=act_func
        #     ),
        #     MaxPooling2D(pool_size=(2, 2), strides=1, padding="same"),
        #     Conv2D(filters=64, kernel_size=(3, 3), padding="same", activation=act_func),
        # ],
        # [
        #     Conv2D(
        #         filters=256, kernel_size=(3, 3), padding="same", activation=act_func
        #     ),
        #     MaxPooling2D(pool_size=(2, 2), strides=1, padding="same"),
        # ],
        [
            Dense(512, activation=act_func),
            Dense(256, activation=act_func),
            Dense(128, activation=act_func),
            Dense(64, activation=act_func),
            Dense(16, activation=act_func),
            Dense(10, activation=act_func),
        ],
        [
            Dense(512, activation=act_func),
            Dense(64, activation=act_func),
            Dense(10, activation=act_func),
        ],
        [
            Dense(512, activation=act_func),
            Dense(64, activation=act_func),
            Dense(10, activation=act_func),
        ],
        [
            Dense(512, activation=act_func),
            Dense(64, activation=act_func),
            Dense(10, activation=act_func),
        ],
        [
            Dense(512, activation=act_func),
            Dense(64, activation=act_func),
            Dense(10, activation=act_func),
        ],
    ]
    for_concat = []
    for path in paths:
        output_tensor = input_tensor
        for layer in path:
            output_tensor = layer(output_tensor)
        for_concat.append(output_tensor)
    return concatenate(for_concat)


output_tensor = input_tensor = Input(X_train.shape[1:])

output_tensor = Flatten()(output_tensor)
output_tensor = BatchNormalization()(output_tensor)
output_tensor = add_inseption_module(output_tensor)

output_tensor = tf.reduce_mean(output_tensor, axis=1)

model = Model(inputs=input_tensor, outputs=output_tensor)
model.compile(loss="categorical_crossentropy", metrics="accuracy", optimizer="adam")

from keras.utils import plot_model

plot_model(model, show_shapes=True)
