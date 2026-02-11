class Solution {
public:
    // Simplified iterative O(m*n) approach without DFS recursion overhead
    int islandPerimeter(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        int perimeter = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1) {
                    // Each land cell contributes 4 sides
                    perimeter += 4;
                    
                    // Subtract 2 for each adjacent land cell (shared edge)
                    // Only check right and down to avoid double counting
                    if (i + 1 < m && arr[i + 1][j] == 1) {
                        perimeter -= 2;  // shared edge with cell below
                    }
                    if (j + 1 < n && arr[i][j + 1] == 1) {
                        perimeter -= 2;  // shared edge with cell to the right
                    }
                }
            }
        }
        
        return perimeter;
    }
};
