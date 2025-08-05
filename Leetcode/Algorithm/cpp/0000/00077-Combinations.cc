class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> t;
        _combine(res, t, 1, n, k);
        return res;
    }
	void _combine(
            vector<vector<int> >& res, 
            vector<int>& t, 
            int st, 
            int end, 
            int k) {
        if (t.size() == k) {
            res.push_back(t);
        } else {
            for (int i = st; i <= end; i++) {
                t.push_back(i);
                _combine(res, t, i + 1, end, k);
                t.pop_back();
            }
        }
    }
};
