#include <bits/stdc++.h>
using namespace std;

#define size_t long long

// Function to check if a given
// number is prime
bool isPrime(size_t n) {
    // Since 0 and 1 is not prime
    // return false.
    if (n == 1 || n == 0) return false;

    // Run a loop from 2 to
    // square root of n.
    for (size_t i = 2; i * i <= n; i++) {
        // If the number is divisible by i,
        // then n is not a prime number.
        if (n % i == 0) return false;
    }

    // Otherwise n is a prime number.
    return true;
}

// Check for every number from 1 to N
vector<size_t> getPrimeNumbers(size_t n) {
    vector<size_t> prime_numbers;
    // size_t square_root = ceil(sqrt(n));

    // TODO: tirar 1000 e colocar n
    for (size_t i = 1; i <= 15100; i++) {
        // Check if current number is prime
        if (isPrime(i)) {
            prime_numbers.push_back(i);
        }
    }

    return prime_numbers;
}