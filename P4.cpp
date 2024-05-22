#include <iostream>
#include <vector>
#include <omp.h>
// Gladys Nina Mamani 
// 12465858

std::vector<int> multiplicarMatrizVector(const std::vector<std::vector<int>>& matriz, const std::vector<int>& vector) {
    int n = matriz.size();
    std::vector<int> resultado(n, 0);

    #pragma omp parallel for shared(matriz, vector, resultado) collapse(2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }

    return resultado;
}

int main() {
   
    const int N = 3;

    std::vector<std::vector<int>> matriz = {{1, 2, 3},
                                             {4, 5, 6},
                                             {7, 8, 9}};
    
   
    std::vector<int> vector = {1, 2, 3};

    std::vector<int> resultado = multiplicarMatrizVector(matriz, vector);

    std::cout << "Resultado de la multiplicación:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << resultado[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
