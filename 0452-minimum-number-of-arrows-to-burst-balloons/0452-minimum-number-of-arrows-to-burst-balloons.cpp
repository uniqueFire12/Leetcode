class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
      sort(p.begin(), p.end());
      
      int res=1;
      int last = p[0][1];
      
      for(auto it : p) {
        
        if(it[0] > last) {
          res++;
          last = it[1];
        }
        
        last = min(it[1], last);
      }
      
      return res;
    }
};