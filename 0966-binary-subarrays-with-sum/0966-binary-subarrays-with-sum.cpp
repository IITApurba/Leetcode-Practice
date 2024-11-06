class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int count = 0;
        int sum = 0;
        int l = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Handle case when the sum itself is the goal

        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];

            // Check if there exists a subarray that sums to 'goal'
            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
                count += prefixSumCount[sum - goal];
            }

            // Store the current prefix sum count
            prefixSumCount[sum]++;
        }

        return count;
    }
};