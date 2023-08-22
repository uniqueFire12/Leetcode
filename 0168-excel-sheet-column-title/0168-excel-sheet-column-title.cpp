class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        char t;
        
        while(n) {
            n -= 1;
            
            t = 'A' + (n % 26);
            
            res = t + res;
            
            n /= 26;
        }
        
        return res;
    }
};