class Solution {
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        string buffer = "";
        dfs(n, 0, buffer);
        return res;
    }
private:
    void dfs(int u, int v, string& buffer) {
        if (u == 0 && v == 0) {
            res.push_back(buffer);
            return;
        }
        if (v > 0) {
            buffer.push_back(')');
            dfs(u, v - 1, buffer);
            buffer.pop_back();
        }
        if (u > 0) {
            buffer.push_back('(');
            dfs(u - 1, v + 1, buffer);
            buffer.pop_back();
        }
    }
private:
    vector<string> res;
};
