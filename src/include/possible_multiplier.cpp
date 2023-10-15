#include <bits/stdc++.h>
using namespace std;

size_t getPossibleMultiplier(size_t r, double fx) {
    double multiplication = fx * r;
    size_t k = round(multiplication);
    double epsilon_line = (double)k - multiplication;
    cout << "multiplication: " << multiplication << endl;
    cout << "k: " << k << endl;
    cout << "epsilon_line: " << epsilon_line << endl;

    double new_multiplication = fx * r;
    size_t new_k = round(new_multiplication);
    double new_epsilon_line = double(new_k) - new_multiplication;
    while (new_epsilon_line >= epsilon_line) {
        r++;
        new_multiplication = fx * r;
        new_k = round(new_multiplication);
        new_epsilon_line = double(new_k) - new_multiplication;
    }
    return r;
}