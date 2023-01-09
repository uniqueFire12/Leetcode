class Solution {
public:
    int minDeletionSize(vector<string>& str) {
      int rows = str.size(), cols = str[0].size();
      int delColumn = 0;
      for(int j=0; j<cols; j++) {
        for(int i=0; i<rows-1; i++) {
          if(str[i][j] > str[i+1][j]) {
            delColumn++;
            break;
          }
        }
      }
      return delColumn;
    }
};