class Solution {
public:
  
    void findCombination(int ind, int target, vector<int> &a, vector<vector<int>> &ans, vector<int> &ds) {
      
      if(ind == a.size()) {
        if(target == 0) {
          ans.push_back(ds);
        }
        return;
      }
      
      if(a[ind] <= target) {
        ds.push_back(a[ind]);
        findCombination(ind, target - a[ind], a, ans, ds);
        ds.pop_back();
      }
      
      findCombination(ind + 1, target, a, ans, ds);
      
    }
  
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
      vector<vector<int>> ans;
      vector<int> ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
      
    }
  
};