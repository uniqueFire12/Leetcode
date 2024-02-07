class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> up;
        for(auto it : s) {
            up[it]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto it : up) {
            pq.push({it.second, it.first});
        }
        
        string ans;
        pair<int, char> curr;
        while(!pq.empty()) {
            curr = pq.top();
            pq.pop();
            ans += string(curr.first, curr.second);
            
        }
        return ans;
    }
};