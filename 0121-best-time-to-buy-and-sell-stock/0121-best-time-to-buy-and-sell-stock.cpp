class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice= INT_MAX, maxPro = INT_MIN;
        for(int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};