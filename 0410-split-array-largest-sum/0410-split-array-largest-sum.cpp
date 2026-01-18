class Solution {
public:
    bool check(vector<int>& nums, int k, int maxSum) {
        int splits = 1;
        int currentSum = 0;

        for (int x : nums) {
            if (currentSum + x <= maxSum) {
                currentSum += x;
            } else {
                splits++;
                currentSum = x;
            }
        }
        return splits <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int maxVal = 0;
        long long sumVal = 0;

        for (int x : nums) {
            maxVal = max(maxVal, x);
            sumVal += x;
        }

        long long lo = maxVal;
        long long hi = sumVal;
        long long ans = hi;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(nums, k, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
