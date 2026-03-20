class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;
        
        int target_mask = (1 << n) - 1;
        queue<vector<int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i, 0});
            visited[i][1 << i] = true;
        }
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int node = curr[0];
            int mask = curr[1];
            int dist = curr[2];
            
            for (int neighbor : graph[node]) {
                int next_mask = mask | (1 << neighbor);
                
                if (next_mask == target_mask) {
                    return dist + 1;
                }
                
                if (!visited[neighbor][next_mask]) {
                    visited[neighbor][next_mask] = true;
                    q.push({neighbor, next_mask, dist + 1});
                }
            }
        }
        
        return 0;
    }
};