class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int currVal = nums[i];
            int remaining = target - currVal;
            if(mpp.find(remaining) != mpp.end()) {
               return {mpp[remaining], i};
            }
            mpp[currVal] = i;
        }
        return {-1, -1};
    }
};