from keras.layers import (
    Conv2D,
    MaxPool2D,
    GlobalAveragePooling2D,
    Dense,
    Input,
    Reshape,
    UpSampling2D,
    BatchNormalization,
    GaussianNoise,
)
from keras.models import Model
from keras.optimizers import Adam
from keras.datasets import mnist

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

data = mnist.load_data()
(X_train, Y_train), (X_test, Y_test) = mnist.load_data()
X_train = np.expand_dims(X_train, axis=-1)
X_train_scaled = (x_train / 255).copy()
X_test = np.expand_dims(X_test, axis=-1)
y_train = pd.get_dummies(pd.Categorical(y_train)).values
y_test = pd.get_dummies(pd.Categorical(y_test)).values


output_tensor = input_tensor = Input(X_train.shape[1:])


act_func = "selu"
aec_dim_num = 2
encoder_layers = [
    GaussianNoise(1),
    BatchNormalization(),
    Conv2D(32, (7, 7), padding="same", activation=act_func),
    MaxPool2D(2, 2),
    BatchNormalization(),
    Conv2D(64, (5, 5), padding="same", activation=act_func),
    MaxPool2D(2, 2),
    BatchNormalization(),
    Conv2D(128, (3, 3), padding="same", activation=act_func),
    GlobalAveragePooling2D(),
    Dense(aec_dim_num, activation="tanh"),
]
decoder_layers = [
    Dense(128, activation=act_func),
    BatchNormalization(),
    Reshape((1, 1, 128)),
    UpSampling2D((7, 7)),
    Conv2D(32, (3, 3), padding="same", activation=act_func),
    BatchNormalization(),
    UpSampling2D((2, 2)),
    Conv2D(32, (5, 5), padding="same", activation=act_func),
    BatchNormalization(),
    UpSampling2D((2, 2)),
    Conv2D(32, (7, 7), padding="same", activation=act_func),
    BatchNormalization(),
    Conv2D(1, (3, 3), padding="same", activation="sigmoid"),
]
lrng_rate = 0.0002
tensor = input_aec = input_encoder = Input(X_train.shape[1:])
for layer in encoder_layers:
    tensor = layer(tensor)
output_encoder = tensor
dec_tensor = input_decoder = Input(output_encoder.shape[1:])
for layer in decoder_layers:
    tensor = layer(tensor)
    dec_tensor = layer(dec_tensor)
output_aec = tensor
output_decoder = dec_tensor
autoencoder = Model(inputs=input_aec, outputs=output_aec)
encoder = Model(inputs=input_encoder, outputs=output_encoder)
decoder = Model(inputs=input_decoder, outputs=dec_tensor)
autoencoder.compile(optimizer=Adam(lrng_rate), loss="binary_crossentropy")
autoencoder.fit(x=X_train, y=X_train, epochs=500, batch_size=256)

fig, ax = plt.subplots(1, 1, figsize=(20, 16))
for i in range(10):
    digits = y_train == i
    needed_imgs = X_train[digits, ...]  # TUTAJ WYWAŁA SIĘ KOD
    preds = encoder.predict(needed_imgs)
    ax.scatter(preds[:, 0], preds[:, 1])
ax.legend(list(range(10)))

num = 15
limit = 0.6
step = limit * 2 / num
fig, ax = plt.subplots(num, num, figsize=(20, 16))
X_vals = np.arange(-limit, limit, step)
Y_vals = np.arange(-limit, limit, step)
for i, x in enumerate(X_vals):
    for j, y in enumerate(Y_vals):
        test_in = np.array([[x, y]])
        output = decoder.predict(x=test_in)
        output = np.squeeze(output)
        ax[-j - 1, i].imshow(output, cmap="jet")
        ax[-j - 1, i].axis("off")


act_func = "selu"
encoder_layers_2 = [
    GaussianNoise(1),
    BatchNormalization(),
    Conv2D(32, (3, 3), padding="same", activation=act_func),
    MaxPool2D(2, 2),
    Conv2D(64, (3, 3), padding="same", activation=act_func),
    MaxPool2D(2, 2),
    Conv2D(128, (3, 3), padding="same", activation=act_func),
    GlobalAveragePooling2D(),
    Dense(aec_dim_num, activation="tanh"),
]
decoder_layers_2 = [
    UpSampling2D((2, 2)),
    Conv2D(32, (3, 3), padding="same", activation=act_func),
    UpSampling2D((2, 2)),
    Conv2D(32, (3, 3), padding="same", activation=act_func),
    Conv2D(1, (3, 3), padding="same", activation="sigmoid"),
]
lrng_rate = 0.0001
tensor = input_aec = input_encoder = Input(X_train.shape[1:])
for layer in encoder_layers_2:
    tensor = layer(tensor)
autoencoder_2 = Model(inputs=input_aec, outputs=tensor)
autoencoder_2.compile(optimizer=Adam(lrng_rate), loss="binary_crossentropy")
autoencoder_2.fit(
    x=X_train, y=X_train, epochs=5, batch_size=256
)  # TUTAJ WYWAŁA SIĘ KOD

test_photos = X_test[10:20, ...].copy()
mask = np.random.randn(*test_photos.shape)
white = mask > 1
black = mask < -1
noise_test_photos = test_photos
noisy_test_photos[white] = 255
noisy_test_photos[black] = 0
noisy_test_photos /= 255

cleaned_images = autoencoder_2.predict(noisy_test_photos / 255) * 255


def show_pictures(arrs):
    arr_cnt = arrs.shape[0]
    fig, axes = plt.subplots(1, arr_cnt, figsize=(5 * arr_cnt, arr_cnt))
    for axis, pic in zip(axes, arrs):
        axis.imshow(pic.squeeze(), cmap="gray")


show_pictures(test_photos)
show_pictures(noisy_test_photos)
show_pictures(cleaned_images)

# Path: main.py
