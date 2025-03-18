class Solution {
public:
    vector<vector<int>> vis;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int node_i, int node_j, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vis[node_i][node_j] = 1;

        for (int i = 0; i < 4; i++) {
            int x = node_i + dx[i];
            int y = node_j + dy[i];

            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] == '1') {
                dfs(x, y, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vis.assign(m, vector<int>(n, 0));

        int island_no = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    island_no++;
                    dfs(i, j, grid);
                }
            }
        }
        return island_no;
    }
};
