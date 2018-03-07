class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words_) {
        words = words_;
        int n = words.size();
        if (n == 0) {
            return {};
        }
        int m = words[0].size();
        sort(words.begin(), words.end());
        
        for (int i = 0; i < n; i++) {
            buffer.push_back(words[i]);
            dfs(i, n, m);
            buffer.pop_back();
        }

        return res;
    }
private:
    void dfs(int cur, int n, int m) {
        if (buffer.size() == m) {
            res.push_back(buffer);
            return;
        }

        string prefix = "";
        int p = buffer.size();
        for (int i = 0; i < p; i++) {
            prefix += buffer[i][p];
        }
        
        auto q = lower_bound(words.begin(), words.end(), prefix) - words.begin();
        if (q == n) {
            return;
        }
        prefix += "~";
        while (q < n && words[q] < prefix) {
            buffer.push_back(words[q]);
            dfs(q + 1, n, m);
            buffer.pop_back();
            q++;
        }
    }
private:
    vector<vector<string> > res;
    vector<string> buffer;
    vector<string> words;
};
