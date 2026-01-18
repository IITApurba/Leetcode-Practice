class Solution {
public:
    // The Check Function:
    // Returns true if we can split 'nums' into <= k subarrays
    // such that NO subarray sum exceeds 'maxSum'.
    bool check(vector<int>& nums, int k, int maxSum) {
        int splits = 1;        // Start with 1 subarray
        int currentSum = 0;
        
        for (int x : nums) {
            // Greedy: Try to add x to the current subarray
            if (currentSum + x <= maxSum) {
                currentSum += x;
            } else {
                // If adding x exceeds limit, we MUST start a new subarray
                splits++;
                currentSum = x; // Start new subarray with x
            }
        }
        
        // If we used k or fewer splits, this maxSum is feasible (True)
        return splits <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        // 1. Define the search range [lo, hi]
        int maxVal = 0;
        long long sumVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
            sumVal += x;
        }

        // lo cannot be less than the largest element (since that element must fit in a subarray)
        // hi is the sum of all elements (worst case: k=1)
        long long lo = maxVal;
        long long hi = sumVal;
        long long ans = hi;

        // 2. Binary Search Template
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (check(nums, k, mid)) {
                // If mid is valid, it might be the answer, 
                // but we want to minimize it, so try smaller values (left side).
                ans = mid;
                hi = mid - 1;
            } else {
                // If mid is invalid (splits > k), it means our capacity (mid) is too small.
                // We need to increase the capacity.
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};