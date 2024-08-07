#include <stdlib.h>

void array(int arr[], int n, int MAX_RANDOM) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % MAX_RANDOM) + 1;
    }

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int k = arr[i];
        arr[i] = arr[j];
        arr[j] = k;
    }
}
