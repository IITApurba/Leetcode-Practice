class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalKeys = 0;
        int startR = -1, startC = -1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '@') {
                    startR = i;
                    startC = j;
                } else if (c >= 'a' && c <= 'f') {
                    totalKeys++;
                }
            }
        }
        
        int targetMask = (1 << totalKeys) - 1;
        queue<vector<int>> q;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(64, false)));
        
        q.push({startR, startC, 0, 0});
        visited[startR][startC][0] = true;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int r = curr[0];
            int c = curr[1];
            int mask = curr[2];
            int steps = curr[3];
            
            if (mask == targetMask) {
                return steps;
            }
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != '#') {
                    char cell = grid[nr][nc];
                    int nextMask = mask;
                    
                    if (cell >= 'a' && cell <= 'f') {
                        nextMask |= (1 << (cell - 'a'));
                    }
                    
                    if (cell >= 'A' && cell <= 'F' && !(nextMask & (1 << (cell - 'A')))) {
                        continue;
                    }
                    
                    if (!visited[nr][nc][nextMask]) {
                        visited[nr][nc][nextMask] = true;
                        q.push({nr, nc, nextMask, steps + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};