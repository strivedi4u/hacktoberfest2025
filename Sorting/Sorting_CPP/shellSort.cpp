#include <iostream>
#include <vector>
using namespace std;

// Shell Sort function
void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    // Start with a large gap, then reduce
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            arr[j] = temp;
        }
    }
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
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << "\nOriginal array: ";
    printArray(arr);
    
    shellSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    cout << "\nTime Complexity: O(n log n) to O(n^2)" << endl;
    cout << "Space Complexity: O(1)" << endl;
    
    return 0;
}