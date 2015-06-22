class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        res.clear();
        auto _S = S;
        sort(_S.begin(), _S.end());
        
        vector<int> tmp;
        dfs(_S, 0, tmp);
        return res;
    }
private:
    void dfs(const vector<int>& S, int ptr, vector<int>& tmp) {
        if (ptr == S.size()) {
            res.push_back(tmp);
            return;
        }
        
        int endptr = ptr;
        while (endptr < S.size() && S[ptr] == S[endptr]) {
            endptr++;
        }
        
        dfs(S, endptr, tmp);
        
        for (int i = ptr; i < endptr; i++) {
            tmp.push_back(S[i]);
            dfs(S, endptr, tmp);
        }
        
        for (int i = ptr; i < endptr; i++) {
            tmp.pop_back();
        }
    }
private:
    vector<vector<int> > res;
};

