
//MPI – COLLECTIVE OPERATION WITH "SYNCHRONIZATION" 

#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int sleep_time = world_rank * 2;
    printf("Process %d sleeps for %d seconds\n", world_rank, sleep_time);
    sleep(sleep_time);

    printf("Process %d before barrier\n", world_rank);

    MPI_Barrier(MPI_COMM_WORLD);

    printf("Process %d after barrier\n", world_rank);

    MPI_Finalize();
}
