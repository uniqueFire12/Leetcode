class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, mx = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                ans++;
            }
            else {
                ans = 0;
            }
            mx = max(mx, ans);
        }
        return mx;
    }
};