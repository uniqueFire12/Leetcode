class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        if(n == 1) return {-1};
        int maxi = 0;
        for(int i = n-1; i > 0; i--) {
            maxi = max(maxi, arr[i]);
            res.push_back(maxi);
        }
        reverse(res.begin(), res.end());
        res.push_back(-1);
        return res;
    }
};