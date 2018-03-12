class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string s;
        for (auto& str: strs) {
            auto r = str;
            reverse(r.begin(), r.end());
            str = max(str, r);
            s += str;
        }
        string res = "";
        const int n = strs.size();
        for (int i = 0, st = 0; i < n; st += strs[i].size(), i++) {
            const int m = strs[i].size();
            string suffix = s.substr(st + m) + s.substr(0, st);
            for (int j = 0; j < m; j++) {
                string s = strs[i].substr(j) + suffix + strs[i].substr(0, j);
                res = max(res, s);
            }
            reverse(strs[i].begin(), strs[i].end());
            for (int j = 0; j < m; j++) {
                string s = strs[i].substr(j) + suffix + strs[i].substr(0, j);
                res = max(res, s);
            }
        }
        return res;
    }
};
