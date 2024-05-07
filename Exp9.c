#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    int local_value = 1; // Each process has a local value of 1
    int global_sum = 0; // The sum of all local values

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Perform the local computation
    printf("Process %d: local value = %d\n", rank, local_value);

    // Perform the reduction operation (sum) across all processes using MPI_Allreduce
    MPI_Allreduce(&local_value, &global_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    // Print the global sum
    printf("Global sum = %d\n", global_sum);

    MPI_Finalize();
    return 0;
}
