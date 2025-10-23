
#include <bits/stdc++.h> 
using namespace std; 

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }


    return -1;
}

int main() {
    vector<int> myVector = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    int targetToFind = 23;
    int result = binarySearch(myVector, targetToFind);

    if (result != -1) {
        cout << "Element " << targetToFind << " found at index " << result << endl;
    } else {
        cout << "Element " << targetToFind << " not found." << endl;
    }

    targetToFind = 44;
    result = binarySearch(myVector, targetToFind);

    if (result != -1) {
        cout << "Element " << targetToFind << " found at index " << result << endl;
    } else {
        cout << "Element " << targetToFind << " not found." << endl;
    }

    return 0;
}