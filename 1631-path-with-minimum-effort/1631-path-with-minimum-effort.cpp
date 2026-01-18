class Solution {
public:
    int rows, cols;
    // Directions for moving Up, Down, Left, Right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // The Check Function:
    // Returns true if a path exists from (0,0) to (rows-1, cols-1)
    // using ONLY moves with absolute difference <= mid_effort.
    bool check(vector<vector<int>>& heights, int mid_effort) {
        // If start point is destination, effort is 0 (trivial case usually handled by logic)
        
        // BFS Initialization
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        // Visited array to prevent cycles and redundant processing
        // We re-initialize this for every check() call.
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        vis[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // If we reached the bottom-right cell
            if (r == rows - 1 && c == cols - 1) return true;
            
            // Explore 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // 1. Check Bounds
                // 2. Check if already visited
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !vis[nr][nc]) {
                    // 3. The CRITICAL Check:
                    // Is the effort to move to this neighbor within our allowed limit?
                    int current_diff = abs(heights[r][c] - heights[nr][nc]);
                    
                    if (current_diff <= mid_effort) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        // Queue empty and destination not reached
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        
        // 1. Define Search Space
        // lo: Minimum absolute difference is 0
        // hi: Maximum possible difference (10^6 as per constraints, or max-min)
        int lo = 0;
        int hi = 1000000;
        int ans = hi;

        // 2. Binary Search Template (Minimization)
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(heights, mid)) {
                // If it is possible to reach the end with effort <= mid,
                // this is a valid answer. But we want to see if we can do it
                // with even LESS effort.
                ans = mid;
                hi = mid - 1;
            } else {
                // It's impossible to reach the end with this effort limit.
                // The constraint is too tight. We must allow for larger jumps.
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};