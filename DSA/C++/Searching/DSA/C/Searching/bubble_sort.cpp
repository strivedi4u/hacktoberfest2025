#include <iostream>
#include <vector>
#include <utility> // For std::swap

/**
 * @brief Sorts a vector in ascending order using the Bubble Sort algorithm.
 *
 * @param arr The vector of integers to be sorted (passed by reference).
 */
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    // Outer loop for each pass
    // We need n-1 passes in the worst case
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        // Inner loop for comparisons
        // After 'i' passes, the last 'i' elements are already in place
        // So, we only need to compare up to (n - 1 - i)
        for (int j = 0; j < n - 1 - i; ++j) {
            
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                
                // Swap them if they are in the wrong order
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // OPTIMIZATION:
        // If no two elements were swapped by the inner loop,
        // then the array is already sorted, and we can stop early.
        if (!swapped) {
            break;
        }
    }
}

/**
 * @brief Helper function to print the elements of a vector.
 *
 * @param arr The vector to print (passed by const reference).
 */
void printVector(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// --- Main function to run the example ---
int main() {
    // Initialize a vector of integers
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original array: \n";
    printVector(data);

    // Call the bubbleSort function
    bubbleSort(data);

    std::cout << "\nSorted array: \n";
    printVector(data);

    return 0;
}
