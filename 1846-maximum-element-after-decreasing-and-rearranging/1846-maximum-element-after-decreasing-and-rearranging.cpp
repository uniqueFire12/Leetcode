class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(auto it : arr) {
            ans = min(ans+1, it);
        }
        return ans;
    }
};