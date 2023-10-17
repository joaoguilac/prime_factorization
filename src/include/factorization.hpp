#ifndef _FACTORIZATION_1_
#define _FACTORIZATION_1_

#include <bits/stdc++.h>
using namespace std;

#include "possible_multiplier.hpp"
#include "trial_division.hpp"

#define size_t long long

vector<size_t> factorization(size_t n, vector<size_t> P_r,
                             size_t U_pr, size_t Highstep) {
    vector<size_t> factors_AB;
    // Initialization
    double epsilon = 0.02;
    size_t r = 2;
    size_t steps = 0;
    double square_root = sqrt(n);
    double wholePart;
    modf(square_root, &wholePart);
    double fx = square_root - wholePart;

    size_t A, B;
    // Iterate until finding factors or until reaching the threshold specified for steps;
    do {
        double factor = fx * r;
        double factor_integer = round(factor);  //! pode ser ceil ou round
        while ((r <= U_pr) && (factor != factor_integer + epsilon) && (factor != factor_integer - epsilon)) {
            // find a possible multiplier r of fx which generates its nearest integer;
            r = getPossibleMultiplier(r, fx);  //! a condição de encontrar o inteiro mais próximo pode ser diferente
            steps++;
            vector<pair<size_t, size_t>> factors_pq = trialDivision(P_r, r);
            for (size_t i = 0; i < factors_pq.size(); i++) {
                auto pq = factors_pq[i];
                size_t p{pq.first}, q{pq.second};
                A = ceil(wholePart * ((double)q / p));  //! pode ser ceil ou round
                if (n % A != 0) {
                    size_t difference = A;
                    size_t index = 0;
                    for (size_t j = 0; j < P_r.size(); j++) {
                        if (A - P_r[j] < difference) {
                            difference = A - P_r[j];
                            index = j;
                        }
                    }

                    size_t product = P_r[index - 2] * P_r[index - 1] * P_r[index] * P_r[index + 1] * P_r[index + 2];
                    A = gcd(product, n);
                } else {
                    factor = fx * r;
                    factor_integer = round(factor);
                    epsilon = abs(factor_integer - factor);
                }
            }
        }
    } while ((n % A != 0) && (steps <= Highstep));

    if (steps < Highstep && A != 1) {
        B = n / A;
        cout << "A: " << A << " B: " << B << endl;
        factors_AB.push_back(A);
        factors_AB.push_back(B);
    } else {
        cout << "O número é primo ou nenhuma solução foi encontrada para o limite de tentativas escolhido." << endl;
    }
    return factors_AB;
}

#endif