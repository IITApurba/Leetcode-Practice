class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        int max_e = *max_element(nums.begin(), nums.end());
        
        long long tail = 0, head = -1;
        long long count = 0; // count of max_e in current window
        long long invalid_subarrays = 0;

        while (tail < n)
        {
            while (head + 1 < n)
            {
                int next_val = nums[head + 1];
                int is_match = (next_val == max_e);

                if (count + is_match > k - 1) break;

                head++;
                if (next_val == max_e) count++;
            }

            invalid_subarrays += (head - tail + 1);

            if (tail > head)
            {
                tail++;
                head = tail - 1;
                count = 0;
            }
            else
            {
                if (nums[tail] == max_e) count--;
                tail++;
            }
        }

        long long total_subarrays = n * (n + 1) / 2;
        return total_subarrays - invalid_subarrays;
    }
};