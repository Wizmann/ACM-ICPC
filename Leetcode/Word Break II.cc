class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        for (int i = 0; i < SIZE; i++) {
            dp[i].clear();
        }
        itos.clear();
        stoi.clear();
        ans.clear();
        int idx = 0;
        for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
            itos.push_back(*iter);
            stoi[*iter] = idx;
            idx++;
        }
        int len = s.length();
        
        dp[0].push_back(-1);
        for (int i = 0; i <= len; i++) {
            if (!dp[i].empty()) {
                string ss;
                for (int j = i + 1; j <= len; j++) {
                    ss += s[j - 1];
                    if (dict.find(ss) != dict.end()) {
                        idx = stoi[ss];
                        dp[j].push_back(idx);
                    }
                }
            }
        }
        string tmp;
        dfs(len, tmp);
        return ans;
    }
    
    void dfs(int pos, string& tmp) {
        if (pos == 0) {
            ans.push_back(tmp);
            return;
        }
        for (auto iter = dp[pos].begin(); iter != dp[pos].end(); ++iter) {
            string next;
            int now = *iter;
            if (tmp.empty()) {
                next = itos[now];
            } else {
                next = itos[now] + " " + tmp;
            }
            dfs(pos - itos[now].size(), next);
        }
    }
    
    static const int SIZE = 1024;
    vector<string> ans;
    vector<int> dp[SIZE];
    vector<string> itos;
    map<string, int> stoi;
};
