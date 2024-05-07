#include <stdio.h>
#include <omp.h>

#define N 1000

void matrixMultiply(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp target teams distribute parallel for collapse(2) map(to: A, B) map(from: C)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    // Initialize matrices A and B
    // (For simplicity, matrices are initialized with sequential values; real-world data initialization would differ)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    // Perform matrix multiplication on GPU using OpenMP
    matrixMultiply(A, B, C);

    // Display a sample element from the resulting matrix
    printf("Resultant Matrix C[0][0]: %d\n", C[0][0]);

    return 0;
}
