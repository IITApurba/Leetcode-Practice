#include <vector>

using namespace std;

class Solution {
    int mod = 1e9 + 7;
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(goal + 1, vector<long long>(n + 1, -1));
        return rec(goal, n, n, k, dp);
    }

private:
    long long rec(int i, int j, int n, int k, vector<vector<long long>>& dp) {
        if (i == 0) return j == 0 ? 1 : 0;
        if (j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        long long res = (rec(i - 1, j - 1, n, k, dp) * (n - (j - 1))) % mod;
        if (j > k) {
            res = (res + rec(i - 1, j, n, k, dp) * (j - k)) % mod;
        }
        
        return dp[i][j] = res;
    }
};