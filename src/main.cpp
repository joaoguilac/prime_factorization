#include <bits/stdc++.h>
using namespace std;

#include "include/factorization.hpp"
#include "include/factorization2.hpp"
#include "include/print_results.hpp"
#include "include/subset_primes.hpp"

#define size_t long long

int randint(int a, int b) {
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    return std::uniform_int_distribution<int>(a, b)(rng);
}

int main(int argc, char const *argv[]) {
    size_t n, Highstep;

    cout << "Digite o número de uma das opções:" << endl;
    cout << "1. Especificar um n a ser fatorado." << endl;
    cout << "2. Fornecer um intervalo de números e gerar um número aleatório a ser fatorado." << endl;

    size_t option, a{0}, b{0};
    cin >> option;
    if (option == 1) {
        cout << "Digite o número n a ser fatorado: ";
        cin >> n;
    } else if (option == 2) {
        cout << "Digite o intervalo de possíveis valores a serem fatorados: ";
        cin >> a >> b;
        n = randint(a, b);
    }
    cout << "Digite o limite de tentativas para encontrar uma solução: ";
    cin >> Highstep;

    vector<size_t> subset_primes = getPrimeNumbers(n);

    auto start = std::chrono::steady_clock::now();
    vector<size_t> factors = factorization(n, subset_primes, 15100, Highstep);
    auto end = std::chrono::steady_clock::now();

    // print the result of the first algorithm
    auto time = end - start;
    std::string output_file = argv[1];
    printResult(time, a, b, n, Highstep, factors, output_file, 0);

    start = std::chrono::steady_clock::now();
    factors = factorization2(n);
    end = std::chrono::steady_clock::now();

    // print the result of the second algorithm
    time = end - start;
    printResult(time, a, b, n, Highstep, factors, output_file, 1);

    cout << "Acesse results/" << output_file << " para ver os resultados da execução." << endl;

    return 0;
}