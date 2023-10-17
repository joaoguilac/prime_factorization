#ifndef _POSSIBLE_MULTIPLIER_
#define _POSSIBLE_MULTIPLIER_

#include <bits/stdc++.h>
using namespace std;

#define size_t long long

size_t getPossibleMultiplier(size_t r, double fx) {
    if (fx != 0) {
        double multiplication = fx * r;
        size_t k = round(multiplication);
        double epsilon_line = abs((double)k - multiplication);

        double new_multiplication = fx * r;
        size_t new_k = round(new_multiplication);
        double new_epsilon_line = abs(double(new_k) - new_multiplication);
        while (new_epsilon_line >= epsilon_line) {
            r++;
            new_multiplication = fx * r;
            new_k = round(new_multiplication);
            new_epsilon_line = abs(double(new_k) - new_multiplication);
        }
    }
    return r;
}

#endif