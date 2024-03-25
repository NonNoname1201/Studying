"""
1.
Podziel dane na zbiór treningowy i testowy, odpowiednio 80% i 20%.
i dokonaj jeszcze raz pomieszania danych.

2.
zakoduj klasy

3.
wykonaj preprocessing danych

4.
stworz klasyfikatory KNN, SVM, DT, Przedstaw wyniki z wykorzystaniem
macierzy pomyłek. Wykonaj tuning modeli. wykonaj rysunek uzyskanego drzewa decyzyjnego

5.
wykonaj analizę glownych składowych i okresl jaka liczba cech pozwala na wyjasnienie wariancji oraz przedstaw na odpowiednim wykresie

6.
Zbuduj siec neuronowa (NN) na potrzeby klasyfikacji. Przedstaw wyniki z wykorzystaniem macierzy pomyłek.

7.
Porównaj wyniki klasyfikacji dla modeli KNN/SVM/DT/NN. Zaproponuj najlepszy klasyfikator. uzasadnij wybór.
"""
import pandas as pd
from sklearn.datasets import fetch_california_housing

california_housing = fetch_california_housing()
X = pd.DataFrame(california_housing.data, columns=california_housing.feature_names)
Y = california_housing.target

Y = pd.cut(Y, 3, labels=["class_0", "class_1", "class_2"])

data_combined = X.assign(target=Y)

data = data_combined.sample(frac=1).reset_index(drop=True)
data = data.iloc[:1000]


# 1.
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(
    data.iloc[:, :-1], data.iloc[:, -1], test_size=0.2, random_state=42
)

# 2.
from sklearn.preprocessing import LabelEncoder

le = LabelEncoder()
y_train = le.fit_transform(y_train)
y_test = le.transform(y_test)

# 3.
from sklearn.preprocessing import StandardScaler

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# 4.
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import confusion_matrix, accuracy_score
import matplotlib.pyplot as plt

knn = KNeighborsClassifier()
svm = SVC()
dt = DecisionTreeClassifier()

knn.fit(X_train, y_train)
svm.fit(X_train, y_train)
dt.fit(X_train, y_train)

y_pred_knn = knn.predict(X_test)
y_pred_svm = svm.predict(X_test)
y_pred_dt = dt.predict(X_test)

print("KNN")
print(confusion_matrix(y_test, y_pred_knn))
print(accuracy_score(y_test, y_pred_knn))
print("SVM")
print(confusion_matrix(y_test, y_pred_svm))
print(accuracy_score(y_test, y_pred_svm))
print("DT")
print(confusion_matrix(y_test, y_pred_dt))
print(accuracy_score(y_test, y_pred_dt))

# tuning
from sklearn.model_selection import GridSearchCV

knn_params = {"n_neighbors": [3, 5, 7, 9, 11, 13, 15]}
svm_params = {"C": [0.1, 1, 10, 100, 1000], "kernel": ["linear", "rbf"]}
dt_params = {"max_depth": [3, 5, 7, 9, 11, 13, 15]}
knn_grid = GridSearchCV(knn, knn_params, cv=5)
svm_grid = GridSearchCV(svm, svm_params, cv=5)
dt_grid = GridSearchCV(dt, dt_params, cv=5)

knn_grid.fit(X_train, y_train)
svm_grid.fit(X_train, y_train)
dt_grid.fit(X_train, y_train)

print("KNN")
print(knn_grid.best_params_)
print(knn_grid.best_score_)
print("SVM")
print(svm_grid.best_params_)
print(svm_grid.best_score_)
print("DT")
print(dt_grid.best_params_)
print(dt_grid.best_score_)


from sklearn import tree

# wykres drzewa decyzyjnego
plt.figure(figsize=(20, 10))
tree.plot_tree(dt, filled=True, fontsize=10)

# add description
plt.title("Decision tree")
plt.xlabel("features")
plt.ylabel("target")

plt.show()


# 5.
from sklearn.decomposition import PCA

pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_train)

plt.figure(figsize=(10, 10))
plt.scatter(X_pca[:, 0], X_pca[:, 1], c=y_train)

# jaka liczba cech pozwala na wyjasnienie wariancji
pca = PCA()
pca.fit_transform(X_train)
plt.plot(pca.explained_variance_ratio_)

plt.xlabel("number of components")
plt.ylabel("cumulative explained variance")
plt.show()

# 6.
from sklearn.neural_network import MLPClassifier

nn = MLPClassifier()
nn.fit(X_train, y_train)
y_pred_nn = nn.predict(X_test)
print("NN")
print(confusion_matrix(y_test, y_pred_nn))
print(accuracy_score(y_test, y_pred_nn))

# 7.
print()
print("KNN")
print(confusion_matrix(y_test, y_pred_knn))
print(accuracy_score(y_test, y_pred_knn))
print("SVM")
print(confusion_matrix(y_test, y_pred_svm))
print(accuracy_score(y_test, y_pred_svm))
print("DT")
print(confusion_matrix(y_test, y_pred_dt))
print(accuracy_score(y_test, y_pred_dt))
print("NN")
print(confusion_matrix(y_test, y_pred_nn))
print(accuracy_score(y_test, y_pred_nn))

# najlepszy klasyfikator
