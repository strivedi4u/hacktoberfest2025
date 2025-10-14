//A bookstore manager needs to organize the prices of books in ascending order so that customers can easily find affordable options. The prices of the books are: [299, 150, 89, 450, 120, 350, 199, 99, 275, 400]
//Using the Insertion Sort algorithm, sort the book prices in ascending order.

#include <iostream>
using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int prices[] = {299, 150, 89, 450, 120, 350, 199, 99, 275, 400};
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "Original prices: ";
    printArray(prices, n);

    insertionSort(prices, n);

    cout << "Sorted prices: ";
    printArray(prices, n);

    return 0;
}
