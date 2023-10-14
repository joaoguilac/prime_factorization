#include <bits/stdc++.h>
using namespace std;

vector<size_t> algorithm(size_t n, vector<size_t> P_r,
                         size_t U_pr, size_t Highstep) {
    // Initialization
    double epsilon = 0.02;
    size_t r = 2;
    size_t steps = 0;
    double square_root = sqrt(n);
    double wholePart;
    modf(sqrt(n), &wholePart);
    double fx = sqrt(n) - wholePart;

    int A, B;
    // Iterate until finding factors or until reaching the threshold specified for steps;
    do {
        double factor = fx * r;
        double factor_integer;
        modf(factor, &factor_integer);
        while ((r <= U_pr) && (factor != factor_integer + epsilon) && (factor != factor_integer - epsilon)) {
            // TODO: find a possible multiplier r of fx which generates its nearest integer;
            steps++;
            int p, q;
            // TODO: factor r into p and q;
            A = wholePart * (p / q);
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
    } while ((n % A != 0) && (steps <= Highstep));

    if (steps < Highstep) {
        B = n / A;
    } else {
        cout << "n is prime or no solution is found for the chosen thresholds" << endl;
    }
}
