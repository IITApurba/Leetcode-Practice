class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        long long sum = 0;
        int tail = 0, head = -1;
        int ans = 0;

        while (tail < n)
        {
            while (head + 1 < n)
            {
                long long next_val = nums[head + 1];
                long long new_len = (head + 1) - tail + 1;
                long long new_sum = sum + next_val;
                
                long long needed = (next_val * new_len) - new_sum;

                if (needed > k) break;

                head++;
                sum += nums[head];
            }

            ans = max(ans, head - tail + 1);

            if (tail > head)
            {
                tail++;
                head = tail - 1;
                sum = 0;
            }
            else
            {
                sum -= nums[tail];
                tail++;
            }
        }

        return ans;
    }
};