#include <mpi.h>
#include <stdio.h>
#include <math.h>

double f(double x) {
    return 4.0 / (1.0 + x * x);
}

int main(int argc, char** argv) {
    int rank, size, n, i;
    double a, b, h, local_sum, total_sum, x;

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Set the interval [a, b] and the number of trapezoids n
    a = 0.0;
    b = 1.0;
    n = 1000000; // number of trapezoids
    h = (b - a) / n; // step size

    // Calculate local sum
    local_sum = 0.0;
    for (i = rank + 1; i <= n; i += size) {
        x = a + (i - 0.5) * h;
        local_sum += f(x);
    }
    local_sum *= h;

    // Reduce all local sums to a total sum
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the result
    if (rank == 0) {
        printf("Approximation of pi: %f\n", total_sum);
    }

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
