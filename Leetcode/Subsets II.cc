class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        ans.clear();
        sort(S.begin(), S.end());
        vector<int> tmp;
        dfs(S, tmp, 0);
        return ans;
    }
private:
    vector<vector<int> > ans;
private:
    void dfs(const vector<int> &S, vector<int>& tmp, int p) {
        if (p == S.size()) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(S[p]);
        dfs(S, tmp, p + 1);
        tmp.pop_back();
        // --- 
        int u = S[p];
        while (p < S.size() && S[p] == u) {
            p++;   
        }
        dfs(S, tmp, p);
    }
};
