class Solution {
public:
    void dfs(int n, int m, int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int delRow[], int delCol[], int initialColor, int newColor) {
        ans[row][col] = newColor;
        
        for(int i=0; i<4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor) {
                dfs(n, m, nrow, ncol, image, ans, delRow, delCol, initialColor, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(n, m, sr, sc, image, ans, delRow, delCol, initialColor, newColor);
        return ans;
    }
};