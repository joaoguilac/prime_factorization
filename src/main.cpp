#include <bits/stdc++.h>
using namespace std;

#include "include/factorization.cpp"
#include "include/print_results.cpp"
#include "include/subset_primes.cpp"

#define size_t long long

int main(int argc, char const *argv[]) {
    size_t n, Highstep;
    cout << "Digite o número a ser fatorado: ";
    cin >> n;
    cout << "Digite o limite de tentativas para encontrar uma solução: ";
    cin >> Highstep;

    vector<size_t> subset_primes = getPrimeNumbers(n);

    auto start = std::chrono::steady_clock::now();
    vector<size_t> factors = factorization(n, subset_primes, 15100, Highstep);
    auto end = std::chrono::steady_clock::now();

    auto time = end - start;

    std::string output_file = argv[1];
    printResult(time, n, Highstep, factors, output_file);

    return 0;
}