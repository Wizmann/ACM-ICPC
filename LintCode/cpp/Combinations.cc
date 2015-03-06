class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        res.clear();
        
        vector<int> tmp;
        dfs(0, n, k, tmp);
        return res;
    }
private:
    void dfs(int now, int n, int k, vector<int>& tmp) {
        if (tmp.size() == k) {
            res.push_back(tmp);
        }
        for (int i = now + 1; i <= n; i++) {
            tmp.push_back(i);
            dfs(i, n, k, tmp);
            tmp.pop_back();
        }
    }
private:
    vector<vector<int> > res;
};
