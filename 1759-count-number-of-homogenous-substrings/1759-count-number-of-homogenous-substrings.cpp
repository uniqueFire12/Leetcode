class Solution {
public:
    #define mod 1000000007;
    int countHomogenous(string s) {
        int n = s.size();
        int cnt = 0, ans = 0;
        for(int i=0; i<n; i++) {
            if(i > 0 and s[i-1] == s[i]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            ans = (ans + cnt) % mod;
        }
        
        return ans;
    }
};