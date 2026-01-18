class Solution {
public:
    // The Check Function:
    // Returns true if there are at least 'k' numbers in the table <= x.
    // We want the smallest 'x' for which this returns true.
    bool check(int x, int m, int n, int k) {
        int count = 0;
        
        // Iterate through each row 'i' from 1 to m
        for (int i = 1; i <= m; i++) {
            // How many numbers in this row are <= x?
            // Values in row i are: i, 2i, 3i...
            // Simple Math: x / i gives the count of multiples of i that are <= x.
            // Constraint: We cannot have more than 'n' columns.
            count += min(n, x / i);
        }
        
        return count >= k;
    }

    int findKthNumber(int m, int n, int k) {
        // Optimization: Iterating 1..m is faster if m is small.
        // If m > n, we can swap them because the table is symmetric (i*j == j*i).
        // This ensures our check loop runs min(m, n) times.
        if (m > n) swap(m, n);

        // 1. Search Space
        // lo: Smallest element is 1*1 = 1
        // hi: Largest element is m*n
        int lo = 1, hi = m * n;
        int ans = -1;

        // 2. Binary Search Template (Minimization)
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, m, n, k)) {
                // If we found >= k numbers <= mid, then mid is a candidate.
                // We want the k-th smallest, so we try to find a smaller number
                // that still satisfies the condition (squeezing the answer to the left).
                ans = mid;
                hi = mid - 1;
            } else {
                // We found fewer than k numbers <= mid.
                // mid is too small. We need a larger number.
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};