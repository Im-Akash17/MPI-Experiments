#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 1000

int main() {
    int i;
    double sum = 0.0;
    double array[ARRAY_SIZE];

    // Initialize the array with some values
    for (i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i + 1.0;
    }

    // Combined parallel loop reduction and orphaned parallel loop execution
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < ARRAY_SIZE; ++i) {
        sum += array[i];
        
        // Orphaned parallel loop execution
        #pragma omp parallel
        {
            // Additional computation on each array element
            array[i] = array[i] * 2;
        }
    }

    // Output the sum and modified array elements
    printf("Sum: %f\n", sum);
    printf("Modified Array: [");
    for (i = 0; i < ARRAY_SIZE - 1; ++i) {
        printf("%f, ", array[i]);
    }
    printf("%f]\n", array[ARRAY_SIZE - 1]);

    return 0;
}
