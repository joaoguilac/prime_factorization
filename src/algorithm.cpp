#include <bits/stdc++.h>
using namespace std;

vector<size_t> algorithm(size_t n, vector<size_t> P_r,
                         size_t U_pr, size_t Highstep) {
    double epsilon = 0.02;
    size_t r = 2;
    size_t steps = 0;
    double square_root = sqrt(n);
    double wholePart;
    modf(sqrt(n), &wholePart);

    double fx = sqrt(n) - wholePart;
}

int main(int argc, char const *argv[]) {
    auto start = std::chrono::steady_clock::now();

    // algoritm();

    auto end = std::chrono::steady_clock::now();

    auto time = end - start;
    std::cout << std::chrono::duration<double, std::milli>(time).count();

    return 0;
}
