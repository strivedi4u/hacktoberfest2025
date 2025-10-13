//Kadane's Algorithm to find the maximum sum of a contiguous subarray
//Time Complexity: O(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

long long maxSubArraySum(const std::vector<int>& arr) {
    if (arr.empty()) return 0;
    
    // Initialize both to the first element's value, or INT_MIN if empty.
    long long max_so_far = arr[0];
    long long current_max = arr[0];
    
    // Start from the second element
    for (size_t i = 1; i < arr.size(); ++i) {
        // The maximum subarray ending at index i is EITHER:
        // 1. The current element (arr[i])
        // 2. The current element plus the maximum subarray ending at (i-1) (current_max + arr[i])
        current_max = std::max((long long)arr[i], current_max + arr[i]);
        
        // Update the overall maximum sum found so far
        max_so_far = std::max(max_so_far, current_max);
    }
    
    return max_so_far;
}


int main() {
    std::vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; 
    // Max subarray is {4, -1, 2, 1}, Sum: 6
    std::cout << "Max Subarray Sum: " << maxSubArraySum(arr1) << "\n"; // Output: 6
    
    std::vector<int> arr2 = {1, 2, 3, -2, 5}; 
    // Max subarray is {1, 2, 3, -2, 5}, Sum: 9
    std::cout << "Max Subarray Sum: " << maxSubArraySum(arr2) << "\n"; // Output: 9

    return 0;
}
