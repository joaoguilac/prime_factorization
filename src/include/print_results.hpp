#ifndef _PRINT_RESULTS_
#define _PRINT_RESULTS_

#include <bits/stdc++.h>
using namespace std;

void printResult(std::chrono::duration<float> time, size_t a, size_t b, size_t n,
                 size_t Highstep, vector<size_t> factors, std::string file_path, bool flag) {
    std::ofstream results("results/" + file_path, std::ios::app);
    std::string algorithm;

    if (flag == 0) {
        results << "=================================================\n";
        if (a == 0 && b == 0) {
            results << ">> O número não foi gerado aleatoriamente." << std::endl;
        } else {
            results << ">> Intervalo de valores para geração de número aleatório a ser fatorado: " << a << " - " << b << std::endl;
        }
        results << ">> Número fatorado: " << n << std::endl;
        results << ">> Número máximo de tentativas fornecido: " << Highstep << std::endl;

        if (factors.size() > 0) {
            results << ">> Fatores:\n";
            results << "\tA: " << factors[0] << endl;
            results << "\tB: " << factors[1];
            results << "\n";
        } else {
            results << "O número é primo ou nenhuma solução foi encontrada para o limite de tentativas escolhido.";
        }
        algorithm = "algoritmo 1";
    }
    if (flag == 1) {
        algorithm = "algoritmo 2";
    }

    // Milliseconds (10^-3)
    results << ">> Tempo para encontrar os fatores (" << algorithm << ")"
            << ": ";
    results << std::chrono::duration<double, std::milli>(time).count();
    results << "ms\n";

    results.close();
}

#endif