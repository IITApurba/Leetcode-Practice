class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Data Structures for O(1) Min/Max retrieval
        deque<int> maxd, mind;
        
        int tail = 0, head = -1;
        int ans = 0;

        while (tail < n)
        {
            // Expand window using head
            while (head + 1 < n)
            {
                int next_val = nums[head + 1];
                
                // 1. PREDICT: What would the new Max and Min be if we added this element?
                // If deque is empty, the current max/min is just the new element itself.
                int current_max_val = maxd.empty() ? next_val : maxd.front();
                int current_min_val = mind.empty() ? next_val : mind.front();
                
                int new_max = max(current_max_val, next_val);
                int new_min = min(current_min_val, next_val);
                
                // 2. CHECK: Does this violate the limit?
                if (new_max - new_min > limit) break;

                // 3. UPDATE STATE: Since it's valid, we formally add it.
                head++;
                
                // Maintain Monotonic Decreasing Deque (for Max)
                while (!maxd.empty() && maxd.back() < nums[head]) maxd.pop_back();
                maxd.push_back(nums[head]);

                // Maintain Monotonic Increasing Deque (for Min)
                while (!mind.empty() && mind.back() > nums[head]) mind.pop_back();
                mind.push_back(nums[head]);
            }

            // Update Answer (Note: Problem asks for MAX length, not count of subarrays)
            ans = max(ans, head - tail + 1);

            // Shrink window from tail
            if (tail > head)
            {
                tail++;
                head = tail - 1;
                // Window is empty, clear state
                maxd.clear();
                mind.clear();
            }
            else
            {
                // Remove tail effect
                if (maxd.front() == nums[tail]) maxd.pop_front();
                if (mind.front() == nums[tail]) mind.pop_front();
                tail++;
            }
        }
        
        return ans;
    }
};