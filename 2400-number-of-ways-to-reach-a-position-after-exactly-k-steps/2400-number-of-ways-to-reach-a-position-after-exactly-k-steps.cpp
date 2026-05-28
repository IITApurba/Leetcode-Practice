#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int diff = std::abs(startPos - endPos);
        if (diff > k || (k - diff) % 2 != 0) return 0;
        int target = (k + diff) / 2;
        int mod = 1e9 + 7;
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(target + 1, 0));
        for (int i = 0; i <= k; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= std::min(i, target); ++j) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            }
        }
        return dp[k][target];
    }
};