#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/print.h"
#include "../include/array.h"

void bubble(int n, int MAX_RANDOM) {
    int i, j, k;
    int isSwapped;
    int arr[n];

    srand((unsigned int)time(NULL));

    array(arr, n, MAX_RANDOM); //n is the size of the array
    //MAX_RANDOM is the range of number, suppose from 1 to 10, 10 is MAX_RANDOM


    printf("\n\n");
    printf("Unsorted array -> "); // comment to suppress
    printArray(arr, n); // comment t supress

    clock_t start = clock();
    
    for (i = 0; i < n -1; i++) {
        isSwapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
                isSwapped = 1; 
            }
        }
        if (isSwapped == 0) break;
    }
    clock_t stop = clock();
    
    double timeTaken = ((double)(stop - start)) / CLOCKS_PER_SEC;
    
    printf("Sorted array -> "); //comment this line to supress printing
    printArray(arr, n); //comment this line to supress printing
    
    printf("Time taken in bubble sort %lf Seconds \n", timeTaken);
    printf("\n\n");
}

