#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int RUN = 32;

// Insertion sort for small arrays
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Merge function
void merge(vector<int>& arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    vector<int> left(len1), right(len2);
    
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    
    int i = 0, j = 0, k = l;
    
    while (i < len1 && j < len2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    
    while (i < len1)
        arr[k++] = left[i++];
    
    while (j < len2)
        arr[k++] = right[j++];
}

// Tim Sort function
void timSort(vector<int>& arr) {
    int n = arr.size();
    
    // Sort individual runs
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, min(i + RUN - 1, n - 1));
    
    // Merge sorted runs
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);
            
            if (mid < right)
                merge(arr, left, mid, right);
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
    
    timSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    cout << "\nTime Complexity: O(n log n)" << endl;
    cout << "Space Complexity: O(n)" << endl;
    
    return 0;
}