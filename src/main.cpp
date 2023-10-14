#include <bits/stdc++.h>
using namespace std;

#include "include/factorization.cpp"
#include "include/subset_primes.cpp"

int main(int argc, char const *argv[]) {
    int n = (int)argv[1];
    vector<size_t> subset_primes = getPrimeNumbers(n);

    auto start = std::chrono::steady_clock::now();
    algorithm(n, subset_primes, 1000, 1000);
    auto end = std::chrono::steady_clock::now();

    auto time = end - start;
    std::cout << std::chrono::duration<double, std::milli>(time).count();

    return 0;
}