#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> inDegree(n, 0);
        vector<int> depth(n, 1);
        
        // Step 1: Calculate in-degrees
        for (int i = 0; i < n; ++i) {
            inDegree[favorite[i]]++;
        }
        
        // Step 2: Topological Sort (Kahn's Algorithm) to process non-cycle nodes (chains)
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
            
            // The depth of the target node is max of its current depth or the chain leading to it + 1
            depth[v] = max(depth[v], depth[u] + 1);
            
            // Decrease in-degree and push to queue if it becomes 0
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
        
        // Step 3: Cycle Detection & Processing
        int maxCycleLength = 0;
        int sumOfSmallCycles = 0; // Sum of length-2 cycles + their attached chains
        
        for (int i = 0; i < n; ++i) {
            // If inDegree > 0, the node is part of a cycle
            if (inDegree[i] > 0) {
                int cycleLength = 0;
                int current = i;
                
                // Traverse the cycle to find its length
                while (inDegree[current] > 0) {
                    inDegree[current] = 0; // Mark as visited
                    cycleLength++;
                    current = favorite[current];
                }
                
                // Case A: Cycle of length 2
                // We can take the mutual pair PLUS the longest chains leading into both of them.
                // We can also seat multiple length-2 configurations at the same table.
                if (cycleLength == 2) {
                    sumOfSmallCycles += depth[i] + depth[favorite[i]];
                } 
                // Case B: Cycle of length > 2
                // We can only seat this specific cycle at the table.
                else {
                    maxCycleLength = max(maxCycleLength, cycleLength);
                }
            }
        }
        
        // The answer is the maximum of seating one large cycle, or combining all length-2 configurations
        return max(maxCycleLength, sumOfSmallCycles);
    }
};