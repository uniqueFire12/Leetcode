class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size() - 1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum > ans) {
                ans = sum;
            }
            i++;
            j--;
        }
        return ans;
    }
};