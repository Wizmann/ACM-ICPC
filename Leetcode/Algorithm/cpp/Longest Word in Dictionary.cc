class Solution {
public:
    string longestWord(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end());
        vector<bool> dp(n, false);
        map<string, int> mp;
        string res = "";
        
        for (int i = 0; i < n; i++) {
            string& word = words[i];
            mp[word] = i;
            char c = *word.rbegin();
            word.pop_back();
            if (word.empty()) {
                dp[i] = true;
            } else if (mp.count(word) != 0) {
                dp[i] = dp[mp[word]];
            }
            
            word.push_back(c);
            if (dp[i]) {
                if (word.size() > res.size()) {
                    res = word;
                } else if (word.size() == res.size()) {
                    res = min(res, word);
                }
            }
        }
        return res;
    }
};
