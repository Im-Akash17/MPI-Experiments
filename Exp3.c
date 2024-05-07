#include <stdio.h>
#include <omp.h>
#define ARRAY_SIZE 1000
int main()
{
 int i, sum = 0;
 int array[ARRAY_SIZE];
 // Initialize array
 for (i = 0; i < ARRAY_SIZE; i++)
 {
 array[i] = i;
 }
// Combined parallel loop reduction
#pragma omp parallel for reduction(+ : sum) num_threads(4)
 for (i = 0; i < ARRAY_SIZE; i++)
 {
 sum += array[i];
 }
 printf("Sum using combined parallel loop reduction: %d\n", sum);
 sum = 0; // Reset sum
 // Orphaned parallel loop reduction
 sum = 0; // Reset sum
#pragma omp parallel num_threads(4)
 {
 int local_sum = 0;
// Each thread works on a portion of the array
#pragma omp for
 for (i = 0; i < ARRAY_SIZE; i++)
 {
 local_sum += array[i];
 }
// Combine local sums
#pragma omp critical
 {
 sum += local_sum;
 }
 }

  printf("Sum using orphaned parallel loop reduction: %d\n", sum);
 return 0;
}
