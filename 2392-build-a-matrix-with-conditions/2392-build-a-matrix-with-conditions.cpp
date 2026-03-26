#include <vector>
#include <queue>

using namespace std;

class Solution {
    vector<int> topoSort(int k, vector<vector<int>>& edges) {
        vector<vector<int>> adj(k + 1);
        vector<int> inDegree(k + 1, 0);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }
        
        vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            
            for (int v : adj[u]) {
                if (--inDegree[v] == 0) q.push(v);
            }
        }
        
        return order.size() == k ? order : vector<int>();
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topoSort(k, rowConditions);
        vector<int> colOrder = topoSort(k, colConditions);
        
        if (rowOrder.empty() || colOrder.empty()) return {};
        
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        vector<int> rowMap(k + 1), colMap(k + 1);
        
        for (int i = 0; i < k; ++i) {
            rowMap[rowOrder[i]] = i;
            colMap[colOrder[i]] = i;
        }
        
        for (int i = 1; i <= k; ++i) {
            matrix[rowMap[i]][colMap[i]] = i;
        }
        
        return matrix;
    }
};