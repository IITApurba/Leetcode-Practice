#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();

        // Map each unique x[i] to the max y[i] seen for it
        unordered_map<int, int> maxY;
        for (int i = 0; i < n; ++i) {
            if (maxY.count(x[i])) {
                maxY[x[i]] = max(maxY[x[i]], y[i]);
            } else {
                maxY[x[i]] = y[i];
            }
        }

        // Store all max y-values for unique x in a vector
        vector<int> vals;
        for (auto& [_, val] : maxY) {
            vals.push_back(val);
        }

        // Not enough distinct x[i]
        if (vals.size() < 3)
            return -1;

        // Sort in descending order to get top 3
        sort(vals.begin(), vals.end(), greater<int>());

        // Return sum of top 3
        return vals[0] + vals[1] + vals[2];
    }
};
