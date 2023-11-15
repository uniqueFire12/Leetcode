class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char> vowel;
        vector<int> pos;
        
        for(int i=0; i<n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowel.push_back(s[i]);
                pos.push_back(i);
            }
        }
        
        sort(vowel.begin(), vowel.end());
        string ans = s;
        for(int i=0; i<pos.size(); i++) {
            ans[pos[i]] = vowel[i];
        }
        
        return ans;
    }
};