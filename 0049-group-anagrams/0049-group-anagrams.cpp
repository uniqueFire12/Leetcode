class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> up;
        for(string st : strs) {
            string t = st;
            sort(t.begin(), t.end());
            up[t].push_back(st);
        }
        
        for(auto it : up) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};