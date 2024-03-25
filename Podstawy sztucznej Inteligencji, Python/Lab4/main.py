import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import pc
from sklearn.decomposition import PCA
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

from sklearn.pipeline import Pipeline
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score


def qualitative_to_0_1(data, column, value_to_be_1):
    mask = data[column].values == value_to_be_1
    data.loc[mask, column] = 1
    data.loc[~mask, column] = 0
    return data


data = pd.read_csv("voice_extracted_features.csv", sep=",")
data = qualitative_to_0_1(data, "label", "male")

vals = data.values.astype(np.float32)

x = vals[:, :-1]
y = vals[:, -1]

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=1)

x_pca = PCA(2).fit_transform(x_train)

fig, ax = plt.subplots(1, 1)

males = y_train == 1

ax.scatter(x_pca[males, 0], x_pca[males, 1], label="male")
ax.scatter(x_pca[~males, 0], x_pca[~males, 1], label="female")

ax.legend()

plt.show()


# zbuduj wykres procentu wyjaśnionej wariancji, dobierz optymalną liczbę cech dla progu 95%
scaler = StandardScaler()
x_train = scaler.fit_transform(x_train)

pca = PCA().fit(x_train)
variance = pca.explained_variance_ratio_
cumulative_variance = np.cumsum(variance)

plt.scatter(np.arange(variance.shape[0]), cumulative_variance)
plt.yticks(np.arange(0, 1.1, 0.1))
pc.num = (cumulative_variance < 0.95).sum()
plt.show()

# 4. przeprowadź klasyfikację tworząc własny obiekt typu Pipeline


pipe = Pipeline(
    [
        ("transformers", PCA(4)),
        ("scaler", StandardScaler()),
        ("classifier", kNN(3, "uniform")),
    ]
)

pipe.fit(x_train, y_train)
y_pred = pipe.predict(x_test)
print(accuracy_score(y_test, y_pred))

#Zadanie 4.2. Wielokrotne przeprowadzenie eksperymentów klasyfikacji
# Przeprowadź 30 cykli uczenia-testowania dla danych z załadowanego zbioru danych.
# Przetestuj algorytmy kNN, SVM oraz Decision Tree. Dla każdego cyklu testowania wygeneruj
# macierz pomyłek. Uśrednij macierze, pomyśl, jaką płeć metody wykrywają łatwiej? Uzasadnij
# odpowiedź. Podpowiedź: spróbuj znaleźć uzasadnienie w macierzy pomyłek.

from sklearn.metrics import confusion_matrix

pipe = Pipeline(
    [
        ("transformers", PCA(4)),
        ("scaler", StandardScaler()),
        ("classifier", kNN(3, "uniform")),
    ]
)

cm = np.zeros((2, 2))
for i in range(30):
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)
    pipe.fit(x_train, y_train)
    y_pred = pipe.predict(x_test)
    cm += confusion_matrix(y_test, y_pred)

print(cm / 30)

# Zadanie 4.3. Definicja własnej klasy wyznaczającej optymalną liczbę składowych
# głównych dla PCA
# Napisz klasę, której obiekt może być dołączony do obiektu typu Pipeline. Niech ta klasa
# pozwala na dobór liczby cech na podstawie procentu wyjaśnionej wariancji. Podpowiedź: aby
# obiekt klasy można było dołączyć do Pipeline’u, musi on mieć takie metody, jak: ‘fit(x)’,
# ‘transform(x)’, ‘fit_transform(x)’.

from sklearn.base import BaseEstimator, TransformerMixin


class PC(BaseEstimator, TransformerMixin):
    def __init__(self, threshold):
        self.threshold = threshold
        self.num = None

    def fit(self, x, y=None):
        pca = PCA().fit(x)
        variance = pca.explained_variance_ratio_
        cumulative_variance = np.cumsum(variance)
        self.num = (cumulative_variance < self.threshold).sum()
        return self

    def transform(self, x):
        return PCA(self.num).fit_transform(x)

pipe = Pipeline(
    [
        ("transformers", PC(0.95)),
        ("scaler", StandardScaler()),
        ("classifier", kNN(3, "uniform")),
    ]
)

pipe.fit(x_train, y_train)
y_pred = pipe.predict(x_test)
print(accuracy_score(y_test, y_pred))

# Zadanie 4.4. Definicja własnej klasy odpowiedzialnej za usuwanie wartości odstających
# Napisz klasę, której obiekt może być dołączony do obiektu typu Pipeline. Ta klasa ma
# zapewniać znalezienie wartości odstających oraz ich eliminację poprzez zastąpienie średnią.

from sklearn.base import BaseEstimator, TransformerMixin


class OutlierRemover(BaseEstimator, TransformerMixin):
    def __init__(self, threshold):
        self.threshold = threshold
        self.mean = None

    def fit(self, x, y=None):
        self.mean = x.mean(axis=0)
        return self

    def transform(self, x):
        mask = np.abs(x - self.mean) > self.threshold
        x[mask] = self.mean
        return x

pipe = Pipeline(
    [
        ("transformers", OutlierRemover(3)),
        ("scaler", StandardScaler()),
        ("classifier", kNN(3, "uniform")),
    ]
)

pipe.fit(x_train, y_train)
y_pred = pipe.predict(x_test)
print(accuracy_score(y_test, y_pred))
