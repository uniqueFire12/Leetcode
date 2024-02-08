class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128, 0);
        for(auto it : t) mp[it]++;
        int begin=0, end=0, d=INT_MAX, head=0;
        int counter=t.size();
        while(end < s.size()) {
            if(mp[s[end++]]-- > 0) counter--;
            
            while(counter == 0) {
                if(end-begin < d) d=end-(head=begin);
                if(mp[s[begin++]]++ == 0) counter++;
            }
        }
        return d==INT_MAX ? "" : s.substr(head, d);
    }
};