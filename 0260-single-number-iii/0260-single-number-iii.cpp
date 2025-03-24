class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }

        long long diff = xorSum & -xorSum;  // Using long long prevents overflow
        int x = 0, y = 0;

        for (int num : nums) {
            if (num & diff)
                x ^= num;
            else
                y ^= num;
        }

        return {x, y};
    }
};
