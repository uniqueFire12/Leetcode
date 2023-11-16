class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for(int i=0; i<n; i++) {
            char curr = nums[i][i];
            char opposite = (curr == '0') ? '1' : '0';
            
            ans += opposite;
        }
        return ans;
    }
};