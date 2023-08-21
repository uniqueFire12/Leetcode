class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntFresh = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                
                if(grid[i][j] == 1) cntFresh++;
            }
        }
        int time = 0;
        int cnt = 0;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            
            for(int i=0; i<4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        
        if(cntFresh != cnt) return -1;
        
        return time;
    }
};