#include <iostream>
// Gladys Nina Mamani 
// 12465858
int suma(int *a, int *b) {
    return *a + *b;
}

int resta(int *a, int *b) {
    return *a - *b;
}

int multiplicacion(int *a, int *b) {
    return (*a) * (*b);
}

float division(int *a, int *b) {
    if (*b == 0) {
        std::cerr << "Error: División por cero" << std::endl;
        return 0;
    }
    return static_cast<float>(*a) / static_cast<float>(*b);
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
