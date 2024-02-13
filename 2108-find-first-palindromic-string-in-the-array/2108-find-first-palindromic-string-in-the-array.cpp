class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(auto it : words) {
            if(isPalindrome(it)) {
                return it;
            }
        }
        return "";
    }
    
    bool isPalindrome(string s) {
        if(s.size() == 1) return true;
        int j = s.size() - 1;
        bool flag = 0;
        for(int i=0; i<s.size()/2; i++) {
            if(s[i] == s[j]) {
                flag = 1;
                j--;
                continue;
            } else {
                flag = 0;
                break;
            }
        }
        
        if(flag == 1) return true;
        return false;
    }
};