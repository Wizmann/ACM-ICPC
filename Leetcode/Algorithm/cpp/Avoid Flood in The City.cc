class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> dry;
        const int n = rains.size();
        map<int, int> full;
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            int r = rains[i];
            if (r == 0) {
                dry.insert(i);
            } else if (full.count(r)) {
                int pre = full[r];
                auto iter = dry.upper_bound(pre);
                // cout << *iter << endl;
                if (iter == dry.end()) {
                    return {};
                } else {
                    res[*iter] = r;
                    dry.erase(iter);
                }
                full[r] = i;
            } else {
                full[r] = i;
            }
        }
        for (auto d: dry) {
            res[d] = 1;
        }
        return res;
    }
};
