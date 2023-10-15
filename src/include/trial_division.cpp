#include <bits/stdc++.h>
using namespace std;

// Function to find gcd of array of
// numbers
vector<pair<size_t, size_t>> trialDivision(vector<size_t> subset_primes, size_t n) {
    size_t square_root = ceil(sqrt(n));
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
    for (size_t i = 0; i < factors.size(); i++) {
        // TODO: pegar todos os pares possíveis que multiplicados geram r a partir dos seus fatores
    }

    return factorized_pairs;
}