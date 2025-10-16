#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // sort array first

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // skip duplicates for left and right
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
                else if (sum < 0) {
                    left++;  // need a bigger sum
                }
                else {
                    right--; // need a smaller sum
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = sol.threeSum(nums);

    cout << "Triplets that sum to 0:\n";
    for (auto &triplet : res) {
        for (auto &num : triplet) cout << num << " ";
        cout << endl;
    }

    return 0;
}
