#include <stdio.h>
#include "print.h"
#include <time.h>

void bubble(int arr[], int n) {
    int i, j, k;
    int isSwapped;

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
}


int main() {
    int arr[] = {40, 50, 50, 7, 4, 18, 89, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);

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
