class Solution {
public:
  
    int dp[102][102][102];
    int mod = 1e9 + 7;
    int solve(int k, int i, int j, int n, int minProfit, vector<int>& group, vector<int>& profit) {
      
      if(k == profit.size()) {
        if(j >= minProfit && n >= i) return 1;
        return 0;
      }
      else if(n < i) return 0;
      
      if(dp[k][i][j] != -1) return dp[k][i][j];
      int take = 0, not_take = 0;
      not_take= solve(k+1,i,j,n,minProfit,group,profit);
      take=solve(k+1,i+group[k],min(j+profit[k],minProfit),n,minProfit,group,profit);
      return  dp[k][i][j] = (take  % mod + not_take  % mod ) % mod;
    }
  
  int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 0,n, minProfit, group, profit);
  }
};