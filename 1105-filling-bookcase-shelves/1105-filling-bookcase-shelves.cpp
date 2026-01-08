class Solution {
public:
    int n, sw;
    vector<vector<int>> b;
    vector<int> dp; // dp[i] = min height to place books from i..n-1

    int rec(int i) {
        // base case
        if (i == n)
            return 0;
        //cache check

        if (dp[i] != -1)
            return dp[i];

        int ans = 1e9;
        int w = 0, h = 0;

        // put books i..j on the same shelf
        for (int j = i; j < n; j++) {
            w += b[j][0];
            if (w > sw)
                break;
            h = max(h, b[j][1]);
            ans = min(ans, h + rec(j + 1));
        }
        return dp[i] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        b = books;
        sw = shelfWidth;
        n = b.size();
        dp.assign(n, -1);
        return rec(0);
    }
};
