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
