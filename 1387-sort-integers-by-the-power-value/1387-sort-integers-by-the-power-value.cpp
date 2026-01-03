class Solution {
public:

    static const int MX = 1000000;
    int dp[MX + 1];

    int pw(int x) {
        // base case
        if (x == 1) return 0;
        //save and return
        if (x <= MX && dp[x] != -1) return dp[x];

        //transition
        int nx = (x % 2 == 0) ? (x / 2LL) : (3LL * x + 1);
        int ans = 1 + pw(nx);

        if (x <= MX) dp[x] = ans;
        return ans;
    }

    int getKth(int lo, int hi, int k) {
        memset(dp, -1, sizeof(dp));
        dp[1] = 0;

        vector<pair<int,int>> v; // (power, value)
        v.reserve(hi - lo + 1);

        for (int x = lo; x <= hi; x++) {
            v.push_back({pw(x), x});
        }

        sort(v.begin(), v.end(), [](const auto &a, const auto &b){
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        return v[k - 1].second;
    }
};
