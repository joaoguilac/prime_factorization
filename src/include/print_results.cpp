#include <bits/stdc++.h>
using namespace std;

void printResult(std::chrono::duration<float> time, size_t n, size_t Highstep,
                 vector<size_t> factors, std::string file_path) {
    std::ofstream results("results/" + file_path, std::ios::app);
    results << "=================================================\n";

    // Milliseconds (10^-3)
    results << ">> Tempo para encontrar os fatores: ";
    results << std::chrono::duration<double, std::milli>(time).count();
    results << "ms\n"
            << std::endl;

    results << ">> Número fatorado: " << n << std::endl;
    results << ">> Número máximo de tentativas fornecido: " << Highstep << std::endl;

    if (factors.size() > 0) {
        results << ">> Fatores :\n";
        results << "\tA " << factors[0];
        results << "\tB " << factors[1];
        results << std::endl;
    } else {
        results << "O número é primo ou nenhuma solução foi encontrada para o limite de tentativas escolhido.";
    }
    results.close();

    cout << "Acesse results/" << file_path << " para ver os resultados da execução." << endl;
}