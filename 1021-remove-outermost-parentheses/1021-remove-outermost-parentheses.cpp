class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";
        
        for(auto it : s) {
            
            if(it == '(') {
                if(count > 0) {
                    ans += it;
                }
                count++;
            }
            else {
                if(count > 1) {
                    ans += it;
                }
                count--;
            }
        }
        
        return ans;
    }
};