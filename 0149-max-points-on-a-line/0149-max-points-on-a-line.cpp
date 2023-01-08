class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      int maxi = 0;
      
      for (auto x : points) {
            map<double, int> slopes;
        
            for (auto y : points) {
                if (x == y) continue;
                double slope = numeric_limits<double>::infinity();
                if (y[0] - x[0] != 0) {
                    slope = (double)(y[1] - x[1]) / (y[0] - x[0]);
                }
                ++slopes[slope];
                maxi = max(maxi, slopes[slope]);
            }
        
      }
      return maxi + 1;
    }
};