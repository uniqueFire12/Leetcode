class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        double num = 0;
        int i = 0;
        while(s[i] == ' ') {
            i++;
        }
        bool pos = s[i] == '+';
        bool neg = s[i] == '-';
        pos == true ? i++ : i;
        neg == true ? i++ : i;
        while(i < len and s[i] >= '0' and s[i] <= '9') {
            num = num*10 + (s[i] - '0');
            i++;
        }
        num = neg ? -num : num;
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;
        return (int)num;
    }
};