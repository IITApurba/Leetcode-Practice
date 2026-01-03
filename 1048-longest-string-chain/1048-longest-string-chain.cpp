class Solution {
public:
    bool pred(const string &a, const string &b) {
        if ((int)b.size() != (int)a.size() + 1) return false;
        int i = 0, j = 0;
        bool used = false;
        while (i < (int)a.size() && j < (int)b.size()) {
            if (a[i] == b[j]) {
                i++; j++;
            } else {
                if (used) return false;
                used = true;
                j++; // skip inserted char in b
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
            int &res = dp[i];
            if (res != -1) return res;
            res = 1;
            for (int j = 0; j < i; j++) {
                if (words[j].size() + 1 == words[i].size() && pred(words[j], words[i])) {
                    res = max(res, rec(j) + 1);
                }
            }
            return res;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, rec(i));
        return ans;
    }
};
