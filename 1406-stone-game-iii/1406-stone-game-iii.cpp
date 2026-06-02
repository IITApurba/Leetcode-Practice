class Solution {
public:
    vector<int> dp;
    int n;

    int solve(int i, vector<int>& stoneValue) {
        if (i >= n) return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int sum = 0;
        int ans = INT_MIN;

        for (int k = 1; k <= 3 && i + k - 1 < n; k++) {
            sum += stoneValue[i + k - 1];
            ans = max(ans, sum - solve(i + k, stoneValue));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int diff = solve(0, stoneValue);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};