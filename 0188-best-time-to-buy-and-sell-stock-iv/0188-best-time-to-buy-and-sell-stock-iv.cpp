#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return dfs(0, k, 0, prices, memo);
    }

private:
    int dfs(int i, int k, int holding, vector<int>& prices, vector<vector<vector<int>>>& memo) {
        if (k == 0 || i == prices.size()) return 0;
        if (memo[i][k][holding] != -1) return memo[i][k][holding];
        
        int skip = dfs(i + 1, k, holding, prices, memo);
        int take = 0;
        
        if (holding) {
            take = prices[i] + dfs(i + 1, k - 1, 0, prices, memo);
        } else {
            take = -prices[i] + dfs(i + 1, k, 1, prices, memo);
        }
        
        return memo[i][k][holding] = max(skip, take);
    }
};