#ifndef _FACTORIZATION_2_
#define _FACTORIZATION_2_

#include <bits/stdc++.h>
using namespace std;

#include "subset_primes.hpp"
#include "trial_division.hpp"

#define size_t long long

vector<size_t> factorization2(size_t n) {
    vector<size_t> factors;
    vector<size_t> subset_primes = getPrimeNumbers(n);
    vector<pair<size_t, size_t>> possible_factors = trialDivision(subset_primes, n);

    for (size_t i = 0; i < possible_factors.size(); i++) {
        auto p_factor = possible_factors[i];
        auto factor_A = p_factor.first;
        auto factor_B = p_factor.second;

        if (factor_A != 1 && factor_B != 1) {
            factors.push_back(factor_A);
            factors.push_back(factor_B);
            break;
        }
    }

    return factors;
}

#endif