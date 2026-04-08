class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dist[0][0] = 0;
        int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
        while (!dq.empty()) {
            auto [r, c] = dq.front(); dq.pop_front();
            if (r == m - 1 && c == n - 1) return dist[r][c];
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                int cost = (grid[r][c] != i + 1);
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[r][c] + cost < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + cost;
                    if (cost == 1) dq.push_back({nr, nc});
                    else dq.push_front({nr, nc});
                }
            }
        }
        return dist[m-1][n-1];
    }
};