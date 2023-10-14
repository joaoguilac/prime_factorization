#include <bits/stdc++.h>
using namespace std;

// Function to check if a given
// number is prime
bool isPrime(int n) {
    // Since 0 and 1 is not prime
    // return false.
    if (n == 1 || n == 0) return false;

    // Run a loop from 2 to
    // square root of n.
    for (int i = 2; i * i <= n; i++) {
        // If the number is divisible by i,
        // then n is not a prime number.
        if (n % i == 0) return false;
    }

    // Otherwise n is a prime number.
    return true;
}

// Check for every number from 1 to N
vector<size_t> getPrimeNumbers(int n) {
    vector<size_t> prime_numbers;
    size_t square_root = ceil(sqrt(n));

    for (int i = 1; i <= square_root; i++) {
        // Check if current number is prime
        if (isPrime(i)) {
            prime_numbers.push_back(i);
        }
    }

    return prime_numbers;
}