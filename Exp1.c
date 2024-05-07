#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void initialize_vectors(int* a, int* b) {
    for(int i = 0; i < SIZE; i++) {
        a[i] = i * 135;
        b[i] = SIZE;
    }
}

void calculate_sum(int* a, int* b, int* sum) {
    #pragma omp parallel for
    for(int i = 0; i < SIZE; i++) {
        sum[i] = a[i] + b[i];
    }
}

long long int calculate_dot_product(int* a, int* b) {
    long long int dot_product = 0;
    #pragma omp parallel for reduction(+:dot_product)
    for(int i = 0; i < SIZE; i++) {
        dot_product += (long long int)a[i] * b[i];
    }
    return dot_product;
}

int main() {
    int* a = (int*)malloc(SIZE * sizeof(int));
    int* b = (int*)malloc(SIZE * sizeof(int));
    int* sum = (int*)malloc(SIZE * sizeof(int));

    if (!a || !b || !sum) {
        printf("Memory allocation failed\n");
        return 1;
    }

    initialize_vectors(a, b);
    calculate_sum(a, b, sum);

    printf("Vector addition: \n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", sum[i]);
    }
    printf("\n");

    long long int dot_product = calculate_dot_product(a, b);
    printf("Dot product: %lld\n", dot_product);

    free(a);
    free(b);
    free(sum);

    return 0;
}