class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        res.clear();
        res.push_back(vector<int>());
        vector<int> vec = S;
        sort(vec.begin(), vec.end());
        vector<int> tmp;
        dfs(vec, 0, tmp);
        return res;
    }
private:
    void dfs(const vector<int> &S, int p, vector<int>& tmp) {
        if (p >= S.size()) {
            return;
        }
        tmp.push_back(S[p]);
        res.push_back(tmp);
        dfs(S, p + 1, tmp);
        tmp.pop_back();
        
        int u = S[p];
        while (p < S.size() && S[p] == u) {
            p++;
        }
        dfs(S, p, tmp);
    }
private:
    vector<vector<int> > res;
};

