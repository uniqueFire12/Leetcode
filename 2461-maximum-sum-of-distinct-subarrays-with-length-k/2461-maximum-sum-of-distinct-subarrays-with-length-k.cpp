class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int> hash;
        long long int sum = 0, mx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(hash.count(nums[i]) == 0) {
                sum += nums[i];
            }
            hash[nums[i]]++;
            if(hash.size() == k) {
                mx = max(mx, sum);
            }
            if(i-k+1 >= 0) {
                hash[nums[i-k+1]]--;
                if(hash[nums[i-k+1]] == 0) {
                    sum = sum - nums[i-k+1];
                    hash.erase(nums[i-k+1]);
                }
            }
        }
        return mx;
    }
};