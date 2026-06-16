#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_oranges = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }
        
        if (fresh_oranges == 0) return 0;
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty() && fresh_oranges > 0) {
            int q_size = q.size();
            
            for (int i = 0; i < q_size; ++i) {
                auto [row, col] = q.front();
                q.pop();
                
                for (auto dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;
                    
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        fresh_oranges--;
                        q.push({newRow, newCol});
                    }
                }
            }
            minutes++;
        }
        
        if (fresh_oranges > 0) {
            return -1;
        }
        
        return minutes;
    }
};