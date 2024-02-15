class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        for(int i = n - 1; i >= 2; i--) {
            sum -= nums[i];
            if(sum > nums[i]) {
                return sum + nums[i];
            }
        }
        
        return -1;
    }
};