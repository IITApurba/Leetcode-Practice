class Solution {
    void dfs(int u, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[u] = true;
        for (int v : rooms[u]) {
            if (!visited[v]) {
                dfs(v, rooms, visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, rooms, visited);
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};