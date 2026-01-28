class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxd, mind;
        int tail = 0, head = -1;
        int ans = 0;

        while (tail < n) {
            while (head + 1 < n) {
                int next_val = nums[head + 1];

                int current_max_val = maxd.empty() ? next_val : maxd.front();
                int current_min_val = mind.empty() ? next_val : mind.front();

                int new_max = max(current_max_val, next_val);
                int new_min = min(current_min_val, next_val);

                if (new_max - new_min > limit) break;

                head++;

                while (!maxd.empty() && maxd.back() < nums[head]) maxd.pop_back();
                maxd.push_back(nums[head]);

                while (!mind.empty() && mind.back() > nums[head]) mind.pop_back();
                mind.push_back(nums[head]);
            }

            ans = max(ans, head - tail + 1);

            if (tail > head) {
                tail++;
                head = tail - 1;
                maxd.clear();
                mind.clear();
            } else {
                if (!maxd.empty() && maxd.front() == nums[tail]) maxd.pop_front();
                if (!mind.empty() && mind.front() == nums[tail]) mind.pop_front();
                tail++;
            }
        }

        return ans;
    }
};
