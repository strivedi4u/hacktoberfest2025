#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> indexmap;

        for(int i=0;i<n;i++){
            int cur_num=nums[i];
            if(indexmap.count(cur_num)){
                int prev_index=indexmap[cur_num];
                if(i-prev_index<=k){
                    return true;
                }
            }
            indexmap[cur_num]=i;
        }

        return false;
    }
};