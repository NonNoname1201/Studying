"""1.from keras.layers import Dense, BatchNormalization
2.from keras.layers import Dropout, GaussianNoise
3.from keras.layers import LayerNormalization
4.from keras.models import Sequential
5.from keras.optimizers import Adam
6.neuron_num = 64
7.do_rate = 0.5
8.noise = 0.1
9.learning_rate = 0.001
10.block = [
11. Dense,
12. LayerNormalization(),
13. BatchNormalization,
14. Dropout,
15. GaussianNoise]
16.args = [
17. (neuron_num,'selu'),(),(),(do_rate,),(noise,)]
18.model = Sequential()
19.model.add(Dense(neuron_num, activation='relu',
 input_shape = (X.shape[1],)))
20.repeat_num = 2
21.for i in range(repeat_num):
22. for layer,arg in zip(block, args):
23. model.add(layer(*arg))
24.model.add(Dense(1, activation='sigmoid'))
25.model.compile(optimizer= Adam(learning_rate),
 loss='binary_crossentropy',
 metrics=('accuracy', 'Recall', 'Precision'))
Tu dokonaj podziału danych na zbiory treningowy oraz
testowy.
26.model.fit(X_train, y_train, batch_size=32,
 epochs=nrEpoch[0], validation_data=(X_test, y_test),
 verbose=0)
27.acc=max(model.history.history['val_accuracy'])"""


"""
Utwórz sieć o strukturze podobnej do tej, którą pokazuje Listing 6.2. Zostaw w bloku
tylko warstwę Dense. Przeprowadź kilka eksperymentów wielokrotnego testowania modelu dla
różnych wartości parametru regularyzacji typu L2, przyjmij współczynniki regularyzacji
reg_rate = [0, 0.0001, 0.001, 0.01, 0.1]. Wygeneruj wykresy punktowe uzyskanych zależności
średniej dokładności od współczynnika regularyzacji.
"""

# Path: main.py

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


args = [(neuron_num, "selu")]
block = [Dense]

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
