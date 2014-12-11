class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        res.clear();
        tmp.clear();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
private:
    void dfs(const vector<int> &candidates, int p, int target) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        int n = candidates.size();
        if (p >= n) {
            return;
        }
        while (p < n) {
            if (p - 1 >= 0 && candidates[p - 1] == candidates[p]) {
                continue;
            }
            tmp.push_back(candidates[p]);
            dfs(candidates, p, target - candidates[p]);
            tmp.pop_back();
            p++;
        }
    }
    
private:
    vector<int> tmp;
    vector<vector<int> > res;
};
