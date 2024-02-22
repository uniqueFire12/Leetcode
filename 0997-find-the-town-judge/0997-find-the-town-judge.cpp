class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 and n == 1) return 1;
        
        vector<int> cnt(n+1);
        for(auto it : trust) {
            cnt[it[0]]--;
            cnt[it[1]]++;
        }
        
        for(int i = 0; i < cnt.size(); i++) {
            if(cnt[i] == n-1) return i;
        }
        
        return -1;
    }
};