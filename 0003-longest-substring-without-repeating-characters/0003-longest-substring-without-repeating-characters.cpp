class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int l = 0;
        int r = 0;
        int max_length = 0;
        unordered_set<char> st;

        while (r < n) {
            while (st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            max_length = max(max_length, r - l + 1);

            r++;
        }

        return max_length;
    }
};