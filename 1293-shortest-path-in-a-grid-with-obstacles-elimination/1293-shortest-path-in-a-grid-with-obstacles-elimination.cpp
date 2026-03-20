class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (k >= m + n - 2) {
            return m + n - 2;
        }
        
        queue<vector<int>> q;
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        q.push({0, 0, k, 0});
        visited[0][0] = k;
        
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int r = curr[0];
            int c = curr[1];
            int rem_k = curr[2];
            int steps = curr[3];
            
            if (r == m - 1 && c == n - 1) {
                return steps;
            }
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_k = rem_k - grid[nr][nc];
                    
                    if (next_k >= 0 && next_k > visited[nr][nc]) {
                        visited[nr][nc] = next_k;
                        q.push({nr, nc, next_k, steps + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};