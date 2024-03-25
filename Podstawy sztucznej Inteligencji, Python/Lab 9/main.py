"""Jedną z ciekawych architektur jest również sieć ResNet. Podobnie do Inception składa
się ona ze standardowych bloków. Jej główną cecha jest wykorzystanie połączeń skrótowych
w sposób następujący:
wejście → conv 3x3 → batch norm → + wyjście -> reLu -> wyjście
Rys. 8.7. Pojedynczy blok architektury ResNet.
Napisz skrypt pozwalający na utworzenie sieci zawierającej podaną liczbę bloków
ResNet, przetestuj sieć na zbiorze danych MNIST."""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import tensorflow as tf
from tensorflow.keras.layers import (
    Input,
    Conv2D,
    BatchNormalization,
    Activation,
    Add,
    Concatenate,
)

from keras.datasets import mnist

data = mnist.load_data()
X_train, y_train = data[0][0], data[0][1]
X_test, y_test = data[1][0], data[1][1]
X_train = np.expand_dims(X_train, axis=-1)
X_test = np.expand_dims(X_test, axis=-1)
y_train = pd.get_dummies(pd.Categorical(y_train)).values
y_test = pd.get_dummies(pd.Categorical(y_test)).values

output_tensor = input_tensor = Input(X_train.shape[1:])


def ResNet(output_tensor):
    skip_tensor = output_tensor
    output_tensor = Conv2D(32, (3, 3), padding="same", activation="relu")(output_tensor)
    output_tensor = BatchNormalization()(output_tensor)
    output_tensor = Add()([output_tensor, skip_tensor])
    output_tensor = Activation("relu")(output_tensor)
    return output_tensor


def DesNet(output_tensor):
    skip_tensor = output_tensor
    output_tensor = Conv2D(32, (3, 3), padding="same", activation="relu")(output_tensor)
    output_tensor = BatchNormalization()(output_tensor)
    output_tensor = Concatenate()([output_tensor, skip_tensor])
    output_tensor = Conv2D(32, (1, 1), padding="same", activation="relu")(output_tensor)
    return output_tensor


for _ in range(5):
    output_tensor = DesNet(output_tensor)

model = tf.keras.models.Model(input_tensor, ResNet(output_tensor))
model.compile(loss="categorical_crossentropy", optimizer="adam", metrics=["accuracy"])

# plot model
tf.keras.utils.plot_model(model, show_shapes=True, show_layer_names=True)
