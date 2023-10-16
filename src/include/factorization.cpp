#include <bits/stdc++.h>
using namespace std;

#include "possible_multiplier.cpp"
#include "trial_division.cpp"

#define size_t long long

void factorization(size_t n, vector<size_t> P_r,
                   size_t U_pr, size_t Highstep) {
    // Initialization
    double epsilon = 0.02;
    size_t r = 2;
    size_t steps = 0;
    double square_root = sqrt(n);
    double wholePart;
    modf(sqrt(n), &wholePart);
    double fx = sqrt(n) - wholePart;

    size_t A, B;
    // Iterate until finding factors or until reaching the threshold specified for steps;
    do {
        double factor = fx * r;
        double factor_integer = round(factor);
        while ((r <= U_pr) && (factor != factor_integer + epsilon) && (factor != factor_integer - epsilon)) {
            // find a possible multiplier r of fx which generates its nearest integer;
            r = getPossibleMultiplier(r, fx);
            steps++;
            vector<pair<size_t, size_t>> factors = trialDivision(P_r, r);
            for (size_t i = 0; i < factors.size(); i++) {
                pair<size_t, size_t> factors_pq = factors[i];
                size_t p{factors_pq.first}, q{factors_pq.second};
                A = ceil(wholePart * ((double)q / p));
                if (n % A != 0) {
                    size_t P_ri = P_r[0];
                    size_t difference = A;
                    size_t index = 0;
                    for (size_t i = 0; i < P_r.size(); i++) {
                        if (A - P_r[i] < difference) {
                            P_ri = P_r[i];
                            difference = A - P_r[i];
                            index = i;
                        }
                    }

                    size_t product = P_r[index - 2] * P_r[index - 1] * P_r[index] * P_r[index + 1] + P_r[index + 2];
                    A = gcd(product, n);
                } else {
                    factor = fx * r;
                    factor_integer = round(factor);
                    epsilon = abs(factor_integer - factor);
                }
            }
        }
    } while ((n % A != 0) && (steps <= Highstep));

    if (steps < Highstep) {
        B = n / A;
        cout << "A: " << A << " B: " << B << endl;
    } else {
        cout << "n is prime or no solution is found for the chosen thresholds" << endl;
    }
}
