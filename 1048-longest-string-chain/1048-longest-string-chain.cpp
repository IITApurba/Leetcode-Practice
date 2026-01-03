class Solution {
public:
    //pred(a,b) -> check is 'a' predecessor of 'b'
    bool pred(const string &a, const string &b) {
        // len of b must be 1+a
        if (b.size() != a.size() + 1) return false;

        // using 2 pointers to check b can be made by just using 1 char
        int i = 0, j = 0;
        bool used = false;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++; j++;
            } else {
                if (used) return false;
                used = true;
                j++;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // sort the words array by length :p
        sort(words.begin(), words.end(), [&](const string &x, const string &y){
            if (x.size() != y.size()) return x.size() < y.size();
            return x < y;
        });

        // dp = -1
        vector<int> dp(n, -1);

        // dp[i] -> longest word chain ending at i 

        function<int(int)> rec = [&](int i) -> int {
            
            //cache check
            if (dp[i] != -1) return dp[i];

            int ans = 1;
            for (int j = 0; j < i; j++) {
                // words[j] is a valid predecessor of words[i]
                if (words[j].size() + 1 == words[i].size() && pred(words[j], words[i])) {
                    ans = max(ans, rec(j) + 1);
                }
            }
            return dp[i] = ans;
        };

        int ans = 0;

        for (int i = 0; i < n; i++) ans = max(ans, rec(i));
        
        return ans;
    }
};
