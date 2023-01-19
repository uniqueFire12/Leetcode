class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      
      int sum = 0;
      int rem = 0;
      int res = 0;
      
      vector<int> hash(k);
      hash[rem]++;
      
      for(int i = 0; i < nums.size(); i++) {
        
        sum += nums[i];
        rem = sum % k;
        
        if(rem < 0) rem += k;
        
        res += hash[rem];
        
        hash[rem]++;
      }
      
      return res;
    }
};