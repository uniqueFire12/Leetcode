class Solution {
public:
  // memoization solution
    int f(int i, int j, vector<vector<int>>& t, int n, vector<vector<int>> &dp) {
      if(i == n-1) {
        return t[n-1][j];
      }
      if(dp[i][j] != -1) {
        return dp[i][j];
      }
      int down = t[i][j] + f(i+1, j, t, n, dp);
      int diag = t[i][j] + f(i+1, j+1, t, n, dp);
      
      return dp[i][j] = min(down, diag);
    }
  
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      //vector<vector<int>> dp(n, vector<int>(n, 0));
      // return f(0, 0, triangle, n, dp);
      
      
      // tabulation approach
      /*for(int i=0; i<n; i++) {
        dp[n-1][i] = triangle[n-1][i];
      }
      
      for(int i = n-2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
          int down = triangle[i][j] + dp[i+1][j];
          int diag = triangle[i][j] + dp[i+1][j+1];
          dp[i][j] = min(down, diag);
        }
      }
      return dp[0][0];*/
      
      // space optimization
      vector<int> front(n, 0), curr(n, 0);
      for(int i=0; i<n; i++) {
        front[i] = triangle[n-1][i];
      }
      
      for(int i = n-2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
          int down = triangle[i][j] + front[j];
          int diag = triangle[i][j] + front[j+1];
          curr[j] = min(down, diag);
        }
        front = curr;
      }
      return front[0];
    }
};