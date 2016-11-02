class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> mp;
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            const auto& interval = intervals[i];
            int x = interval.start;
            if (mp.find(x) == mp.end()) {
                mp[x] = i;
            }
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            const auto& interval = intervals[i];
            auto iter = mp.lower_bound(interval.end);
            if (iter == mp.end()) {
                ans[i] = -1;
            } else {
                ans[i] = iter->second;
            }
        }
        return ans;
    }
};
