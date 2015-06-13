class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        tmp.clear();
        res.clear();
        
        dfs(1, 0, k, n);
        return res;
    }
private:
    void dfs(int cur, int sum, int k, int n) {
        if (tmp.size() == k) {
            if (sum == n) {
                res.push_back(tmp);
            }
            return;
        }
        for (int i = cur; i < 10; i++) {
            if (sum + i > n) {
                continue;
            }
            tmp.push_back(i);
            dfs(i + 1, sum + i, k, n);
            tmp.pop_back();
        }
    }
private:
    vector<int> tmp;
    vector<vector<int>> res;
};
