class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfitCal = 0;

        for(int i = 0; i < prices.size(); i++) {
            int cost = prices[i] - mini;
            maxProfitCal = max(maxProfitCal, cost);
            mini = min(mini, prices[i]);
        }

        return maxProfitCal;
    }
};