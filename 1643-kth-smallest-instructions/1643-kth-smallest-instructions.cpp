class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0];
        int h = destination[1];
        int n = h + v;
        
        vector<vector<long long>> nCr(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            nCr[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
            }
        }
        
        string result = "";
        for (int i = 0; i < n; ++i) {
            if (h > 0) {
                long long count = nCr[h - 1 + v][v];
                if (k <= count) {
                    result += 'H';
                    h--;
                } else {
                    result += 'V';
                    v--;
                    k -= count;
                }
            } else {
                result += 'V';
                v--;
            }
        }
        return result;
    }
};