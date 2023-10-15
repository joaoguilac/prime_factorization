#include <bits/stdc++.h>
using namespace std;

#include "include/factorization.cpp"
// #include "include/possible_multiplier.cpp"
#include "include/subset_primes.cpp"
#include "include/trial_division.cpp"

int main(int argc, char const *argv[]) {
    // size_t n = (size_t)argv[1];
    size_t n;
    cin >> n;
    vector<size_t> subset_primes = getPrimeNumbers(n);
    // getPossibleMultiplier(15, 0.86618);
    trialDivision(subset_primes, n);

    auto start = std::chrono::steady_clock::now();
    // algorithm(n, subset_primes, 1000, 1000);
    auto end = std::chrono::steady_clock::now();

    auto time = end - start;
    // std::cout << std::chrono::duration<double, std::milli>(time).count();

    return 0;
}