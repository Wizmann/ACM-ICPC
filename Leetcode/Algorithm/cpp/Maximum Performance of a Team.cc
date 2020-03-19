const int MOD = 1000000000 + 7;

typedef long long llint;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int> > ps;
        for (int i = 0; i < n; i++) {
            ps.push_back({efficiency[i], speed[i]});
        }
        sort(ps.begin(), ps.end());
        multiset<pair<int, int> > left;
        multiset<pair<int, int> > right;
        for (int i = 0; i < n; i++) {
            left.insert({speed[i], efficiency[i]});
        }
        llint ans = 0;
        llint tot = 0;
        for (const auto& p: ps) {
            decltype(p) q = {p.second, p.first};
            auto iter = right.find(q);
            if (iter != right.end()) {
                tot -= q.first;
                right.erase(iter);
            } else {
                iter = left.find(q);
                left.erase(iter);
            }
            
            while (!left.empty() && right.size() < k - 1) {
                iter = --left.end();
                right.insert(*iter);
                tot += iter->first;
                left.erase(iter);
            }
            
            ans = max(ans, 1LL * (tot + q.first) * q.second);
        }
        return ans % MOD;
    }
};
