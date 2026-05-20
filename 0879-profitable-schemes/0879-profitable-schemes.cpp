#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int mod = 1e9 + 7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(group.size(), vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return rec(0, n, minProfit, group, profit, dp);
    }

private:
    int rec(int i, int n, int p, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp) {
        if (i == group.size()) return p == 0 ? 1 : 0;
        if (dp[i][n][p] != -1) return dp[i][n][p];
        
        int res = rec(i + 1, n, p, group, profit, dp);
        if (n >= group[i]) {
            res = (res + rec(i + 1, n - group[i], max(0, p - profit[i]), group, profit, dp)) % mod;
        }
        
        return dp[i][n][p] = res;
    }
};