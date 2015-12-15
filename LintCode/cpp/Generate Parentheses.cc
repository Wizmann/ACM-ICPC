class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        res.clear();
        string buffer;
        dfs(n * 2, buffer, 0);
        return res;
    }
private:
    void dfs(int n, string& buffer, int cnt) {
        if (n == 0) {
            if (cnt == 0) {
                res.push_back(buffer);
            }
            return;
        }
        buffer.push_back('(');
        dfs(n - 1, buffer, cnt + 1);
        buffer.pop_back();
        if (cnt > 0) {
            buffer.push_back(')');
            dfs(n - 1, buffer, cnt - 1);
            buffer.pop_back();
        }
    }
private:
    vector<string> res;
};
