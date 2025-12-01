class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        // Use O(1) space instead of O(n) dp array
        // since we only need the previous two values
        int prev2 = 1;  // dp[1]
        int prev1 = 2;  // dp[2]

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};