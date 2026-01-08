#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<array<int, 26>> nx;
    int n;

    bool rec(int pos, int j, const string& w) {
        if (j == (int)w.size())
            return true;
        if (pos > n)
            return false;
        int c = w[j] - 'a';
        int np = nx[pos][c];
        if (np == -1)
            return false;
        return rec(np + 1, j + 1, w);
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        n = (int)s.size();

        nx.assign(n + 1, {});
        for (int c = 0; c < 26; c++)
            nx[n][c] = -1;
        for (int i = n - 1; i >= 0; i--) {
            nx[i] = nx[i + 1];
            nx[i][s[i] - 'a'] = i;
        }

        unordered_map<string, int> mp;
        mp.reserve(words.size() * 2);
        for (auto& w : words)
            mp[w]++;

        int ans = 0;
        for (auto& it : mp) {
            if (rec(0, 0, it.first))
                ans += it.second;
        }
        return ans;
    }
};
