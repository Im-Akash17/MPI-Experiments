
//MPI – NON-BLOCKING OPERATION 

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int number;
    MPI_Request request;

    if (world_rank == 0) {
        number = -1;
        MPI_Isend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &request);
        printf("Process 0 sends number %d\n", number);
    } else if (world_rank == 1) {
        MPI_Irecv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
    }

    if (world_rank == 1) {
        MPI_Status status;
        MPI_Wait(&request, &status);
        printf("Process 1 received number %d from process 0\n", number);
    }

    MPI_Finalize();
}
