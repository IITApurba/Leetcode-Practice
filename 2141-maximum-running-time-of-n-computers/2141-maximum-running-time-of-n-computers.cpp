class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (int b : batteries) sum += b;
        long long low = 1, high = sum / n;
        while (low < high) {
            long long mid = high - (high - low) / 2;
            long long target = n * mid;
            long long currentSum = 0;
            for (int b : batteries) {
                currentSum += min((long long)b, mid);
            }
            if (currentSum >= target) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};