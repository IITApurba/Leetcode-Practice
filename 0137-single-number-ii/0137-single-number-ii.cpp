class Solution {
public:
    int singleNumber(vector<int>& arr) {

        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < 32; i++) // Iterate over each bit position
        {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] & (1LL << i)) // Check if i-th bit is set
                    cnt++;
            }

            if (cnt % 3 == 1) {
                ans = ans | (1LL << i);
            }
        }

        return ans;
    }
};