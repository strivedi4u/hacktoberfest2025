#include <iostream>
#include <vector>
using namespace std;

// Get next gap for comb sort
int getNextGap(int gap) {
    gap = (gap * 10) / 13;
    return (gap < 1) ? 1 : gap;
}

// Comb Sort function
void combSort(vector<int>& arr) {
    int n = arr.size();
    int gap = n;
    bool swapped = true;
    
    while (gap != 1 || swapped) {
        gap = getNextGap(gap);
        swapped = false;
        
        // Compare elements with current gap
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
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
    
    combSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    cout << "\nTime Complexity: O(n^2/2^p) where p is increments" << endl;
    cout << "Space Complexity: O(1)" << endl;
    
    return 0;
}