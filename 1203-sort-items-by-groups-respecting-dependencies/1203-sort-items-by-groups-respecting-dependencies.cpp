class Solution {
    vector<int> topoSort(vector<vector<int>>& adj, vector<int>& deg, vector<int>& nodes) {
        queue<int> q;
        for (int node : nodes) {
            if (deg[node] == 0) {
                q.push(node);
            }
        }
        
        vector<int> res;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v : adj[u]) {
                if (--deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return res.size() == nodes.size() ? res : vector<int>();
    }

public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }
        
        vector<vector<int>> itemAdj(n);
        vector<int> itemDeg(n, 0);
        vector<vector<int>> groupAdj(m);
        vector<int> groupDeg(m, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int before : beforeItems[i]) {
                itemAdj[before].push_back(i);
                itemDeg[i]++;
                if (group[i] != group[before]) {
                    groupAdj[group[before]].push_back(group[i]);
                    groupDeg[group[i]]++;
                }
            }
        }
        
        vector<int> allItems(n);
        for (int i = 0; i < n; ++i) allItems[i] = i;
        vector<int> itemOrder = topoSort(itemAdj, itemDeg, allItems);
        if (itemOrder.empty()) return {};
        
        vector<int> allGroups(m);
        for (int i = 0; i < m; ++i) allGroups[i] = i;
        vector<int> groupOrder = topoSort(groupAdj, groupDeg, allGroups);
        if (groupOrder.empty()) return {};
        
        vector<vector<int>> groupedItems(m);
        for (int item : itemOrder) {
            groupedItems[group[item]].push_back(item);
        }
        
        vector<int> ans;
        for (int g : groupOrder) {
            for (int item : groupedItems[g]) {
                ans.push_back(item);
            }
        }
        
        return ans;
    }
};