#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    vector<int> sortNearlySortedArray(vector<int>& arr, int k) {
       
        priority_queue<int, vector<int>, greater<int>> minHeap;

  
        vector<int> result;

 
        for (int i = 0; i <= k && i < arr.size(); i++) {
            minHeap.push(arr[i]);
        }

       
        for (int i = k + 1; i < arr.size(); i++) {
           
            result.push_back(minHeap.top());
            minHeap.pop();

            minHeap.push(arr[i]);
        }

       
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;
    }
};

int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    Solution obj;
    vector<int> sortedArr = obj.sortNearlySortedArray(arr, k);

    for (int num : sortedArr) {
        cout << num << " ";
    }

    return 0;
}
