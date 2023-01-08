class Solution {
public:
    int minDeletionSize(vector<string>& str) {
      int ans = 0;
      int row = str.size(), col = str[0].size();
      
      for(int j = 0; j < col; j++) {       
        for(int i = 0; i < row - 1; i++) {         
          if(str[i][j] > str[i+1][j]) {
            ans++;
            break;
          }
        }      
      }
      
      return ans;
      
    }
};