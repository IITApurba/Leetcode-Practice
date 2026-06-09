class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
    long long hours = 0;
    for (int p : piles) hours += (p + k - 1) / k;
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    int ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canEat(piles, h, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
};