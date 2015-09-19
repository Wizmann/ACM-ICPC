class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        res.clear();
        buffer.clear();
        sort(num.begin(), num.end());
        dfs(num, 0, target);
        return res;
    }
private:
    void dfs(vector<int>& num, int ptr, int target) {
        if (target == 0) {
            res.push_back(buffer);
            return;
        }
        if (target < 0 || ptr >= num.size()) {
            return;
        }
        int p = ptr;
        int q = ptr;
        int cur = num[p];
        while (q < num.size() && num[q] == num[p]) {
            q++;
        }
        dfs(num, q, target);
        while (p < q) {
            buffer.push_back(cur);
            target -= cur;
            dfs(num, q, target);
            p++;
        }
        while (!buffer.empty() && *buffer.rbegin() == cur) {
            buffer.pop_back();   
        }
    }
private:
    vector<int> buffer;
    vector<vector<int> > res;
};
