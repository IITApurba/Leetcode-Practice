class Solution {
public:
    // The Check Function:
    // Returns true if there are at least 'k' pairs with distance <= mid_dist
    bool check(vector<int>& nums, int k, int mid_dist) {
        int count = 0;
        int left = 0;
        int n = nums.size();
        
        // Sliding Window approach to count pairs in O(N)
        for (int right = 0; right < n; right++) {
            // While the window is invalid (distance > mid_dist), shrink from left
            while (nums[right] - nums[left] > mid_dist) {
                left++;
            }
            // All indices between left and right-1 form a valid pair with 'right'
            // specifically: (left, right), (left+1, right), ... (right-1, right)
            count += (right - left);
        }
        
        return count >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        // 1. Sorting is mandatory for the Sliding Window logic to work
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // 2. Define Search Space
        // Smallest possible distance is 0
        // Largest possible distance is between the max and min elements
        int lo = 0;
        int hi = nums[n-1] - nums[0];
        int ans = hi;

        // 3. Binary Search Template (Minimization)
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(nums, k, mid)) {
                // If true, it means we have ENOUGH pairs (>= k) with distance <= mid.
                // mid is a valid candidate for "k-th smallest", but we want to see 
                // if a smaller distance can also satisfy the "k-th" rank.
                ans = mid;
                hi = mid - 1;
            } else {
                // If false, we have fewer than k pairs. 
                // mid is too strict (too small). We need a larger distance to include more pairs.
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};