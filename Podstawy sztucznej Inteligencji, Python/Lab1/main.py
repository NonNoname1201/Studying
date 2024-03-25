import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math


file_name = "practice_lab_1.xlsx"

data_from_xlsx = pd.read_excel(file_name)

data_numpy = np.array(data_from_xlsx)

data_columns = data_from_xlsx.columns.tolist()

wartosci_kolumn = data_from_xlsx.values


# %%
# 1.2.3

arr1 = wartosci_kolumn[::2, :] - wartosci_kolumn[1::2, :]

# %%
# 1.2.2

arr2 = (wartosci_kolumn - wartosci_kolumn.mean()) / wartosci_kolumn.std()

# %%
# 1.2.3

arr3 = (wartosci_kolumn - wartosci_kolumn.mean(axis=0)) / (
    wartosci_kolumn.std(axis=0) + np.spacing(wartosci_kolumn.std(axis=0))
)

# %%
# 1.2.4

arr4 = wartosci_kolumn.mean(axis=0) / (
    wartosci_kolumn.std(axis=0) + np.spacing(wartosci_kolumn.std(axis=0))
)

# %%
# 1.2.5

arr5 = np.argmax(arr4)

# %%
# 1.2.6

arr5 = (wartosci_kolumn > wartosci_kolumn.mean(axis=0)).sum(axis=0)

# %%
# 1.2.7

max_value = wartosci_kolumn.max()
col_max = wartosci_kolumn.max(axis=0)
data_columns = np.array(data_columns)
mask = data_columns[col_max == max_value]
print(mask)
mask_boolean = col_max == max_value

# %%
# 1.2.8
# I sposób:
id_col = ((wartosci_kolumn == 0).sum(axis=0)).argmax()
print(data_columns[id_col])

# II sposób:
maska = data_numpy == 0
ilosczer = np.count_nonzero(maska == 1, axis=0)
w8 = data_columns[np.where(ilosczer)]
# %%
# 1.2.9

parzyste = wartosci_kolumn[::2, :]
nieparzyste = wartosci_kolumn[1::2, :]
nazwy_kolumn = parzyste.sum(axis=0) > nieparzyste.sum(axis=0)
nazwy_kolumn = data_columns[parzyste.sum(axis=0) > nieparzyste.sum(axis=0)]
print(nazwy_kolumn)


# %%
# Zadanie 1.3:
x = np.arange(-5, 5, 0.01)
# wykres 1:
y = np.tanh(x)
plt.plot(x, y)
plt.xlabel("x")
plt.ylabel("y")
plt.show()

# wykres 2:
y = (np.exp(x) - np.exp(-x)) / ((np.exp(x) + np.exp(-x)))
plt.plot(x, y)
plt.xlabel("x")
plt.ylabel("y")
plt.show()

# Wykres 3:
y = 1 / (1 + np.exp(-x))
plt.plot(x, y)
plt.xlabel("x")
plt.ylabel("y")
plt.show()

# Wykres 4:

plt.plot(x[x > 0], x[x > 0], "b")
plt.plot(x[x <= 0], np.zeros(len(x[x <= 0])), "b")
plt.show()

# wykres 5

plt.plot(x[x > 0], x[x > 0], "b")
plt.plot(x[x <= 0], np.exp(x[x <= 0]) - 1, "b")
plt.show()

# %%
# Zadanie 1.4:
data = pd.read_excel("practice_lab_1.xlsx")
nazwy_kolumn = list(data.columns)
korelacje = data.corr()
fig, ax = plt.subplots(len(nazwy_kolumn), len(nazwy_kolumn), figsize=(10, 10))
for i in range(len(nazwy_kolumn)):
    for j in range(len(nazwy_kolumn)):
        ax[i, j].scatter(data.iloc[:, i], data.iloc[:, j])


"""
df = pd.read_excel(file_name)


data_array = df.values
column_names = df.columns.tolist()


even_rows = data_array[::2]  # Get all even rows
odd_rows = data_array[1::2]  # Get all odd rows
result1 = even_rows - odd_rows


mean_values = np.mean(data_array, axis=0)
std_deviations = np.std(data_array, axis=0)
result2 = (data_array - mean_values) / std_deviations


std_deviations += np.spacing(std_deviations)
result3 = (data_array - mean_values) / std_deviations


coefficient_of_variation = mean_values / (std_deviations + np.spacing(std_deviations))


max_cv_column_index = np.argmax(coefficient_of_variation)
column_with_max_cv = df.columns[max_cv_column_index]
print("Column with the highest coefficient of variation:", column_with_max_cv)


elements_greater_than_mean = np.sum(data_array > mean_values, axis=0)


max_values = np.max(data_array, axis=0)
max_value_mask = data_array == max_values
column_names_with_max = df.columns[np.any(max_value_mask, axis=0)]
column_names_list = column_names_with_max.tolist()


zero_values_df = df == 0
count_of_zeros = zero_values_df.sum()
column_names_with_most_zeros = count_of_zeros[count_of_zeros == count_of_zeros.max()].index.tolist()


def even_sum_greater_than_odd(column):
    even_sum = sum(column[i] for i in range(len(column)) if i % 2 == 0)
    odd_sum = sum(column[i] for i in range(len(column)) if i % 2 != 0)
    return even_sum > odd_sum
column_names_greater_even = df.columns[df.apply(even_sum_greater_than_odd)]


def funkcja1(x):
    return np.tanh(x)

def funkcja2(x):
    a = math.e**x
    b = math.e**-x
    return (a-b)/(a+b)

def funkcja3(x):
    a = math.e**-x
    return 1/(1+a)

def funkcja4(x):
    return np.where(x < 0, x, 0)

def funkcja5(x):
    a = math.e**x
    return np.where(x < 0, x, a-1)


x = np.arange(-5, 5, 0.01)

y1 = funkcja1(x)
y2 = funkcja2(x)
y3 = funkcja3(x)
y4 = funkcja4(x)
y5 = funkcja5(x)

plt.plot(x, y1)
plt.plot(x, y2)
plt.plot(x, y3)
plt.plot(x, y4)
plt.plot(x, y5)

plt.xlabel('Wartości x')
plt.ylabel('Wartości funkcji')
plt.title('Wykresy be like:')

plt.show()
"""
