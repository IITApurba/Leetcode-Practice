class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (auto& flight : flights) {
                if (dist[flight[0]] != 1e9) {
                    temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            dist = temp;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};