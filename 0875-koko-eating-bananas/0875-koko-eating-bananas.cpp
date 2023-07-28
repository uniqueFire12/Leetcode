class Solution {
public:
    double cal(vector<int>& piles, int hourly) {
       int n = piles.size();
       double totalhours = 0;
        for(int i = 0; i < n; i++) {
            totalhours += ceil((double)piles[i] / (double)hourly);
        }
        return totalhours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low <= high) {
            int mid = low + (high - low) / 2;
            double totalHours = cal(piles, mid);
            if(totalHours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};