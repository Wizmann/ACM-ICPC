class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        ans.clear();
        mmp.clear();
        int n = num.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int s = num[i] + num[j];
                mmp.insert(mkpair(s, i, j));
                auto range = mmp.equal_range(target-s);
                for (auto iter = range.first; iter != range.second; ++iter) {
                    auto p = iter -> second;
                    int a = p.first, b = p.second;
                    if (a != i && a != j && b != i && b != j) {
                        append_record(num, a, b, i, j);
                    }
                }
            }
        }
        vector<vector<int> > res;
        copy(ans.begin(), ans.end(), back_inserter(res));
        return res;
    }
private:
    void append_record(vector<int> &num, int a, int b, int c ,int d) {
        vector<int> vec({a, b, c, d});
        for (int i = 0; i < 4; i++) {
            vec[i] = num[vec[i]];
        }
        sort(vec.begin(), vec.end());
        ans.insert(vec);
    }
    pair<int, pair<int, int> > mkpair(int s, int a, int b) {
        return make_pair<int, pair<int, int> >(int(s),
                make_pair<int, int>(int(a), int(b)));
    }
private:
    set<vector<int> > ans;
    unordered_multimap<int, pair<int, int> > mmp;
};
