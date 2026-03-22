class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0), candA, candB;
        
        for (auto& edge : edges) {
            if (parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        for (auto& edge : edges) {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1];
            int pu = find(parent, u), pv = find(parent, v);
            
            if (pu == pv) {
                if (candA.empty()) return edge;
                return candA;
            }
            parent[pv] = pu;
        }
        
        return candB;
    }
    
private:
    int find(vector<int>& parent, int f) {
        if (f != parent[f]) {
            parent[f] = find(parent, parent[f]);
        }
        return parent[f];
    }
};