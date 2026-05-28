#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        std::vector<std::vector<std::vector<std::pair<int, int>>>> mem(n + 1, std::vector<std::vector<std::pair<int, int>>>(n + 1, std::vector<std::pair<int, int>>(n + 1)));
        auto [a, b] = solve(firstPlayer, n - secondPlayer + 1, n, mem);
        return {a, b};
    }
private:
    std::pair<int, int> solve(int l, int r, int k, std::vector<std::vector<std::vector<std::pair<int, int>>>>& mem) {
        if (l == r) return {1, 1};
        if (l > r) std::swap(l, r);
        if (mem[l][r][k] != std::pair<int, int>{0, 0}) return mem[l][r][k];
        int a = INT_MAX;
        int b = INT_MIN;
        for (int i = 1; i <= l; ++i) {
            for (int j = l - i + 1; j <= r - i; ++j) {
                if (i + j > (k + 1) / 2 || i + j < l + r - k / 2) continue;
                auto [x, y] = solve(i, j, (k + 1) / 2, mem);
                a = std::min(a, x + 1);
                b = std::max(b, y + 1);
            }
        }
        return mem[l][r][k] = {a, b};
    }
};