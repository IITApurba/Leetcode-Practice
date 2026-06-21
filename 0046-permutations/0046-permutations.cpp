class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur_perm;
        vector<vector<int>> all_sol;
        // Use unordered_map instead of map for O(1) average lookup/insert
        // instead of O(log n) for each operation
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int num : nums)
            mp[num]++;

        function<void(int)> rec = [&](int level) {
            if (level == n) {
                all_sol.push_back(cur_perm);
                return;
            }

            for (auto& v : mp) {
                if (v.second != 0) {
                    v.second--;
                    cur_perm.push_back(v.first);
                    rec(level + 1);
                    cur_perm.pop_back();
                    v.second++;
                }
            }
        };

        rec(0);
        
        return all_sol;
    }
};
