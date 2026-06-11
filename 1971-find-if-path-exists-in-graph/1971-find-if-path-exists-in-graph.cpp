class Solution {
    bool dfs(int curr, int destination, vector<vector<int>>& adj, vector<bool>& visited) {
        if (curr == destination) return true;
        visited[curr] = true;
        for (int next : adj[curr]) {
            if (!visited[next]) {
                if (dfs(next, destination, adj, visited)) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(source, destination, adj, visited);
    }
};