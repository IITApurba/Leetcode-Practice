int dp[105][2];
class Solution {
public:
    int rec(vector<int>& a, int i, int prevRob, int end) {
        if (i > end)
            return 0;

        if (dp[i][prevRob] != -1)
            return dp[i][prevRob];

        int ans = 0;

        if (prevRob == 1) {
            ans = rec(a, i + 1, 0, end);
        } else {
            int rob = a[i] + rec(a, i + 1, 1, end);
            int skip = rec(a, i + 1, 0, end);
            ans = max(rob, skip);
        }

        return dp[i][prevRob] = ans;
    }
    int rob(vector<int>& a) {

        int n = a.size();

        if (n == 1)
            return a[0];

        memset(dp, -1, sizeof(dp));
        int option1 = rec(a, 0, 0, n - 2);

        memset(dp, -1, sizeof(dp));
        int option2 = rec(a, 1, 0, n - 1);

        return max(option1, option2);
    }
};