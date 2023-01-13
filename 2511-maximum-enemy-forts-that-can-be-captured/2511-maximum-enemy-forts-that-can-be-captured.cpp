class Solution {
public:
    int captureForts(vector<int>& forts) {
      
      int n = forts.size();
      int ans = 0, j = 0;
      
      for(int i = 0; i < n; i++) {
        if(forts[i] != 0) {
          if(forts[j] == -forts[i]) ans = max(ans, i-j-1);
          
          j = i;
        }
      }
      
      return ans;
    }
};