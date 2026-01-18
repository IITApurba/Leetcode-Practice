class Solution {
public:
    bool check(vector<int>& nums, int k, int mid) {
        
        int count = 0, left = 0, n = nums.size();

        for (int right = 0; right < n; right++) {
            while (nums[right] - nums[left] > mid)
                left++;
            count += right - left;
        }
        return count >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back() - nums.front(), ans = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
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
