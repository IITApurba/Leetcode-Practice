class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        int res[50][50][3], degree[50][50][3];
        memset(res, 0, sizeof(res));
        memset(degree, 0, sizeof(degree));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                degree[i][j][1] = graph[i].size();
                degree[i][j][2] = graph[j].size();
                for (int next : graph[j]) if (next == 0) { degree[i][j][2]--; break; }
            }
        }
        queue<vector<int>> q;
        for (int i = 1; i < n; i++) {
            res[0][i][1] = res[0][i][2] = 1; q.push({0, i, 1, 1}); q.push({0, i, 2, 1});
            res[i][i][1] = res[i][i][2] = 2; q.push({i, i, 1, 2}); q.push({i, i, 2, 2});
        }
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int m = curr[0], c = curr[1], t = curr[2], v = curr[3];
            int prev_t = 3 - t;
            for (int prev_node : (prev_t == 1 ? graph[m] : graph[c])) {
                int pm = (prev_t == 1) ? prev_node : m, pc = (prev_t == 2) ? prev_node : c;
                if (pc == 0 || res[pm][pc][prev_t]) continue;
                if (v == prev_t || --degree[pm][pc][prev_t] == 0) {
                    res[pm][pc][prev_t] = v;
                    q.push({pm, pc, prev_t, v});
                }
            }
        }
        return res[1][2][1];
    }
};