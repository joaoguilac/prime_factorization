#ifndef _FACTORIZATION_4_
#define _FACTORIZATION_4_

#include <bits/stdc++.h>
using namespace std;

#define size_t long long

bool isPerfectSquare(size_t X) {
    if (X >= 0) {
        size_t square_root = sqrt(X);
        return (square_root * square_root == X);
    }
    return false;
}

vector<size_t> factorization4(size_t n, size_t Highstep) {
    vector<size_t> factors;

    size_t Y = 1;
    size_t square_root = n + Y * Y;
    size_t X = sqrt(square_root);
    size_t A, B;

    while (true) {
        if (isPerfectSquare(square_root)) {
            A = X + Y;
            B = X - Y;
            if (A * B == n) {
                break;
            }
        }
        Y++;
        square_root = n + Y * Y;
        X = sqrt(square_root);
    }

    factors.push_back(A);
    factors.push_back(B);

    return factors;
}

#endif