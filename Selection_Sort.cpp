#include <iostream>
using namespace std;

// Selection Sort Function
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) { // Find the smallest element
                minIndex = j;
            }
        }
        // Swap minimum element with first element of unsorted part
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calling Selection Sort
    selectionSort(arr, n);

    // Output Sorted Array
    cout << "Sorted Array (Selection Sort): ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
