#include <bits/stdc++.h>
using namespace std;

#define size_t long long

// Function to find gcd of array of
// numbers
vector<pair<size_t, size_t>> trialDivision(vector<size_t> subset_primes, size_t n) {
    size_t prime = subset_primes[0];
    size_t i = 0;
    size_t remainder = n;
    vector<size_t> factors;
    while (remainder != 1 && prime <= n) {
        if (remainder % prime == 0) {
            factors.push_back(prime);
            remainder /= prime;
        } else {
            i++;
            prime = subset_primes[i];
        }
    }

    // for (size_t i = 0; i < factors.size(); i++) {
    //     cout << factors[i] << endl;
    // }

    vector<pair<size_t, size_t>> factorized_pairs;
    size_t square_root = ceil(sqrt(n));
    i = 0;
    size_t factor = factors[i];
    while (factor <= square_root) {
        size_t result = n / factor;
        factorized_pairs.push_back({factor, result});
        i++;
        factor *= factors[i];
    }

    return factorized_pairs;
}