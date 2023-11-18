class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) {
        int n = nums.size();
        int i = 0, j;
        sort(nums.begin(), nums.end());
        for(j = 0; j < n; j++) {
            k += nums[j];
            if(k < (long)nums[j] * (j-i+1)) {
                k -= nums[i];
                i++;
            }
        }
        return (j-i);
    }
};