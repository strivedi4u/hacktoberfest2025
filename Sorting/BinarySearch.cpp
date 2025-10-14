#include <iostream>
#include <vector>
#include <algorithm> 

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid; 
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    std::vector<int> arr = {34, 12, 56, 78, 23, 7, 89, 1};
    std::sort(arr.begin(), arr.end()); // Sort the array before applying binary search

    int target = 56;
    int result = binarySearch(arr, target);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}
