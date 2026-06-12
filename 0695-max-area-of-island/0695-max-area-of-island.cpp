class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();

        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0; // mark visited

        return 1 +
               dfs(grid, r + 1, c) +
               dfs(grid, r - 1, c) +
               dfs(grid, r, c + 1) +
               dfs(grid, r, c - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};