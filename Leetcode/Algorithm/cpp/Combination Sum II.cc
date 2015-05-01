class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        res.clear();
        vector<int> v;
        sort(num.begin(), num.end());
        dfs(num, 0, target, v);
        return res;
    }
    
    void dfs(vector<int> &num, int ptr, int target, vector<int>& v) {
        if (target == 0) {
            res.push_back(v);
            return;
        } else if (target < 0) {
            return;
        }
        int sz = num.size();
        while (ptr < sz) {
            v.push_back(num[ptr]);
            dfs(num, ptr + 1, target - num[ptr], v);
            v.pop_back();
            while  (ptr + 1 < sz && num[ptr] == num[ptr + 1]) {
                ptr++;
            } 
            ptr++;
        }
    }
    
    vector<vector<int> > res;
};
