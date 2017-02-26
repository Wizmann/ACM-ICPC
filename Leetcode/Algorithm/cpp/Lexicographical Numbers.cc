class Solution {
public:
    vector<int> lexicalOrder(int n) {
        res.clear();
        res.reserve(n);
        dfs(0, n);
        return res;
    }
private:
    void dfs(int cur, int n) {
        if (cur > n) {
            return;
        }
        if (cur) {
            res.push_back(cur);
        }
        for (int i = (cur == 0? 1: 0); i < 10; i++) {
            dfs(cur * 10 + i, n);
        }
    }
    
    vector<int> res;
};
