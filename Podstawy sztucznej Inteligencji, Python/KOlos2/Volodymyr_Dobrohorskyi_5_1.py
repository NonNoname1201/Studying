import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Activation, Dropout, Flatten
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.datasets import fashion_mnist
import matplotlib.pyplot as plt

# Zadanie 1
# 1
info = pd.read_excel("housing_data.xlsx")
X = info.iloc[:, :-1]
y = info.iloc[:, -1]

# 2
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)

# 3
regression = LinearRegression()
regression.fit(X_train, y_train)
y_prediction = regression.predict(X_test)

print("współczynniki regresji: ", regression.coef_)
print("błąd średniokwadratowy: ", mean_squared_error(y_test, y_prediction))

plt.scatter(X_test["Przestepczosc"], y_test, color="blue")
plt.show()


# Zadanie 2
# 1
data = pd.read_csv("voice_extracted_features.csv")

# 2
mask = data["label"] == "female"
data["label"][mask] = 0
data["label"][~mask] = 1

X = data.iloc[:, :-1]
y = data.iloc[:, -1]

# 4
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)

# 5
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.fit_transform(X_test)


# Zadanie 3
tp = 95
tn = 3
fp = 0
fn = 1
recall = tp / (tp + fn)
print("precision: ", tp / (tp + fp))
print("recall: ", recall)
print("f1: ", 2 * (recall * (tp / (tp + fp))) / (recall + (tp / (tp + fp))))


# Zadanie 4
# 1
data = pd.read_csv("voice_extracted_features.csv")

mask = data["label"] == "female"
data["label"][mask] = 1
data["label"][~mask] = 0
X = data.iloc[:, :-1]
y = data.iloc[:, -1]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)

# 2
pca = PCA(2)

# 3
X_train = pca.fit_transform(X_train)
X_test = pca.transform(X_test)

# 4
print("Kształt zredukowanego zestawu danych:", X_train.shape)
print("Wyjaśniony stosunek wariancji:", pca.explained_variance_ratio_)


# Zadanie 5
# 1
(X_train, y_train), (X_test, y_test) = fashion_mnist.load_data()

# 2
dropout = 0.2
num_classes = 10
gau_noise = 0.1

model = Sequential()
model.add(Flatten(input_shape=(28, 28)))
model.add(Dense(512))
model.add(Dense(256))
model.add(Dense(128))
model.add(Dense(64))
model.add(Dense(num_classes))
model.add(Activation("softmax"))

# 3
model.compile(
    optimizer=Adam(), loss="sparse_categorical_crossentropy", metrics=["accuracy"]
)

history = model.fit(X_train, y_train, epochs=10, validation_data=(X_test, y_test))

# 4
# Wykres dla straty
plt.figure(figsize=(12, 6))
plt.plot(history.history["loss"], label="Training Loss")
plt.plot(history.history["val_loss"], label="Validation Loss")
plt.title("Model Loss")
plt.ylabel("Loss")
plt.xlabel("Epochs")
plt.legend(loc="upper right")
plt.show()

# Wykres dla dokładności
plt.figure(figsize=(12, 6))
plt.plot(history.history["accuracy"], label="Training Accuracy")
plt.plot(history.history["val_accuracy"], label="Validation Accuracy")
plt.title("Model Accuracy")
plt.ylabel("Accuracy")
plt.xlabel("Epochs")
plt.legend(loc="lower right")
plt.show()
