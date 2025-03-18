class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> vis;
    int ans = 0;

    void dfs(vector<vector<int>>& arr, int node_i, int node_j) {
        if (vis[node_i][node_j] == 1)
            return;

        vis[node_i][node_j] = 1;

        for (int i = 0; i < 4; i++) {
            int x = node_i + dx[i];
            int y = node_j + dy[i];

            if (x < 0 || x >= arr.size() || y < 0 || y >= arr[0].size() || arr[x][y] == 0) {
                ans++;  // Counting perimeter
            } else if (vis[x][y] == 0) {
                dfs(arr, x, y);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        vis.assign(m, vector<int>(n, 0));  // Initialize vis with correct dimensions

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1) { // Start DFS from the first land cell found
                    dfs(arr, i, j);
                    return ans;  // No need to continue after processing one island
                }
            }
        }

        return 0; // If no land is found, return 0
    }
};
