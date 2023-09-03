class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;
        
        for(auto it: s) {
            if(it == '(') {
                if(st.size() > 0) {
                    ans += it;
                }
                st.push(it);
            }
            else {
                if(st.size() > 1) {
                    ans += it;
                }
                st.pop();
            }
        }
        
        return ans;
    }
};