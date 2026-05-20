#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (size_t k = 0; k < group.size(); k++) {
            int g = group[k];
            int p = profit[k];
            for (int i = n; i >= g; i--) {
                for (int j = minProfit; j >= 0; j--) {
                    dp[i][j] = (dp[i][j] + dp[i - g][max(0, j - p)]) % mod;
                }
            }
        }
        
        return dp[n][minProfit];
    }
};