#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#define ARRAY_SIZE 5

int main(int argc, char *argv[]) {
    int rank, size;
    int local_number;
    int *all_numbers;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Allocate memory for all_numbers
    all_numbers = (int *)malloc(sizeof(int) * size);

    // Seed the random number generator differently for each process
    srand(time(NULL) + rank);
    local_number = rand() % 100;
    printf("Process %d generated local number: %d\n", rank, local_number);

    // Perform Allgather to gather all local numbers into all_numbers
    MPI_Allgather(&local_number, 1, MPI_INT, all_numbers, 1, MPI_INT, MPI_COMM_WORLD);

    // Print the gathered array in each process
    printf("Process %d has all numbers: ", rank);
    for (int i = 0; i < size; ++i) {
        printf("%d ", all_numbers[i]);
    }
    printf("\n");

    // Free allocated memory
    free(all_numbers);

    MPI_Finalize();
    return 0;
}
