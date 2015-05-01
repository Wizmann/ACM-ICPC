class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n = S.size();
        sort(S.begin(), S.end());
        ans.clear();
        vector<int> tmp;
        dfs(S, tmp, 0, n);
        return ans;
    }
private:
    vector<vector<int> > ans;
private:
    void dfs(vector<int> &S, vector<int> &tmp, int p, int n)
    {
        ans.push_back(tmp);
        if (p == n) {
            return;
        }
        
        for (int i = p; i < n; i++) {
            if (i - 1 >= p && S[i] == S[i - 1]) {
                continue;
            }
            tmp.push_back(S[i]);
            dfs(S, tmp, i + 1, n);
            tmp.pop_back();
        }
    }
};
