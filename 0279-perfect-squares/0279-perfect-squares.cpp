class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        int cnt = 1;
        while(cnt*cnt <= n) {
            int sq = cnt * cnt;
            for(int i=sq; i<=n; i++){              
                dp[i] = min(dp[i-sq] + 1, dp[i]);
            }
            cnt++;
        }
        return dp[n];
    }
};