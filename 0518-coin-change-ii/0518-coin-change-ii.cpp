class Solution {
public:
    
    int changeCoins(int n, int amount, vector<int>& coins, vector<vector<int>> &dp) {
        if(n == 0) return 0;
        
        if(amount == 0) return 1;
        
        if(dp[n][amount] != -1) return dp[n][amount];
        
        if(coins[n-1] > amount) {
            dp[n][amount] = changeCoins(n-1, amount, coins, dp);
            return dp[n][amount];
        }
        
        dp[n][amount] = changeCoins(n, amount-coins[n-1], coins, dp) + changeCoins(n-1, amount, coins, dp);
        
        return dp[n][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        if(amount == 0) return 1;
        if(n == 0) return 0;
        
        vector<vector<int>> dp;
        
        dp.resize(n+2, vector<int>(amount + 2, -1));
        
        dp[n][amount] = changeCoins(n, amount, coins, dp);
        
        return dp[n][amount];
    }
};