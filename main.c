#include <stdio.h>
#include "include/print.h"
#include "include/bubble.h"
#include <time.h>


int main() {
    int arr[] = {40, 50, 50, 7, 4, 18, 89, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Size of array -> %d\n", n);

    printf("Unsorted array -> ");
    printArray(arr, n);

    clock_t start = clock();

    bubble(arr, n);

    clock_t stop = clock();
    
    double timeTaken = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("Time taken %lf Seconds \nSorted array -> ", timeTaken);
    printArray(arr, n);

    return 0;

}
