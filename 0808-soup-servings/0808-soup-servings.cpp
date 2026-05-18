class Solution {
    double dp[200][200];

public:
    double soupServings(int n) {
        if (n >= 4800)
            return 1.0;
        n = (n + 24) / 25;
        memset(dp, 0, sizeof(dp));
        return rec(n, n);
    }

    double rec(int a, int b) {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;
        if (dp[a][b] > 0)
            return dp[a][b];
        return dp[a][b] = 0.25 * (rec(a - 4, b) + rec(a - 3, b - 1) +
                                  rec(a - 2, b - 2) + rec(a - 1, b - 3));
    }
};