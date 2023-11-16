class Solution {
public:
    long atoi(int len, string s, int sign, int i, long num) {
        // 3 base-cases
        if(sign*num >= INT_MAX) return INT_MAX;
        if(sign*num <= INT_MIN) return INT_MIN;
        if(i >= len or s[i] < '0' or s[i] > '9') {
            return sign*num; 
        }
        
        num = atoi(len, s, sign, i+1, (num*10 + (s[i] - '0')));
        return num;
    }
    
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        int i = 0;
        while(s[i] == ' ') i++;
        
        if(s[i] == '+') {
            i++;
        }
        else if(s[i] == '-') {
            sign = -1;
            i++;
        }
        
        return atoi(n, s, sign, i, 0);
    }
};