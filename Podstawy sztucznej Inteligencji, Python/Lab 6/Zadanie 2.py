from keras.layers import Dense, BatchNormalization
from keras.layers import Dropout, GaussianNoise
from keras.layers import LayerNormalization
from keras.models import Sequential
from keras.optimizers import Adam
from keras import regularizers
from keras.regularizers import l2
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import pandas as pd

from sklearn.datasets import load_iris

data = load_iris()
y = data.target
X = data.data
y_one_hot = pd.get_dummies(y).values

neuron_num = 64
reg_rate = [0, 0.0001, 0.001, 0.01, 0.1]
repeat_num = 2
learning_rate = 0.001
do_rate = [0, 0.2, 0.3, 0.5]
noise = 0.1

block = [Dense, Dropout]

for do_r in do_rate:
    args = [(neuron_num, "selu"), (), (), (do_r,), (noise,)]
    for i in reg_rate:
        model = Sequential()
        X_train, X_test, y_train, y_test = train_test_split(X, y_one_hot, test_size=0.2)
        for _ in range(repeat_num):
            for layer, arg in zip(block, args):
                model.add(Dense(y_train.shape[1], activation="softmax"))
        model.compile(
            optimizer=Adam(learning_rate),
            loss="categorical_crossentropy",
            metrics=("accuracy"),
        )

        history = model.fit(
            X_train,
            y_train,
            batch_size=32,
            epochs=10,
            validation_data=(X_test, y_test),
            verbose=2,
        )

        plt.plot(history.history["accuracy"], label="accuracy")
        plt.plot(history.history["val_accuracy"], label="val_accuracy")
        plt.xlabel("Epoch")
        plt.ylabel("Accuracy")
        plt.legend(loc="lower right")
        plt.show()
