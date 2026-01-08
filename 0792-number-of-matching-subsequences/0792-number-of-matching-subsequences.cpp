class Solution {
public:
    int n;
    string s;
    vector<vector<int>> nx; // nx[pos][c]

    int rec(int pos, int j, const string& w) {
        if (j == (int)w.size())
            return 1;
        if (pos > n)
            return 0;

        int c = w[j] - 'a';
        int np = nx[pos][c];
        if (np == -1)
            return 0;

        return rec(np + 1, j + 1, w);
    }

    int numMatchingSubseq(string S, vector<string>& words) {
        s = S;
        n = (int)s.size();

        // build nx[pos][c]
        nx.assign(n + 1, vector<int>(26, -1));
        for (int i = n - 1; i >= 0; i--) {
            nx[i] = nx[i + 1];
            nx[i][s[i] - 'a'] = i;
        }

        // compress duplicates
        unordered_map<string, int> mp;
        mp.reserve(words.size() * 2);
        for (auto& w : words)
            mp[w]++;

        int ans = 0;
        for (auto& it : mp) {
            ans += it.second * rec(0, 0, it.first);
        }
        return ans;
    }
};
