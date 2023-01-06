class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      sort(costs.begin(), costs.end());
      int n = costs.size();
      int sum = 0, cnt = 0;
      for(int i=0; i<n; i++) {
        sum += costs[i];
        cnt++;
        if(sum > coins) {
          sum -= costs[i];
          cnt--;
          continue;
        }
      }
      return cnt;
    }
};