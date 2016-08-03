class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> mp;
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            auto& word = words[i];
            mp[word] = i;
        }
        
        for (int i = 0; i < n; i++) {
            auto& word = words[i];
            vector<string> prefixs, suffixs;
            get_prefix(word, prefixs, suffixs);
            for (auto prefix: prefixs) {
                //printf("%s ", prefix.c_str());
                reverse(prefix.begin(), prefix.end());
                if (mp.find(prefix) != mp.end() && mp[prefix] != i) {
                    ans.push_back({i, mp[prefix]});
                }
            }
            for (auto suffix: suffixs) {
                reverse(suffix.begin(), suffix.end());
                if (mp.find(suffix) != mp.end() && mp[suffix] != i) {
                    ans.push_back({mp[suffix], i});
                }
            }
        }
        return ans;
    }
private:
    void get_prefix(const string& word, vector<string>& prefix, vector<string>& suffix) {
        memset(dp, 0, sizeof(dp));
        int n = word.size();
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;    
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; i + j < n; j++) {
                if (word[j] != word[i + j]) {
                    continue;
                }
                if (i > 1 && !dp[j + 1][i + j - 1]) {
                    continue;
                }
                dp[j][j + i] = 1;
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (dp[i][n - 1]) {
                prefix.push_back(word.substr(0, i));
            }
        }
        prefix.push_back(word);
        
        for (int i = 0; i < n - 1; i++) {
            if (dp[0][i]) {
                suffix.push_back(word.substr(i + 1));
            }
        }
        
        if (dp[0][n - 1]) {
            prefix.push_back("");
            suffix.push_back("");
        }
    }
    char dp[222][222];
};
