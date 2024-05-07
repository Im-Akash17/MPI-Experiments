#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 10

int main(int argc, char *argv[]) {
    int *a, *b, *c;
    int n = ARRAY_SIZE; 
    int i;

    a = (int *)malloc(sizeof(int) * n); 
    b = (int *)malloc(sizeof(int) * n); 
    c = (int *)malloc(sizeof(int) * n);

    printf("=============VECTOR ADDITION=============\n\n");

    #pragma omp parallel for 
    for (i = 0; i < n; i++) {
        a[i] = i; 
        b[i] = i;
    }

    #pragma omp parallel for 
    for (i = 0; i < n; i++) { 
        c[i] = a[i] + b[i];
    }

    printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n"); 
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
    } 

    free(a); 
    free(b); 
    free(c);

    printf("=============Akash Gorkar - 21BCE11468=============");
    return 0;
}
# DOT PRODUCT :
#include <stdio.h>
#include <omp.h>

#define SIZE 100000

int main() {
    int i;
    int A[SIZE], B[SIZE];
    long long int dotProduct = 0;

    // Initialize arrays
    for (i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = 2 * i;
    }

    // Calculate dot product
    for (i = 0; i < SIZE; i++) {
        dotProduct += A[i] * B[i];
    }

    // Print result
    printf("Dot Product Result: %lld\n", dotProduct);

    return 0;
}
