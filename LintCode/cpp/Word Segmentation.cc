class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        size_t len = s.length();
	    bool dp[len + 5];
	    dp[0] = 1;
        
        vector<int> wchars;
        wchars.resize(256);

        for (const auto& word: dict) {
            for (auto c: word) {
                wchars[c] = 1;
            }
        }
        
        for (auto c: s) {
            if (!wchars[c]) {
                return false;
            }
        }

        
        for (int i = 1; i <= len; i++) {
            dp[i] = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[len] == 1;
    }
};
