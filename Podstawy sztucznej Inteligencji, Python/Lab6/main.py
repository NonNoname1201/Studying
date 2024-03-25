from keras.layers import Dense, BatchNormalization
from keras.layers import Dropout, GaussianNoise
from keras.layers import LayerNormalization
from keras.models import Sequential
from keras.optimizers import Adam


neuron_num = 64
do_rate = 0.5
noise = 0.1
learning_rate = 0.001

reg_rate = [0, 0.0001, 0.001, 0.01, 0.1]

block = [
    Dense,
    LayerNormalization(),
    BatchNormalization,
    Dropout,
    GaussianNoise]

args = [
    (neuron_num,'selu'),(),(),(do_rate,),(noise,)]

for i in reg_rate:
    model = Sequential()
    model.add(Dense(neuron_num, activation='relu', input_shape=(X_train,), kernel_regularizer=l2(i)))

model.compile(optimizer= Adam(learning_rate),
    loss='binary_crossentropy',
    metrics=('accuracy', 'Recall', 'Precision'))

model.fit(X_train, y_train, batch_size=32,
    epochs=nrEpoch[0], validation_data=(X_test, y_test),
    verbose=0)

acc=max(model.history.history['val_accuracy'])


