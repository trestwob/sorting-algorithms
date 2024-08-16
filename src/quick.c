#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/print.h"
#include "../include/array.h"


void swap(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int partition(int arr[], int i, int j) {
    int pivot = arr[j];
    int k = i - 1; //to make it easier to read

    for (; i < j; i++) {
        if (arr[i] <= pivot) {
            k++;
            swap(arr[k], arr[i]);
        }
    }

    swap(arr[k + 1], arr[j]);
    return (k + 1);
}


void quicksort(int arr[], int i, int j) {
    if (i < j) {
        int pivot = partition(arr, i, j);
        quicksort(arr, i, pivot - 1);
        quicksort(arr, pivot + 1, j);
    }
}


void quick(int n, int MAX_RANDOM) {
    
    int arr[n];

    srand((unsigned int)time(NULL));

    array(arr, n, MAX_RANDOM); //n is the size of the array
    //MAX_RANDOM is the range of number, suppose from 1 to 10, 10 is MAX_RANDOM

    printf("\n\n");
    printf("Unsorted array -> "); //comment to supress printing
    printArray(arr, n); // comment to supress printing

    clock_t start = clock();
    
    quicksort(arr, 0, n - 1);

    clock_t stop = clock();
    
    double timeTaken = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("Sorted array -> "); // comment to supress
    printArray(arr, n); // comment to supress
    printf("Time taken in quick sort %lf Seconds \n", timeTaken);
    printf("\n\n");
}
