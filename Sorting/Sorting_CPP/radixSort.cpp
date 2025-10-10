#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Counting sort for a specific digit
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);
    
    // Store count of occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    // Change count to actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy output to arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    int maxVal = *max_element(arr.begin(), arr.end());
    
    // Do counting sort for every digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortForRadix(arr, exp);
}

// Function to print array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " non-negative elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << "\nOriginal array: ";
    printArray(arr);
    
    radixSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    cout << "\nTime Complexity: O(d * (n + k)) where d is digits" << endl;
    cout << "Space Complexity: O(n + k)" << endl;
    
    return 0;
}   