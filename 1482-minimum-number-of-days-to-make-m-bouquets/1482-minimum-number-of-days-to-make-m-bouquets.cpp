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
        // if(n < m*k) return -1;
        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int mn = *min_element(bloomDay.begin(), bloomDay.end());
        int low = mn, high = mx;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        if(ans!= 0) return ans;
        else return -1;
    }
};