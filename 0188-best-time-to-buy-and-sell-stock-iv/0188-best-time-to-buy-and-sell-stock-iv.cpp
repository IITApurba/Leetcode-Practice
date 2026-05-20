#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return rec(0, k, 0, prices, dp);
    }

private:
    int rec(int i, int k, int holding, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (k == 0 || i == prices.size()) return 0;
        if (dp[i][k][holding] != -1) return dp[i][k][holding];
        
        int skip = rec(i + 1, k, holding, prices, dp);
        int take = 0;
        
        if (holding) {
            take = prices[i] + rec(i + 1, k - 1, 0, prices, dp);
        } else {
            take = -prices[i] + rec(i + 1, k, 1, prices, dp);
        }
        
        return dp[i][k][holding] = max(skip, take);
    }
};