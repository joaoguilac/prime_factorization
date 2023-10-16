#include <bits/stdc++.h>
using namespace std;

#include "include/factorization.cpp"
#include "include/subset_primes.cpp"

#define size_t long long

int main(int argc, char const *argv[]) {
    // size_t n = (size_t)argv[1];
    size_t n;
    cin >> n;
    vector<size_t> subset_primes = getPrimeNumbers(n);

    auto start = std::chrono::steady_clock::now();
    factorization(n, subset_primes, 1000, 1000);
    auto end = std::chrono::steady_clock::now();

    auto time = end - start;
    // std::cout << std::chrono::duration<double, std::milli>(time).count();

    return 0;
}