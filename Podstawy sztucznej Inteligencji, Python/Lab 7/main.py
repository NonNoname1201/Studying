# #Listing 7.1
# from keras.layers import Conv2D, Flatten, Dense
# from keras.models import Sequential
# from keras.optimizers import Adam
# from keras.datasets import mnist

# import numpy as np

# train, test = mnist.load_data()
# X_train, y_train = train[0], train[1]
# X_test, y_test = test[0], test[1]
# X_train = np.expand_dims(X_train, axis=-1)
# X_test = np.expand_dims(X_test, axis=-1)
# class_cnt = np.unique(y_train).shape[0]
# filter_cnt = 32
# neuron_cnt = 32
# learning_rate = 0.0001
# act_func = "relu"
# kernel_size = (3, 3)
# model = Sequential()
# conv_rule = 'same'
# model.add(Conv2D(input_shape = X_train.shape[1:],
#  filters=filter_cnt,
#  kernel_size = kernel_size,
#  padding = conv_rule, activation = act_func))
# model.add(Flatten())
# model.add(Dense(class_cnt, activation='softmax'))
# model.compile(optimizer=Adam(learning_rate),
#  loss='SparseCategoricalCrossentropy',
#  metrics='accuracy')
# model.fit(x = X_train, y = y_train,
#  epochs = class_cnt ,
#  validation_data=(X_test, y_test))

"""Zadanie 7.2. Znalezienie optymalnej liczby warstw
Stosując Listing 7.1 napisz skrypt, który pozwoli na znalezienie optymalnej liczby
warstw. Jako optymalną rozumiemy liczbę, przy której jakość działania modelu będzie
najlepsza, a liczba warstw nie będzie za duża."""

# Zadanie 7.2
from keras.layers import Conv2D, Flatten, Dense
from keras.models import Sequential
from keras.optimizers import Adam
from keras.datasets import mnist

from tensorflow.keras.layers import Dense
from tensorflow.keras.layers import MaxPooling2D

import numpy as np

train, test = mnist.load_data()
X_train, y_train = train[0], train[1]
X_test, y_test = test[0], test[1]

X_train = np.expand_dims(X_train, axis=-1)
X_test = np.expand_dims(X_test, axis=-1)

class_cnt = np.unique(y_train).shape[0]
filter_cnt = 32
neuron_cnt = 32
learning_rate = 0.0001
act_func = "relu"
kernel_size = (3, 3)

from tensorflow.keras.layers import Dense

# Initialize a list to store the accuracies
accuracies = []

# Loop over the range 1-10
# for i in range(1, 11):
#     # Create a new model
#     model = Sequential()
#     conv_rule = "same"
#     model.add(
#         Conv2D(
#             input_shape=X_train.shape[1:],
#             filters=filter_cnt,
#             kernel_size=kernel_size,
#             padding=conv_rule,
#             activation=act_func,
#         )
#     )
#     model.add(Flatten())

#     # Add i Dense layers
#     for _ in range(i):
#         model.add(Dense(class_cnt, activation="relu"))

#     model.add(Dense(class_cnt, activation="softmax"))
#     model.compile(
#         optimizer=Adam(learning_rate),
#         loss="SparseCategoricalCrossentropy",
#         metrics="accuracy",
#     )

#     # Train the model
#     history = model.fit(
#         x=X_train, y=y_train, epochs=class_cnt, validation_data=(X_test, y_test)
#     )

#     # Store the accuracy of the model on the validation set
#     accuracies.append(history.history["val_accuracy"][-1])

# # Find the model with the highest accuracy
# best_model_index = accuracies.index(max(accuracies)) + 1
# print(f"The best model is the one with {best_model_index} hidden layers.")
"""
Zadanie 7.3. Wpływ warstw głosujących
Zbadaj wpływ warstw głosujących. Po każdej warstwie konwolucyjnej dodaj warstwę
głosującą. Porównaj krzywe uczenia uzyskane z zastosowaniem warstw głosujących oraz
bez nich. Przetestuj dwa rodzaje warstw: MaxPooling oraz AveragePooling.
"""

# Zadanie 7.3
model = Sequential()
conv_rule = "same"
model.add(
    Conv2D(
        input_shape=X_train.shape[1:],
        filters=filter_cnt,
        kernel_size=kernel_size,
        padding=conv_rule,
        activation=act_func,
    )
)
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Flatten())
model.add(Dense(class_cnt, activation="softmax"))
model.compile(
    optimizer=Adam(learning_rate),
    loss="SparseCategoricalCrossentropy",
    metrics="accuracy",
)

# Train the model
history = model.fit(
    x=X_train, y=y_train, epochs=class_cnt, validation_data=(X_test, y_test)
)
