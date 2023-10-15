#include <bits/stdc++.h>
using namespace std;

#include "possible_multiplier.cpp"

void algorithm(size_t n, vector<size_t> P_r,
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
        double factor_integer;
        modf(factor, &factor_integer);
        while ((r <= U_pr) && (factor != factor_integer + epsilon) && (factor != factor_integer - epsilon)) {
            // find a possible multiplier r of fx which generates its nearest integer;
            r = getPossibleMultiplier(r, fx);
            steps++;
            size_t p, q;
            // TODO: factor r into p and q;
            vector<pair<size_t, size_t>> factors = trialDivision(P_r, r);
            for (size_t i = 0; i < factors.size(); i++) {
                A = wholePart * (q / p);
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
