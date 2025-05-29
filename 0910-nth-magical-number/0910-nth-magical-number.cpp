class Solution {
public:
    const int MOD = 1e9 + 7;

    long long lcm(long long a, long long b) {
        return a / __gcd(a, b) * b;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long left = 1, right = 1LL * n * min(a, b);
        long long l = lcm(a, b);

        while (left < right) {
            long long mid = (left + right) / 2;
            long long count = mid / a + mid / b - mid / l;

            if (count < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left % MOD;
    }
};
