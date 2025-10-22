#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create prefix sum array
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    // Print prefix sum array
    cout << "Prefix sum array: ";
    for (int i = 0; i < n; i++) {
        cout << prefixSum[i] << " ";
    }
    cout << endl;

    // Example: sum of subarray from l to r (0-indexed)
    int l, r;
    cout << "Enter left and right indices to find subarray sum: ";
    cin >> l >> r;

    int subarraySum = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
    cout << "Sum of elements from index " << l << " to " << r << " is " << subarraySum << endl;

    return 0;
}
