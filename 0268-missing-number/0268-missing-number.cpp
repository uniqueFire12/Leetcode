class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        map<int, int> mpp;
        for(auto it : nums) {
            mpp[it]++;
        }
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(mpp.find(i) == mpp.end()) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};