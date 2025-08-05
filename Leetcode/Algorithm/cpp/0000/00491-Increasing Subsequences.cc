class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        
        for (int i = 1; i < (1 << n); i++) {
            vector<int> cur;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    cur.push_back(nums[j]);
                }
            }
            if (is_inc(cur)) {
                res.insert(cur);
            }
        }
        vector<vector<int>> resvec;
        copy(res.begin(), res.end(), back_inserter(resvec));
        return resvec;
    }
private:
    bool is_inc(const vector<int>& vec) {
        int n = vec.size();
        if (n < 2) {
            return false;
        }
        for (int i = 1; i < n; i++) {
            if (vec[i] < vec[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
