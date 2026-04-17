class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        int maxCycle = -1;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_map<int, int> dist;
                int curr = i;
                int distance = 0;
                
                while (curr != -1 && !visited[curr]) {
                    visited[curr] = true;
                    dist[curr] = distance++;
                    curr = edges[curr];
                }
                
                if (curr != -1 && dist.count(curr)) {
                    maxCycle = max(maxCycle, distance - dist[curr]);
                }
            }
        }
        return maxCycle;
    }
};