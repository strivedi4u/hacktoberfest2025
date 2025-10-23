#include <iostream>
using namespace std;

int fibonacciSearch(int arr[], int n, int key) {
    // Initialize Fibonacci numbers
    int fibMMm2 = 0;     // (m-2)'th Fibonacci No.
    int fibMMm1 = 1;     // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

    // fibM is going to store the smallest Fibonacci number >= n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Marks the eliminated range from front
    int offset = -1;

    // While there are elements to inspect
    while (fibM > 1) {
        // Check if fibMMm2 is a valid location
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < key) {
            // Move 1 Fibonacci down
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > key) {
            // Move 2 Fibonacci down
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return i; // element found
    }

    // comparing the last element
    if (fibMMm1 && arr[offset + 1] == key)
        return offset + 1;

    // element not found
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = fibonacciSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
