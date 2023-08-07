class Solution {
public:
    bool check(int i, int n, string &ans) {
        if(i>=n/2) return true;
        if(ans[i] != ans[n-i-1]) return false;
        return check(i+1, n, ans);
    }
    
    bool isPalindrome(string s) {
        string ans;
        for(int i=0; i<s.size(); i++) {
            if(isalnum(s[i])) {
                ans += tolower(s[i]);
            }
        }
        int n = ans.size();
        return check(0, n, ans);
    }
};