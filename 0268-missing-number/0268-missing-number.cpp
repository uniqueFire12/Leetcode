class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cur=0;
        for(int i=0; i<n; i++) {
            if(cur == nums[i] && i != n-1) {
                cur++;
            }
            else if(cur == nums[i] && i == n-1) {
                return cur+1;
            }
            else {
                return cur;
            }
        }
        return -1;
    }
};