class Solution {
public:
    long long appealSum(string s) {
        // Optimized from O(n * 26) to O(n) using a running sum
        // Instead of summing all last positions each iteration,
        // we maintain a running sum of contributions
        vector<int> last(26, 0);  // last occurrence index + 1
        long long res = 0;
        long long runningSum = 0;  // sum of all last positions
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            int charIdx = s[i] - 'a';
            // Update running sum: subtract old contribution, add new
            runningSum += (i + 1) - last[charIdx];
            last[charIdx] = i + 1;
            res += runningSum;
        }
        return res;
    }
};