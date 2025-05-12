class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int rec(int i, int j, vector<vector<int>>& triangle) {
        if (i == n - 1)
            return triangle[i][j]; // Base case: bottom row

        if (dp[i][j] != -1)
            return dp[i][j]; // Use memo if already computed

        int down = rec(i + 1, j, triangle);
        int diagonal = rec(i + 1, j + 1, triangle);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        dp.assign(n, vector<int>(n, -1));
        return rec(0, 0, triangle);
    }
};
