class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> inDegree(n, 0);
        vector<int> depth(n, 1);
        
        for (int i = 0; i < n; ++i) {
            inDegree[favorite[i]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int v = favorite[u];
            
            depth[v] = max(depth[v], depth[u] + 1);
            
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
        
        int maxCycleLength = 0;
        int sumOfSmallCycles = 0;
        
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] > 0) {
                int cycleLength = 0;
                int current = i;
                
                while (inDegree[current] > 0) {
                    inDegree[current] = 0;
                    cycleLength++;
                    current = favorite[current];
                }
                
                if (cycleLength == 2) {
                    sumOfSmallCycles += depth[i] + depth[favorite[i]];
                } 
                else {
                    maxCycleLength = max(maxCycleLength, cycleLength);
                }
            }
        }
        
        return max(maxCycleLength, sumOfSmallCycles);
    }
};