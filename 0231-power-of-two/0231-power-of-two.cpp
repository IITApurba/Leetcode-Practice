class Solution {
public:
    bool isPowerOfTwo(int n) {

        int x = __builtin_popcount(n);
        return (n > 0) && (x==1);
    }
};