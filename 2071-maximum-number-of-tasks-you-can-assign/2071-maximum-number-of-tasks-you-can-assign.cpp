class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low = 0, high = min(tasks.size(), workers.size());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAssign(tasks, workers, pills, strength, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    bool canAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        if (mid == 0) return true;
        multiset<int> w;
        for (int i = workers.size() - mid; i < workers.size(); ++i) {
            w.insert(workers[i]);
        }

        int p = pills;
        for (int i = mid - 1; i >= 0; --i) {
            auto it = w.end();
            --it;
            if (*it >= tasks[i]) {
                w.erase(it);
            } else if (p > 0) {
                auto it2 = w.lower_bound(tasks[i] - strength);
                if (it2 != w.end()) {
                    w.erase(it2);
                    p--;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};