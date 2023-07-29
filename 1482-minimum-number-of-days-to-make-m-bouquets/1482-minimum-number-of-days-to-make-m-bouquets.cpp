class Solution {
public:
    bool possible(vector<int>& bloomDay, int currentDay, int m, int k) {
        int n = bloomDay.size();
        int count = 0, ans = 0;
        for(int i=0; i<n; i++) {
            if(bloomDay[i] <= currentDay) {
                count++;
            } else {
                ans += (count/k);
                count = 0;
            }
        }
        ans += (count/k);
        if(ans >= m) return true;
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = (long long) m * (long long) k;
        if(n < val) return -1;
        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int mn = *min_element(bloomDay.begin(), bloomDay.end());
        int low = mn, high = mx;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};