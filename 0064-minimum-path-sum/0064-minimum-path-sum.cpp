class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
      if(i == 0 && j == 0) return grid[0][0];
      if(i < 0 || j < 0) return 1e9;
      if(dp[i][j] != -1) return dp[i][j];
      int up =  grid[i][j] + f(i-1, j, grid, dp);
      int left = grid[i][j] + f(i, j-1, grid, dp);
      
      return dp[i][j] = min(up, left);
    }
  
    int minPathSum(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      //vector<vector<int>> dp(n, vector<int>(m, 0));
      // return f(n-1, m-1, grid, dp);
      
      // space optimization approach
      vector<int> prev(m, 0);
      for(int i=0; i<n; i++) {
        vector<int> curr(m, 0);
        for(int j=0; j<m; j++) {
          if(i == 0 && j == 0) curr[j] = grid[0][0];
          else {
            int up = grid[i][j];
            if(i > 0) up += prev[j];
            else up += 1e9;
            int left = grid[i][j];
            if(j > 0) left += curr[j-1];
            else left += 1e9;
            
            curr[j] = min(up, left);
          }
        }
        prev = curr;
      }
      return prev[m-1];
    }
};