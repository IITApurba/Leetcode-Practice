class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        vector<int> minX(61, 100), maxX(61, -1), minY(61, 100), maxY(61, -1);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = targetGrid[i][j];
                minX[c] = min(minX[c], i);
                maxX[c] = max(maxX[c], i);
                minY[c] = min(minY[c], j);
                maxY[c] = max(maxY[c], j);
            }
        }
        
        vector<vector<int>> adj(61);
        for (int c = 1; c <= 60; ++c) {
            if (minX[c] > maxX[c]) continue;
            for (int i = minX[c]; i <= maxX[c]; ++i) {
                for (int j = minY[c]; j <= maxY[c]; ++j) {
                    if (targetGrid[i][j] != c) {
                        adj[c].push_back(targetGrid[i][j]);
                    }
                }
            }
        }
        
        vector<int> state(61, 0);
        for (int i = 1; i <= 60; ++i) {
            if (minX[i] <= maxX[i] && hasCycle(i, adj, state)) {
                return false;
            }
        }
        
        return true;
    }
    
private:
    bool hasCycle(int u, vector<vector<int>>& adj, vector<int>& state) {
        if (state[u] == 1) return true;
        if (state[u] == 2) return false;
        
        state[u] = 1;
        for (int v : adj[u]) {
            if (hasCycle(v, adj, state)) return true;
        }
        state[u] = 2;
        
        return false;
    }
};