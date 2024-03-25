//
// Created by User on 03.11.2023.
//

#ifndef LAB_4_FUNCTOR_H
#define LAB_4_FUNCTOR_H

class Functor {
public:
    bool operator()(int a, int b) {
        int sum_a = 0, sum_b = 0;
        int temp_a = a, temp_b = b;
        while (temp_a != 0) {
            sum_a += temp_a % 10;
            temp_a /= 10;
        }
        while (temp_b != 0) {
            sum_b += temp_b % 10;
            temp_b /= 10;
        }
        return sum_a > sum_b;
    }
};


#endif //LAB_4_FUNCTOR_H
