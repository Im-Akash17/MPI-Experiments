//OPENMP – 1. LOOP WORK-SHARING AND 2. SECTIONS WORK-SHARING 
#include <stdio.h>
#include <omp.h>

#define SIZE 1000

int main() {
    int i, sum = 0;
    int array[SIZE];

    // Initialize array
    for (i = 0; i < SIZE; ++i) {
        array[i] = i + 1;
    }

    // Loop Work-sharing using parallel for
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < SIZE; ++i) {
        sum += array[i];
    }
    printf("Loop Work-sharing Result: %d\n", sum);

    // Reset sum for Sections Worksharing
    sum = 0;

    // Sections Work-sharing using parallel sections
    #pragma omp parallel sections reduction(+:sum)
    {
        // Section 1
        #pragma omp section
        {
            for (i = 0; i < SIZE / 2; ++i) {
                sum += array[i];
            }
        }
        // Section 2
        #pragma omp section
        {
            for (i = SIZE / 2; i < SIZE; ++i) {
                sum += array[i];
            }
        }
    }

    printf("Sections Work-sharing Result: %d\n", sum);
    printf("=============Akash Gorkar - 21BCE11468=============");

    return 0;
}
