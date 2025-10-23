// C program to implement insertion sort
#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int N) {

    // Starting from the second element
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are
      	// greater than key, to one position to
      	// the right of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Move the key to its correct position
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calling insertion sort on array arr
    insertionSort(arr, N);

    printf("Sorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}