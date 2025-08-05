class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        res.clear();
        maxi = 0;
        string buffer;
        dfs(s, 0, 0, buffer);
        vector<string> res_;
        copy(res.begin(), res.end(), back_inserter(res_));
        return res_;
    }
private:
    void dfs(const string& s, int ptr, int match, string& buffer) {
        if (match < 0) {
            return;
        }
        if (buffer.size() + s.size() - ptr < maxi) {
            return;
        }
        if (ptr == s.length()) {
            if (match != 0) {
                return;
            }
            if (buffer.size() > maxi) {
                res.clear();
                maxi = buffer.size();
            }
            if (buffer.size() == maxi) {
                res.insert(buffer);
            }
            return;
        }
        if (s[ptr] != '(' && s[ptr] != ')') {
            buffer.push_back(s[ptr]);
            dfs(s, ptr + 1, match, buffer);
            buffer.pop_back();
            return;
        }
        if (s[ptr] == '(') {
            buffer.push_back('(');
            dfs(s, ptr + 1, match + 1, buffer);
            buffer.pop_back();
        }
        if (s[ptr] == ')') {
            buffer.push_back(')');
            dfs(s, ptr + 1, match - 1, buffer);
            buffer.pop_back();
        }
        dfs(s, ptr + 1, match, buffer);
    }
private:
    int maxi;
    set<string> res;
};
