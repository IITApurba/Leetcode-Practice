class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int left = 0;
        int max_len = 0;
        int max_freq = 0;

        unordered_map<char, int> char_count;

        for (int right = 0; right < n; right++) {

            char_count[s[right]]++;
            max_freq = max(max_freq, char_count[s[right]]);

            // Check if current window is valid
            if ((right - left + 1) - max_freq > k) {
                char_count[s[left]]--;
                left++;
            }

            // Update max length of valid substring
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};