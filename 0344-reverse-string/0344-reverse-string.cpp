class Solution {
public:
    void reverseString(vector<char>& s) {
      int len = s.size();
      char t;
      for(int i = 0; i < s.size()/2; i++) {
        t = s[i];
        s[i] = s[len-1];
        s[len-1] = t;
        len--;
      }
      
    }
};