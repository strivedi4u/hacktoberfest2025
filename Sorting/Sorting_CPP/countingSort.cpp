#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Counting Sort function
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;
    
    vector<int> count(range, 0);
    vector<int> output(arr.size());
    
    // Store count of each element
    for (int num : arr)
        count[num - minVal]++;
    
    // Change count[i] to actual position
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
    
    // Build output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }
    
    // Copy output to arr
    arr = output;
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
    
    countingSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    cout << "\nTime Complexity: O(n + k) where k is range" << endl;
    cout << "Space Complexity: O(n + k)" << endl;
    
    return 0;
}