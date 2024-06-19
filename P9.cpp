#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N = 9; // Número de términos
    int M = size; // Número de procesos

    // Calcular la serie para cada proceso
    for (int i = rank + 1; i <= N; i += M) {
        std::cout << i * 2 << " ";
    }

    std::cout << std::endl;

    MPI_Finalize();
    return 0;
}
