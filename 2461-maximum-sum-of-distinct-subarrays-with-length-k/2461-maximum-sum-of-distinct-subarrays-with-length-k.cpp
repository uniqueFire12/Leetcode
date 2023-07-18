class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        long long int sum = 0, maxm = 0;
        for(int i=0; i<nums.size(); i++) {
            if(mpp.count(nums[i]) == 0) {
                sum = sum + nums[i];
            }
            mpp[nums[i]]++;
            
            if(mpp.size() == k) {
                maxm = max(maxm, sum);
            }
            
            if(i-k+1 >= 0) {
                mpp[nums[i-k+1]]--;
                if(mpp[nums[i-k+1]] == 0) {
                    sum = sum - nums[i-k+1];
                    mpp.erase(nums[i-k+1]);
                }
            }
        }
        return maxm;
    }
};