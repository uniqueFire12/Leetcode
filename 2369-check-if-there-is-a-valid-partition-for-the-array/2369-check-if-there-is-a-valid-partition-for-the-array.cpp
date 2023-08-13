class Solution {
public:
    bool f(int n, vector<int>& nums, int i, vector<int>& dp) {
        if(i == n) return true;
        
        if(dp[i] != -1) return dp[i];
        
        if(i + 1 < n && nums[i] == nums[i+1] ) {
            if(f(n, nums, i + 2, dp)) return true;
            if(i + 2 < n && nums[i] == nums[i+2]){
                if(f(n, nums, i + 3, dp)) return true;
            }
        }
        
        if(i + 2 < n && nums[i] == nums[i+1]-1 && nums[i] == nums[i+2] - 2 ){
            if(f(n, nums, i + 3, dp)) return true;
        }
        
        return dp[i] = false;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return f(n, nums, 0, dp);
    }
};