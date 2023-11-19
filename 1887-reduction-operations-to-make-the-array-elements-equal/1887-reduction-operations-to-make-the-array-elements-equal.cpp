class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>0; i--) {
            if(nums[i-1] != nums[i]) {
                ans += (n-i);
            }
        }
        return ans;
    }
};