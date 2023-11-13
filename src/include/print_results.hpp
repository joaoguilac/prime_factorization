#ifndef _PRINT_RESULTS_
#define _PRINT_RESULTS_

#include <bits/stdc++.h>
using namespace std;

void printResult(std::chrono::duration<float> time, size_t a, size_t b, size_t n,
                 size_t Highstep, vector<size_t> factors, std::string file_path, size_t flag) {
    std::ofstream results("results/" + file_path, std::ios::app);
    size_t algorithm;

    if (flag == 0) {
        results << "=================================================\n";
        if (a == 0 && b == 0) {
            results << ">> O número não foi gerado aleatoriamente." << std::endl;
        } else {
            results << ">> Intervalo de valores para geração de número aleatório a ser fatorado: " << a << " - " << b << std::endl;
        }
        results << ">> Número fatorado: " << n << std::endl;
        results << ">> Número máximo de tentativas fornecido: " << Highstep << std::endl;

        algorithm = 1;
    }
    if (flag == 1) {
        algorithm = 2;
    }
    if (flag == 2) {
        algorithm = 3;
    }
    results << ">> Algoritmo " << algorithm << ":" << std::endl;

    if (factors.size() > 0) {
        results << "\t>> Fatores:\n";
        results << "\t\tA: " << factors[0] << endl;
        results << "\t\tB: " << factors[1];
        results << "\n";
    } else {
        results << "\tO número é primo ou nenhuma solução foi encontrada para o limite de tentativas escolhido.\n";
    }
    // Milliseconds (10^-3)
    results << "\t>> Tempo para encontrar os fatores: ";
    results << std::chrono::duration<double, std::milli>(time).count();
    results << "ms\n";

    results.close();
}

#endif