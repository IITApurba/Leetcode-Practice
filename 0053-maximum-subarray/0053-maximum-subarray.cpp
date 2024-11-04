typedef long long ll;

class Solution {
public:
    ll maxSubArray(vector<int>& a) {
        ll max_sum = INT_MIN;
        ll best_sum = INT_MIN;

        for (int i = 0; i < a.size(); i++) {
            max_sum = max(max_sum + a[i], (ll)a[i]);
            best_sum = max(best_sum, max_sum);
        }

        return (best_sum);
    }
};