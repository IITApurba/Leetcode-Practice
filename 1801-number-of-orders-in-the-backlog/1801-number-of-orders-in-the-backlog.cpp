class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> buy_pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sell_pq;
        
        for (const auto& order : orders) {
            int price = order[0];
            int amount = order[1];
            int type = order[2];
            
            if (type == 0) {
                while (amount > 0 && !sell_pq.empty() && sell_pq.top().first <= price) {
                    auto top = sell_pq.top();
                    sell_pq.pop();
                    int take = min(amount, top.second);
                    amount -= take;
                    top.second -= take;
                    if (top.second > 0) {
                        sell_pq.push(top);
                    }
                }
                if (amount > 0) {
                    buy_pq.push({price, amount});
                }
            } else {
                while (amount > 0 && !buy_pq.empty() && buy_pq.top().first >= price) {
                    auto top = buy_pq.top();
                    buy_pq.pop();
                    int take = min(amount, top.second);
                    amount -= take;
                    top.second -= take;
                    if (top.second > 0) {
                        buy_pq.push(top);
                    }
                }
                if (amount > 0) {
                    sell_pq.push({price, amount});
                }
            }
        }
        
        long long ans = 0;
        int mod = 1e9 + 7;
        
        while (!buy_pq.empty()) {
            ans = (ans + buy_pq.top().second) % mod;
            buy_pq.pop();
        }
        while (!sell_pq.empty()) {
            ans = (ans + sell_pq.top().second) % mod;
            sell_pq.pop();
        }
        
        return ans;
    }
};