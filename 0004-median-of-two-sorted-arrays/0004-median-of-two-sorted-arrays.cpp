class Solution {
public:
    // Helper function to check counts
    // Returns true if the total count of numbers <= candidate is >= k
    bool check(vector<int>& nums1, vector<int>& nums2, int candidate, int k) {
        int count = 0;
        
        // Use upper_bound to count how many elements are <= candidate in O(log N)
        // upper_bound returns iterator to first element > candidate.
        // Subtracting .begin() gives the count of elements <= candidate.
        count += upper_bound(nums1.begin(), nums1.end(), candidate) - nums1.begin();
        count += upper_bound(nums2.begin(), nums2.end(), candidate) - nums2.begin();
        
        return count >= k;
    }

    // Generic function to find the K-th smallest element using your template
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        // Range based on LeetCode constraints (-10^6 to 10^6)
        // You can also dynamically find min/max if needed.
        int lo = -1000000;
        int hi = 1000000;
        int ans = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(nums1, nums2, mid, k)) {
                // If we have >= k elements <= mid, then mid is a valid candidate.
                // We want the smallest such mid (Minimization Pattern).
                ans = mid;
                hi = mid - 1;
            } else {
                // Not enough elements <= mid. Mid is too small.
                lo = mid + 1;
            }
        }
        return ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;

        // If total length is odd, median is the (total/2 + 1)-th element.
        // If total length is even, median is average of (total/2)-th and (total/2 + 1)-th.
        
        // We can unify this:
        // k1 is the left median index, k2 is the right median index.
        // For odd (e.g. 5): k1 = 3, k2 = 3.
        // For even (e.g. 4): k1 = 2, k2 = 3.
        int k1 = (total + 1) / 2;
        int k2 = (total + 2) / 2;

        int val1 = getKthElement(nums1, nums2, k1);
        
        // Optimization: If odd, no need to search twice
        if (k1 == k2) return val1;
        
        int val2 = getKthElement(nums1, nums2, k2);

        return (val1 + val2) / 2.0;
    }
};