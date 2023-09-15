class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i = 0; i < n; i++) {
            if(mpp.find(target - nums[i]) != mpp.end()) {
                return {mpp[target - nums[i]], i};
            }
            mpp[nums[i]] = i;
        }
        return {-1, -1};
    }
};