#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& c) {
        int mn = -1, mx = -1, md = 0;
        long long n = 0, s = 0;
        int bf = -1;
        for (int i = 0; i < 256; i++) {
            if (c[i]) {
                if (mn == -1) mn = i;
                mx = i;
                n += c[i];
                s += 1LL * i * c[i];
                if (bf == -1 || c[i] > bf) bf = c[i], md = i;
            }
        }

        double me = (double)s / (double)n;

        long long k1 = (n - 1) / 2, k2 = n / 2; // 0-indexed
        int v1 = -1, v2 = -1;
        long long cur = 0;
        for (int i = 0; i < 256; i++) {
            if (!c[i]) continue;
            long long nx = cur + c[i];
            if (v1 == -1 && k1 < nx) v1 = i;
            if (v2 == -1 && k2 < nx) { v2 = i; break; }
            cur = nx;
        }
        double med = ((double)v1 + (double)v2) / 2.0;

        return {(double)mn, (double)mx, me, med, (double)md};
    }
};
