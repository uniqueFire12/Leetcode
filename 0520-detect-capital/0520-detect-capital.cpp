class Solution {
public:
    bool detectCapitalUse(string word) {
        int up=0, lo=0;
        int n = word.size();
        for(int i=0; i<n; i++) {
          if(isupper(word[i])) {
            up++;
          } else {
            lo++;
          }
        }
      
      if(up == n || lo == n || (isupper(word[0]) && up == 1)) 
        return true;
      return false;
    }
};