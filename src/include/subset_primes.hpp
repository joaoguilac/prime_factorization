#ifndef _SUBSET_PRIMES_
#define _SUBSET_PRIMES_

#include <bits/stdc++.h>
using namespace std;

#define size_t long long

bool isPrime(size_t n) {
    if (n == 1 || n == 0) {
        return false;
    }

    size_t square_root = sqrt(n);
    for (size_t i = 2; i <= square_root; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

vector<size_t> getPrimeNumbers(size_t n) {
    vector<size_t> prime_numbers;
    size_t square_root = ceil(sqrt(n));

    //! invés da raiz quadrada pode testar n
    for (size_t i = 1; i <= square_root; i++) {
        if (isPrime(i)) {
            prime_numbers.push_back(i);
        }
    }

    return prime_numbers;
}

#endif