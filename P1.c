#include <stdio.h>

// Función para sumar dos números
int suma(int *a, int *b) {
    return *a + *b;
}

// Función para restar dos números
int resta(int *a, int *b) {
    return *a - *b;
}

// Función para multiplicar dos números
int multiplicacion(int *a, int *b) {
    return (*a) * (*b);
}

// Función para dividir dos números
float division(int *a, int *b) {
    if (*b == 0) {
        printf("Error: División por cero\n");
        return 0;
    }
    return (float)(*a) / (float)(*b);
}

int main() {
    // Ejemplo de uso de las funciones
    int num1 = 8, num2 = 7;
    
    printf("Suma: %d\n", suma(&num1, &num2));
    printf("Resta: %d\n", resta(&num1, &num2));
    printf("Multiplicación: %d\n", multiplicacion(&num1, &num2));
    
    if (num2 != 0) {
        printf("División: %.2f\n", division(&num1, &num2));
    } else {
        printf("No se puede dividir por cero.\n");
    }

    return 0;
}
