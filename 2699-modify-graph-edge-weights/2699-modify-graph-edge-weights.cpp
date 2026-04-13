class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][2] != -1) {
                adj[edges[i][0]].push_back({edges[i][1], i});
                adj[edges[i][1]].push_back({edges[i][0], i});
            }
        }
        auto dijkstra = [&](int src, int dst, vector<vector<pair<int, int>>>& graph, vector<vector<int>>& edges_ref) {
            vector<long long> dist(n, 1e18);
            dist[src] = 0;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            pq.push({0, src});
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist[u]) continue;
                for (auto& [v, idx] : graph[u]) {
                    int weight = edges_ref[idx][2];
                    if (weight == -1) continue;
                    if (dist[v] > dist[u] + weight) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist[dst];
        };
        long long initial_dist = dijkstra(source, destination, adj, edges);
        if (initial_dist < target) return {};
        bool matched = (initial_dist == target);
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][2] == -1) {
                edges[i][2] = matched ? 2e9 : 1;
                adj[edges[i][0]].push_back({edges[i][1], i});
                adj[edges[i][1]].push_back({edges[i][0], i});
                if (!matched) {
                    long long new_dist = dijkstra(source, destination, adj, edges);
                    if (new_dist <= target) {
                        edges[i][2] += target - new_dist;
                        matched = true;
                    }
                }
            }
        }
        if (!matched) return {};
        return edges;
    }
};