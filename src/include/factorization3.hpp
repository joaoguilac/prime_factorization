#ifndef _FACTORIZATION_3_
#define _FACTORIZATION_3_

#include <bits/stdc++.h>
using namespace std;

#include "subset_primes.hpp"
#include "trial_division.hpp"

#define size_t long long

size_t randint(size_t a, size_t b) {
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    return std::uniform_int_distribution<size_t>(a, b)(rng);
}

vector<size_t> factorization3(size_t n, size_t Highstep) {
    vector<size_t> factors;
    size_t i = 1;
    size_t x = randint(0, n - 1);
    size_t y = x;
    size_t k = 2;

    while (Highstep > 0) {
        i++;
        x = (x * x - 1) % n;
        size_t d = gcd(abs(y - x), n);
        if (d != 1 and d != n) {
            factors.push_back(d);
            break;
        }
        if (i == k) {
            y = x;
            k = 2 * k;
        }
        Highstep--;
    }

    if (factors.size() > 0) {
        size_t B = n / factors[0];
        factors.push_back(B);
    }

    return factors;
}

#endif