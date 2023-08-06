class Solution {
private:
    void dfs(int n, int m, int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int initialColor, int delRow[], int delCol[]) {
        ans[row][col] = newColor;
        for(int i=0; i<4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and image[nrow][ncol] == initialColor and ans[nrow][ncol] != newColor) {
                dfs(n, m,  nrow, ncol, ans, image, newColor, initialColor, delRow, delCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(n, m, sr, sc, ans, image, newColor, initialColor, delRow, delCol);
        return ans;
    }
};