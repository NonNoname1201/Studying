#ifndef LAB_3_ARRAY_H
#define LAB_3_ARRAY_H

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Array {
private:
    int maxSize;
    int firstFreeIndex;
    T *tab;

public:
    Array(int size) : maxSize(size), firstFreeIndex(0), tab(new T[size]) {}

    Array() : Array(10) {}

    ~Array() { delete[] tab; }

    template<>
    void sort<string>() {

        for (int i = 0; i < firstFreeIndex; i++) {
            for (int j = 0; j < firstFreeIndex - 1; j++) {
                if (tab[j].length() > tab[j + 1].length()) {
                    T temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                }
            }
        }
    }

template<>
void sort<>() {

    for (int i = 0; i < firstFreeIndex; i++) {
        for (int j = 0; j < firstFreeIndex - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                T temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

T getMax() {

    if (typeid(T) == typeid(string)) {
        int max = 0;
        for (int i = 0; i < firstFreeIndex; i++) {
            if (tab[i].length() > tab[max].length()) {
                max = i;
            }
        }
        return tab[max];
    } else {
        int max = 0;
        for (int i = 0; i < firstFreeIndex; i++) {
            if (tab[i] > tab[max]) {
                max = i;
            }
        }
        return tab[max];
    }
};

void print() {
    for (int i = 0; i < firstFreeIndex; i++) {
        cout << tab[i] << " ";
    }
};

void add(T element) {

    if (firstFreeIndex < maxSize) {
        tab[firstFreeIndex] = element;
        firstFreeIndex++;
    }
};

T get(int index) {
    if (index < firstFreeIndex) {
        return tab[index];
    } else {
        return tab[0];
    }
};
};

#endif // LAB_3_ARRAY_H
