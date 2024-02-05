class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        map<char, int> mpp;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
        }
        
        for(int i=0; i<n; i++) {
            if(mpp[s[i]] == 1) {
                ans = i;
                return ans;
            }
        }
        
        return -1;
    }
};