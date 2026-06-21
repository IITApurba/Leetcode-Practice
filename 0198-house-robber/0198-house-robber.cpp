class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        // Use O(1) space instead of O(n) dp array
        // since we only need the previous two values
        int prev2 = nums[0];                  // dp[0]
        int prev1 = max(nums[0], nums[1]);    // dp[1]

        for (int i = 2; i < n; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};