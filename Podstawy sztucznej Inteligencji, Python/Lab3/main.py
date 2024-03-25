import numpy as npimport pandas as pd
from sklearn.neighbors import KNeighborsClassifier as kNNfrom sklearn.svm import SVC as SVM
from sklearn.model_selection import train_test_splitfrom sklearn.metrics import confusion_matrix
data = pd.read_excel("practice_lab_3.xlsx")y = data['Loan_Status'].values
X = data.drop(columns = ['Loan_Status']).valuesmodels = [kNN(), SVM()]
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state= 221, shuffle=False)for model in models:
 model.fit(X_train,y_train) y_pred = model.predict(X_test)
 print(confusion_matrix(y_test, y_pred))