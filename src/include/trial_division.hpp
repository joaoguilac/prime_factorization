#ifndef _TRIAL_DIVISION_
#define _TRIAL_DIVISION_

#include <bits/stdc++.h>
using namespace std;

#define size_t long long

vector<pair<size_t, size_t>> trialDivision(vector<size_t> subset_primes, size_t r) {
    size_t prime = subset_primes[0];
    size_t i = 0;
    size_t remainder = r;
    vector<size_t> factors;
    while (remainder != 1 && prime <= r) {
        if (remainder % prime == 0) {
            factors.push_back(prime);
            remainder /= prime;
        } else {
            i++;
            if (i == subset_primes.size()) {
                break;
            }
            prime = subset_primes[i];
        }
    }

    vector<pair<size_t, size_t>> factorized_pairs;
    size_t square_root = ceil(sqrt(r));
    i = 0;
    if (factors.size() > 0) {
        size_t factor = factors[i];
        while (factor <= square_root) {
            size_t result = r / factor;
            factorized_pairs.push_back({factor, result});
            i++;
            if (i == factors.size()) {
                break;
            }
            factor *= factors[i];
        }
    }

    return factorized_pairs;
}

#endif