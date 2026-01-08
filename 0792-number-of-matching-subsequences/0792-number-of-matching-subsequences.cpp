class Solution {
public:
    int n;
    string s;
    vector<array<int,26>> nxt;

    // recursive check: can we match w[j..] starting from position pos in s?
    int rec(int pos, int j, const string &w) {
        // base case
        if (j == (int)w.size()) return 1;
        if (pos > n) return 0;

        int c = w[j] - 'a';
        int np = nxt[pos][c];
        if (np == -1) return 0;

        return rec(np + 1, j + 1, w);
    }

    int numMatchingSubseq(string S, vector<string>& words) {
        s = S;
        n = (int)s.size();

        // build nxt[pos][c]
        nxt.assign(n + 1, {});
        for (int c = 0; c < 26; c++) nxt[n][c] = -1;
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }

        // compress duplicates
        unordered_map<string,int> mp;
        mp.reserve(words.size() * 2);
        for (auto &w : words) mp[w]++;

        int ans = 0;
        for (auto &it : mp) {
            const string &w = it.first;
            int cnt = it.second;
            ans += cnt * rec(0, 0, w);
        }
        return ans;
    }
};
