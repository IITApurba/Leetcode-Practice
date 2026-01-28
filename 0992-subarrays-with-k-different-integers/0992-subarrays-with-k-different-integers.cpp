class Solution {
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        int tail = 0, head = -1;
        int distinct = 0;
        int ans = 0;

        while (tail < n) {
            while (head + 1 < n) {
                int next_val = nums[head + 1];
                int is_new = (cnt[next_val] == 0);
                
                if (distinct + is_new > k) break;

                head++;
                if (cnt[next_val] == 0) distinct++;
                cnt[next_val]++;
            }

            ans += (head - tail + 1);

            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                cnt[nums[tail]]--;
                if (cnt[nums[tail]] == 0) distinct--;
                tail++;
            }
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};