#include <iostream>
#include <omp.h>

// Gladys Nina Mamani 
// 12465858

int suma(int *a, int *b) {
    return *a + *b;
}

int resta(int *a, int *b) {
    return *a - *b;
}
int multiplicacion(int *a, int *b) {
    int resultado = 0;
    #pragma omp parallel for reduction(+:resultado)
    for (int i = 0; i < *b; i++) {
        resultado += *a;
    }
    return resultado;
}

float division(int *a, int *b) {
    if (*b == 0) {
        std::cerr << "Error: División por cero" << std::endl;
        return 0;
    }
    float resultado = 0;
    float temp = *a;
    #pragma omp parallel for reduction(-:temp)
    while (temp >= *b) {
        temp -= *b;
        resultado++;
    }
    return resultado;
}

int main() {
    
    int num1 = 8, num2 = 7;
    
    std::cout << "Suma: " << suma(&num1, &num2) << std::endl;
    std::cout << "Resta: " << resta(&num1, &num2) << std::endl;
    std::cout << "Multiplicación: " << multiplicacion(&num1, &num2) << std::endl;
    
    if (num2 != 0) {
        std::cout << "División: " << division(&num1, &num2) << std::endl;
    } else {
        std::cerr << "No se puede dividir por cero." << std::endl;
    }

    return 0;
}
