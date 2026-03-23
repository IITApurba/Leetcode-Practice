class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 1) q.push({i, j});

        if (q.empty() || q.size() == n * n) return -1;

        int dist = -1;
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while (!q.empty()) {
            int size = q.size();
            dist++;
            while (size--) {
                auto [r, c] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return dist;
    }
};