class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        tmp.clear();
        dfs(num, 0, target);
        return res;
    }
private:
    void dfs(const vector<int> &num, int p, int target) {
        if (target == 0) {
            res.push_back(tmp);
        }
        if (target < 0) {
            return;
        }
        for (int i = p; i < num.size(); i++) {
            if (i > p && num[i - 1] == num[i]) {
                continue;
            }
            tmp.push_back(num[i]);
            dfs(num, i + 1, target - num[i]);
            tmp.pop_back();
        }
    }
private:
    vector<int> tmp;
    vector<vector<int> > res;
};
