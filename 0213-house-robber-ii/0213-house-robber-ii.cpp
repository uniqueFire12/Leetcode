class Solution {
public:
   int maxMoney(vector<int>& nums) {
      int n = nums.size();
      int prev = nums[0], prev2 = 0;
      
      for(int i=1; i<n; i++) {
        int take = nums[i];
        if(i > 1) take += prev2;
        int nottake = 0 + prev;
        
        int curi = max(take, nottake);
        prev2 = prev;
        prev = curi;
      }
      return prev;
    }
  
    int rob(vector<int>& nums) {
      vector<int> t1, t2;
      int n = nums.size();
      if(n == 1) return nums[0];
      for(int i=0; i<n; i++) {
        if(i != 0) t1.push_back(nums[i]);
        if(i != n-1) t2.push_back(nums[i]);
      }
      int ans1 = maxMoney(t1);
      int ans2 = maxMoney(t2);
      return max(ans1, ans2);
    }
};