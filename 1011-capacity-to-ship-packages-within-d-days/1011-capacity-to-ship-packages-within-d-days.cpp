class Solution {
public:
    int calDays(vector<int>& weights, int capacity) {
        int load = 0, days = 1;
        int n = weights.size();
        
        for(int i = 0; i < n; i++) {
            if(load + weights[i] > capacity) {
                days++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int n = weights.size();
        int mx = *max_element(weights.begin(), weights.end());
        for(auto it : weights) {
            sum += it;
        }
        
        int low = mx, high = sum;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int requiredDays = calDays(weights, mid); 
            if(requiredDays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};