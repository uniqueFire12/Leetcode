class Solution {
public:
    void solve(int node, vector<int> adjLs[], vector<int> &vis) {
        vis[node] = 1;
        for(auto it : adjLs[node]) {
            if(!vis[it]) {
                solve(it, adjLs, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int ans = 0;
        int n = adj.size();
        vector<int> visited(n+1, 0);
        
        // to change adjacency matrix to list
        vector<int> adjLs[n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                ans++;
                solve(i, adjLs, visited);
            }
        }
        
        return ans;
    }
};