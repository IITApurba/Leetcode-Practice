class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        if (!dict.count(endWord)) {
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int k = 0; k < size; ++k) {
                string word = q.front();
                q.pop();
                
                if (word == endWord) {
                    return steps;
                }
                
                for (int i = 0; i < word.length(); ++i) {
                    char original = word[i];
                    
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        
                        if (dict.count(word)) {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            steps++;
        }
        
        return 0;
    }
};