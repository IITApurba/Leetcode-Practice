class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = (int)nums.size();
        vector<int> d(n + 1, 0);
        int f = 0, ans = 0;

        for (int i = 0; i + 2 < n; i++)
        {
            f ^= d[i];
            int v = nums[i] ^ f;
            if (v == 0)
            {
                ans++;
                f ^= 1;
                d[i + 3] ^= 1;
            }
        }

        for (int i = max(0, n - 2); i < n; i++)
        {
            f ^= d[i];
            if ((nums[i] ^ f) == 0)
                return -1;
        }

        return (int)ans;
    }
};