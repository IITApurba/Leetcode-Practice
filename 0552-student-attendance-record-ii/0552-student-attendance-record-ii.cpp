class Solution {
    int mod = 1e9 + 7;
    
    int solve(int n, int a, int l, vector<vector<vector<int>>>& memo) {
        if (n == 0) return 1;
        if (memo[n][a][l] != -1) return memo[n][a][l];

        long long ans = solve(n - 1, a, 0, memo); 
        if (a < 1) ans = (ans + solve(n - 1, a + 1, 0, memo)) % mod;
        if (l < 2) ans = (ans + solve(n - 1, a, l + 1, memo)) % mod;

        return memo[n][a][l] = ans;
    }

public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0, memo);
    }
};