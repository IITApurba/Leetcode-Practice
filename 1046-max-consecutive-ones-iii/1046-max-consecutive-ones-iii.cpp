class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l = 0;
        int maxLength = 0;
        int zero = 0;
        int n = nums.size();

        for (int r = 0; r < n; r++) {

            if (nums[r] == 0) {
                zero++;
            }

            while (zero == k+1) {
                if (nums[l] == 0) {
                    zero--;
                }
                l++;
            }

            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};