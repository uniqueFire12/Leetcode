class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int sum = 0;
        
        for(auto num : nums) {
            sum += num;
        }
        
        int left = 0; 
        int right = sum;
        
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            right -= num;
            
            ans[i] = num * i - left + right - num * (nums.size() - i - 1);
            left += num;
        }
        
        return ans;
    }
};