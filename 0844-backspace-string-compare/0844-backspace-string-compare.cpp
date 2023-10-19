class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> s1, s2;
        string a1, a2;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#' and !s1.empty()) {
                s1.pop();
            }
            else if(s[i] != '#') {
                s1.push(s[i]);
            }
        }
        
        for(int i = 0; i < t.size(); i++) {
            if(t[i] == '#' and !s2.empty()) {
                s2.pop();
            }
            else if(t[i] != '#') {
                s2.push(t[i]);
            }
        }
        
        while(!s1.empty()) {
            char ch = s1.top();
            s1.pop();
            a1 += ch;
        }
        
        while(!s2.empty()) {
            char ch = s2.top();
            s2.pop();
            a2 += ch;
        }
        
        return a1 == a2;     
    }
};