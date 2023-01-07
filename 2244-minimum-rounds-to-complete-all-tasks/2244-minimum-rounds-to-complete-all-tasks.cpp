class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        int i;
        map<int,int> m;
        for(i=0;i<tasks.size();i++) {
            m[tasks[i]]++;
        }
        
        int c=0;
        
        for (auto freq : m){
            if(freq.second == 1)
                return -1;
            if(freq.second %3 == 0){
                c += freq.second / 3;
            }
            else{
                c += freq.second / 3 + 1;
            }
        }
        return c;
    }
};