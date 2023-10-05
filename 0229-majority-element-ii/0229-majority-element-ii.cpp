class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        vector<int> ans;
        int n = nums.size();
        for(auto it: nums) {
            mpp[it]++;
        }
        
        for(auto it : mpp) {
            if(it.second > n/3) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};