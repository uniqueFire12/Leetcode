class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char, int> um;
        priority_queue<pair<int, char>> pq;
        
        for(auto it : s) um[it]++;
        
        for(auto it : um) pq.push(make_pair(it.second, it.first));
        
        while(pq.size() > 1) {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            
            ans += top1.second;
            ans += top2.second;
            
            top1.first -= 1;
            top2.first -= 1;
            
            if(top1.first > 0) 
                pq.push(top1);
            if(top2.first > 0) 
                pq.push(top2);            
        }
        
        if(!pq.empty()) {
            if(pq.top().first > 1) 
                return "";
            else 
                ans += pq.top().second;
        }
        
        return ans;
    }
};