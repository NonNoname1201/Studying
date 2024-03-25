import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sklearn.datasets as datasets

#read from file
data = pd.read_excel("practice_lab_2.xlsx")

#generate correlation matrix
corr_matrix = data.corr()

x = data.iloc[:, :-1]
y = data.iloc[:, -1]

#generate plots
fig, axs = plt.subplots(x.shape[1], 1, figsize(10, 10))
for i, col in enumerate(x.shape[1]):
    axs[i].scatter(x[col], y)

plt.show()

######################################

# Zadanie 2.2
from sklearn.metrics import mean_absolute_error, mean_squared_error, mean_absolute_percentage_error
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

def test_linear_regression(X, y, repeats):
    mape_list = []
    for i in range(repeats):
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)
        linReg = LinearRegression()
        linReg.fit(X_train, y_train)
        y_pred = linReg.predict(X_test)
        mape = mean_absolute_percentage_error(y_test, y_pred)
        mape_list.append(mape)
    return np.mean(mape_list)


X = data.iloc[:, :-1]
y = data.iloc[:, -1:]
mape = test_linear_regression(X, y, 10)
print("Mean Absolute Percentage Error:", mape)

########################

#Zadanie 2.3
from sklearn.metrics import mean_absolute_error, mean_squared_error, mean_absolute_percentage_error
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

data = pd.read_excel("practice_lab_2.xlsx")

def remove_outliers(data, column, threshold=1.5):
    q1 = data[column].quantile(0.25)
    q3 = data[column].quantile(0.75)
    iqr = q3 - q1
    lower_bound = q1 - threshold * iqr
    upper_bound = q3 + threshold * iqr
    return data[(data[column] >= lower_bound) & (data[column] <= upper_bound)]

def test_linear_regression_mod(X, y, repeats):
    mape_list = []
    for i in range(repeats):
        data = pd.concat([X, y], axis=1)
        data = remove_outliers(data, y.columns[0])
        X = data.iloc[:, :-1]
        y = data.iloc[:, -1]
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=True)
        linReg = LinearRegression()
        linReg.fit(X_train, y_train)
        y_pred = linReg.predict(X_test)
        mape = mean_absolute_percentage_error(y_test, y_pred)
        mape_list.append(mape)
    return np.mean(mape_list)

X = data.iloc[:, :-1]
y = data.iloc[:, -1:]
mape = test_linear_regression_mod(X, y, 10)
print("Mean Absolute Percentage Error:", mape)



########################
#Zadanie 2.4
"""
"""