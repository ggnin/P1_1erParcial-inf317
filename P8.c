#include <stdio.h>
#include <omp.h>

#define M 4  // Número de vectores (procesadores)
#define N 10 // Número de términos en cada vector

int main() {
    int i, j;
    int vectores[M][N];  // Matriz para almacenar los vectores

    // Directiva OpenMP para el bucle paralelo
    #pragma omp parallel for num_threads(M) private(j)
    for (i = 0; i < M; i++) {
        // Generar cada vector de la serie
        for (j = 0; j < N; j++) {
            vectores[i][j] = (i * N + 2) + 2 * j;
        }
    }

    // Imprimir los vectores generados
    printf("Vectores generados:\n");
    for (i = 0; i < M; i++) {
        printf("Vector %d: ", i + 1);
        for (j = 0; j < N; j++) {
            printf("%d ", vectores[i][j]);
        }
        printf("\n");
    }

    return 0;
}
