#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Bucket Sort function for floating point numbers
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;
    
    // Create n empty buckets
    vector<vector<float>> buckets(n);
    
    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIdx = n * arr[i];
        buckets[bucketIdx].push_back(arr[i]);
    }
    
    // Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());
    
    // Concatenate all buckets
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

// Function to print array
void printArray(const vector<float>& arr) {
    for (float num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<float> arr(n);
    cout << "Enter " << n << " elements (between 0 and 1): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << "\nOriginal array: ";
    printArray(arr);
    
    bucketSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    cout << "\nTime Complexity: O(n + k) average" << endl;
    cout << "Space Complexity: O(n + k)" << endl;
    
    return 0;
}