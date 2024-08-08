#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/array.h"
#include "../include/print.h"

void sort(int arr[], int n, int m, int o) {
    int n1 = m - n + 1;
    int n2 = o - m;
    int *leftArr = (int *)malloc(n1 * sizeof(int));
    int *rightArr = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) leftArr[i] = arr[n + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[m + j + 1]; // basically m + 1 + j
    
    int i = 0;
    int j = 0;
    int k = n; 

    while(i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    free(leftArr);
    free(rightArr);
}

void mergeBoth(int arr[], int n, int o) {
    if (n < o) {
        int m = n + (o - n) / 2;
        mergeBoth(arr, n, m);
        mergeBoth(arr, m + 1, o);

        sort(arr, n, m, o);
    }

}

void merge(int n, int MAX_RANDOM) {
    int arr[n];

    srand((unsigned int)time(NULL));

    array(arr, n, MAX_RANDOM); //n is the size of the array
    //MAX_RANDOM is the range of number, suppose from 1 to 10, 10 is MAX_RANDOM

    printf("\n\n");
    printf("Unsorted array -> "); //comment to supress printing
    printArray(arr, n); // comment to supress printing

    clock_t start = clock();
    
    mergeBoth(arr, 0, n - 1);

    clock_t stop = clock();
    
    double timeTaken = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("Sorted array -> "); // comment to supress
    printArray(arr, n); // comment to supress
    printf("Time taken in merge sort %lf Seconds \n", timeTaken);
    printf("\n\n");
}

