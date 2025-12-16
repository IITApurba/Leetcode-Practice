class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long mn = *min_element(ranks.begin(), ranks.end());
        long long lo = 0, hi = mn * 1LL * cars * cars;

        auto ok = [&](long long t) -> bool {
            long long s = 0;
            for (int r : ranks) {
                long double x = (long double)t / (long double)r;
                long long n = (long long)sqrtl(x);

                while ((n + 1) > 0 && (long double)(n + 1) * (n + 1) * r <= (long double)t) n++;
                while (n > 0 && (long double)n * n * r > (long double)t) n--;

                s += n;
                if (s >= cars) return true;
            }
            return s >= cars;
        };

        while (lo < hi) {
            long long md = lo + (hi - lo) / 2;
            if (ok(md)) hi = md;
            else lo = md + 1;
        }
        return lo;
    }
};
