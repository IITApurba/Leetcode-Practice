class Solution {
    int mod = 1e9 + 7;

    int solve(int n, int a, int l, vector<vector<vector<int>>>& dp) {
        if (n == 0)
            return 1;
        if (dp[n][a][l] != -1)
            return dp[n][a][l];

        long long ans = solve(n - 1, a, 0, dp);
        if (a < 1)
            ans = (ans + solve(n - 1, a + 1, 0, dp)) % mod;
        if (l < 2)
            ans = (ans + solve(n - 1, a, l + 1, dp)) % mod;

        return dp[n][a][l] = ans;
    }

public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0, dp);
    }
};