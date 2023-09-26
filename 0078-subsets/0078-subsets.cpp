class Solution {
public:
    void allSubsets(int ind, vector<int>& ds, vector<int>& nums, vector<vector<int>> &ans, int n) {
        if(ind >= n) {
            ans.push_back(ds);
            return;
        }
       
        ds.push_back(nums[ind]);
        allSubsets(ind+1, ds, nums, ans, n);
        ds.pop_back();
        allSubsets(ind+1, ds, nums, ans, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        allSubsets(0, temp, nums, ans, n);
        return ans;
    }
};