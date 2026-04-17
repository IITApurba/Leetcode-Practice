class Solution {
    vector<vector<int>> adj;
    vector<int> count, res;
    int n;

    void dfs1(int node, int parent) {
        for (int child : adj[node]) {
            if (child != parent) {
                dfs1(child, node);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent) {
        for (int child : adj[node]) {
            if (child != parent) {
                res[child] = res[node] - count[child] + (n - count[child]);
                dfs2(child, node);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        count.assign(n, 1);
        res.assign(n, 0);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }
};