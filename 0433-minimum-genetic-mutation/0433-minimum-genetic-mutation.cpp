class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valid(bank.begin(), bank.end());
        if (valid.find(endGene) == valid.end()) return -1;

        queue<string> q;
        q.push(startGene);
        int mutations = 0;
        char choices[] = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (curr == endGene) return mutations;

                for (int j = 0; j < 8; ++j) {
                    char original = curr[j];
                    for (char c : choices) {
                        if (c == original) continue;
                        curr[j] = c;
                        if (valid.find(curr) != valid.end()) {
                            q.push(curr);
                            valid.erase(curr);
                        }
                    }
                    curr[j] = original;
                }
            }
            mutations++;
        }
        return -1;
    }
};