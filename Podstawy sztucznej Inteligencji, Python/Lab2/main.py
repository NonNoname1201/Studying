# # Podobnie do zadań z poprzednich zajęć (Zadanie 1.4) wygeneruj macierz korelacji dla wczytanego zbioru. Przeanalizuj macierz korelacji. Jakie zależności mogą mieć związek, a jakie są przypadkowe? Wygeneruj wykresy korelacji pomiędzy cechami niezależnymi a cecha zależną (medianową ceną mieszkania).

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn import datasets
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
import statsmodels.api as sm
import numpy as np
from sklearn.metrics import r2_score

# # Wczytanie danych
# boston = datasets.load_boston()
# boston_df = pd.DataFrame(boston.data, columns=boston.feature_names)
# boston_df["MEDV"] = boston.target
# print(boston_df.head())

# # Wygenerowanie macierzy korelacji
# corr_matrix = boston_df.corr().round(2)
# print(corr_matrix)

# # Wygenerowanie wykresów korelacji
# sns.heatmap(data=corr_matrix, annot=True)
# plt.show()

# # Wygenerowanie wykresów korelacji pomiędzy cechami niezależnymi a cecha zależną (medianową ceną mieszkania)
# sns.pairplot(
#     boston_df,
#     x_vars=["CRIM", "ZN", "INDUS", "CHAS", "NOX"],
#     y_vars="MEDV",
#     height=7,
#     aspect=0.7,
#     kind="reg",
# )
# sns.pairplot(
#     boston_df,
#     x_vars=["RM", "AGE", "DIS", "RAD", "TAX"],
#     y_vars="MEDV",
#     height=7,
#     aspect=0.7,
#     kind="reg",
# )
# sns.pairplot(
#     boston_df,
#     x_vars=["PTRATIO", "B", "LSTAT"],
#     y_vars="MEDV",
#     height=7,
#     aspect=0.7,
#     kind="reg",
# )
# plt.show()

# # Podział danych na zbiór uczący i testowy
# X = boston_df.drop("MEDV", axis=1)
# y = boston_df["MEDV"]
# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)

# # Utworzenie modelu regresji liniowej
# model = LinearRegression()
# model.fit(X_train, y_train)

# # Wyświetlenie współczynników modelu
# print("Intercept: ", model.intercept_)
# print("Coefficients: ", model.coef_)
# print("Features: ", X.columns)

# # Predykcja wartości dla zbioru testowego
# y_pred = model.predict(X_test)

# # Wyświetlenie wartości predykcyjnych i rzeczywistych
# df = pd.DataFrame({"Actual": y_test, "Predicted": y_pred})
# print(df)

# # Wyświetlenie wartości błędu średniokwadratowego
# print("Mean Squared Error: ", mean_squared_error(y_test, y_pred))

# # Wyświetlenie wartości współczynnika determinacji
# print("R2 score: ", r2_score(y_test, y_pred))

# # Wyświetlenie wartości współczynnika determinacji
# X = sm.add_constant(X)
# model = sm.OLS(y, X).fit()
# print(model.summary())


"""
Listing 2.4 
1.from sklearn.metrics import mean_absolute_error,
 mean_squared_error,
 mean_absolute_percentage_error
2.X_train, X_test, y_train, y_test =
 train_test_split(X,y,test_size=0.2,
random_state=221, shuffle=True)
3.linReg = LinearRegression()
4.linReg.fit(X_train, y_train)
5.y_pred = linReg.predict(X_test)
6.mse = mean_squared_error(y_test, y_pred)
7.mae = mean_absolute_error(y_test, y_pred)
8.mape = mean_absolute_percentage_error (y_test, y_pred)


Zmodyfikuj skrypt, który pokazuje Listing 2.4, tak, żeby powstał skrypt pozwalający na
wielokrotne przetestowanie modelu regresji liniowej. Skrypt umieść w oddzielnej funkcji, która
jako argument przyjmie liczbę powtórzeń, które trzeba wykonać. Podpowiedź: w funkcji
zastosuj pętlę for. Za każdym razem zbiór danych ma zostać podzielony na podzbiory: uczący
oraz testowy w sposób losowy, w tym celu nie podawaj argumentu random_state, aby wyniki
za każdym razem się różniły. Jako wynik eksperymentu ma być zwrócona średnia wartość
miary mean_absolute_percentage_error – czyli średni procent błędu regresji.
"""

# Zadanie 2.2
# from sklearn.metrics import mean_absolute_error, mean_squared_error, mean_absolute_percentage_error
# from sklearn.model_selection import train_test_split
# from sklearn.linear_model import LinearRegression

# def test_linear_regression(X, y, repeats):
#     mape_list = []
#     for i in range(repeats):
#         X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)
#         linReg = LinearRegression()
#         linReg.fit(X_train, y_train)
#         y_pred = linReg.predict(X_test)
#         mape = mean_absolute_percentage_error(y_test, y_pred)
#         mape_list.append(mape)
#     return np.mean(mape_list)

"""
Wykonaj Zadanie 2.2 dodając do niego procedurę usuwania/zastępowania wartości
odstających. Porównaj wyniki uzyskane w poprzednim zadaniu z nowymi wynikami.
"""

# Zadanie 2.3
from sklearn.metrics import (
    mean_absolute_error,
    mean_squared_error,
    mean_absolute_percentage_error,
)
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler
import numpy as np


def test_linear_regression(X, y, repeats):
    mape_list = []
    for i in range(repeats):
        X_train, X_test, y_train, y_test = train_test_split(
            X, y, test_size=0.2, shuffle=True
        )
        scaler = StandardScaler()
        X_train = scaler.fit_transform(X_train)
        X_test = scaler.transform(X_test)
        linReg = LinearRegression()
        linReg.fit(X_train, y_train)
        y_pred = linReg.predict(X_test)
        mape = mean_absolute_percentage_error(y_test, y_pred)
        mape_list.append(mape)
    return np.mean(mape_list)

"""
Zadanie 2.4. Generacja nowych cech
Spróbuj zaproponować cechy/kombinacje cech, które mogły by ulepszyć jakość
predykcji regresji liniowej. Przetestuj zaproponowane rozwiązania
"""

# Zadanie 2.4. Generacja nowych cech








# from sklearn.metrics import mean_absolute_error, mean_squared_error, mean_absolute_percentage_error
# from sklearn.model_selection import train_test_split
# from sklearn.linear_model import LinearRegression
# from sklearn.preprocessing import StandardScaler
# import numpy as np

# def test_linear_regression(X, y, repeats):
#     mape_list = []
#     for i in range(repeats):
#         X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)
#         scaler = StandardScaler()
#         X_train = scaler.fit_transform(X_train)
#         X_test = scaler.transform(X_test)
#         linReg = LinearRegression()
#         linReg.fit(X_train, y_train)
#         y_pred = linReg.predict(X_test)
#         mape = mean_absolute_percentage_error(y_test, y_pred)
#         mape_list.append(mape)
#     return np.mean(mape_list)


# Zadanie 2.5. Regularyzacja
# from sklearn.linear_model import Ridge, Lasso, ElasticNet
# from sklearn.metrics import mean_absolute_error, mean_squared_error, mean_absolute_percentage_error
# from sklearn.model_selection import train_test_split
# from sklearn.linear_model import LinearRegression
# from sklearn.preprocessing import StandardScaler
# import numpy as np

# def test_linear_regression(X, y, repeats):
#     mape_list = []
#     for i in range(repeats):
#         X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)
#         scaler = StandardScaler()
#         X_train = scaler.fit_transform(X_train)
#         X_test = scaler.transform(X_test)
#         linReg = LinearRegression()
#         linReg.fit(X_train, y_train)
#         y_pred = linReg.predict(X_test)
#         mape = mean_absolute_percentage_error(y_test, y_pred)
#         mape_list.append(mape)
#     return np.mean(mape_list)

# def test_ridge_regression(X, y, repeats):
#     mape_list = []
#     for i in range(repeats):
#         X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)
#         scaler = StandardScaler()
#         X_train = scaler.fit_transform(X_train)
#         X_test = scaler.transform(X_test)
#         ridge = Ridge(alpha=0.1)
#         ridge.fit(X_train, y_train)
#         y_pred = ridge.predict(X_test)
#         mape = mean_absolute_percentage_error(y_test, y_pred)
#         mape_list.append(mape)
#     return np.mean(mape_list)

# def test_lasso_regression(X, y, repeats):
#     mape_list = []
#     for i in range(repeats):
#         X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)
#         scaler = StandardScaler()
#         X_train = scaler.fit_transform(X_train)
#         X_test = scaler.transform(X_test)
#         lasso = Lasso(alpha=0.1)
#         lasso.fit(X_train, y_train)
#         y_pred = lasso.predict(X_test)
#         mape = mean_absolute_percentage_error(y_test, y_pred)
#         mape_list.append(mape)
#     return np.mean(mape_list)

# def test_elasticnet_regression(X, y, repeats):
#     mape_list = []
#     for i in range(repeats):
#         X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)
#         scaler = StandardScaler()
#         X_train = scaler.fit_transform(X_train)
#         X_test = scaler.transform(X_test)
#         elasticnet = ElasticNet(alpha=0.1)
#         elasticnet.fit(X_train, y_train)
#         y_pred = elasticnet.predict(X_test)
#         mape = mean_absolute_percentage_error(y_test, y_pred)
#         mape_list.append(mape)
#     return np.mean(mape_list)
