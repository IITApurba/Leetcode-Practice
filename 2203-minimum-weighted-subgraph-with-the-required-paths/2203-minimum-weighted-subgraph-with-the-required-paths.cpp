class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> adj(n), rev_adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            rev_adj[e[1]].push_back({e[0], e[2]});
        }
        auto dijkstra = [&](int start, vector<vector<pair<int, int>>>& graph) {
            vector<long long> dist(n, 1e18);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            dist[start] = 0;
            pq.push({0, start});
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist[u]) continue;
                for (auto& [v, w] : graph[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        };
        vector<long long> d1 = dijkstra(src1, adj);
        vector<long long> d2 = dijkstra(src2, adj);
        vector<long long> d3 = dijkstra(dest, rev_adj);
        long long ans = 1e18;
        for (int i = 0; i < n; ++i) {
            if (d1[i] != 1e18 && d2[i] != 1e18 && d3[i] != 1e18) {
                ans = min(ans, d1[i] + d2[i] + d3[i]);
            }
        }
        return ans == 1e18 ? -1 : ans;
    }
};