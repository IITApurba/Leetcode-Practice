class Solution {
public:
    bool pred(const string &a, const string &b) {
        if (b.size() != a.size() + 1) return false;
        int i = 0, j = 0;
        bool used = false;
        while (i < a.size() && j < (int)b.size()) {
            if (a[i] == b[j]) {
                i++; j++;
            } else {
                if (used) return false;
                used = true;
                j++;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = (int)words.size();
        sort(words.begin(), words.end(), [&](const string &x, const string &y){
            if (x.size() != y.size()) return x.size() < y.size();
            return x < y;
        });

        vector<int> dp(n, -1);

        function<int(int)> rec = [&](int i) -> int {

            if (dp[i] != -1) return dp[i];

            int ans = 1;
            for (int j = 0; j < i; j++) {
                if (words[j].size() + 1 == words[i].size() && pred(words[j], words[i])) {
                    ans = max(ans, rec(j) + 1);
                }
            }
            return dp[i] = ans;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, rec(i));
        return ans;
    }
};
