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
    while (prime <= square_root) {
        if (remainder % prime == 0) {
            factors.push_back(prime);
            remainder /= prime;
        }
        i++;
        prime = subset_primes[i];
    }

    vector<pair<size_t, size_t>> factorized_pairs;
    for (size_t i = 0; i < subset_primes.size(); i++) {
        /* code */
    }

    return factorized_pairs;
}