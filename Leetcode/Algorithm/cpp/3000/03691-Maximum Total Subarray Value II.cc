using llint = long long;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<pair<int, int> > ps;
        for (int i = 0; i < n; i++) {
            ps.push_back({ nums[i], i });
        }
        sort(ps.begin(), ps.end());

        vector<int> left_lt(n, -1);
        vector<int> right_lt(n, -1);
        set<int> st;
        for (auto p : ps) {
            int pos = p.second;
            left_lt[pos] = -1;
            right_lt[pos] = n;

            if (!st.empty()) {
                auto iter = st.upper_bound(pos);
                if (iter != st.end()) {
                    right_lt[pos] = *iter;
                }
                if (iter != st.begin()) {
                    --iter;
                    left_lt[pos] = *iter;
                }
            }
            st.insert(pos);
        }

        st.clear();
        vector<int> left_gt(n, INF);
        vector<int> right_gt(n, -1);
        reverse(ps.begin(), ps.end());

        for (auto p : ps) {
            int pos = p.second;
            left_gt[pos] = -1;
            right_gt[pos] = n;

            if (!st.empty()) {
                auto iter = st.upper_bound(pos);
                if (iter != st.end()) {
                    right_gt[pos] = *iter;
                }
                if (iter != st.begin()) {
                    --iter;
                    left_gt[pos] = *iter;
                }
            }
            st.insert(pos);
        }

        reverse(ps.begin(), ps.end());

        auto cmp = [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            assert(0 <= p1.first && p1.first < n);
            assert(0 <= p2.first && p2.first < n);
            assert(0 <= p1.second && p1.second < n);
            assert(0 <= p2.second && p2.second < n);
            return abs(ps[p1.first].first - ps[p1.second].first) < abs(ps[p2.first].first - ps[p2.second].first);
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        pq.push({0, n - 1});
        llint rem = k;
        llint res = 0;
        set<pair<int, int>> visited;
        while (!pq.empty() && rem) {
            if (rem <= 0) {
                break;
            }
            pair<int, int> p = pq.top();
            pq.pop();
            if (visited.count(p)) {
                continue;
            }
            visited.insert(p);

            int l = p.first;
            int r = p.second;
            if (ps[l].second > ps[r].second) {
                swap(l, r);
            }

            int lpos = ps[l].second;
            int lvalue = ps[l].first;
            int rpos = ps[r].second;
            int rvalue = ps[r].first;
            assert(lpos <= rpos);

            int l_limit_l = 0;
            int l_limit_r = 0;
            int r_limit_l = 0;
            int r_limit_r = 0;

            if (lvalue <= rvalue) {
                l_limit_l = left_lt[lpos];
                l_limit_r = right_lt[lpos];
                r_limit_l = left_gt[rpos];
                r_limit_r = right_gt[rpos];
            } else {
                l_limit_l = left_gt[lpos];
                l_limit_r = right_gt[lpos];
                r_limit_l = left_lt[rpos];
                r_limit_r = right_lt[rpos];
            }

            if (l_limit_r >= rpos && r_limit_l <= lpos) {
                llint cnt = min(rem, 1LL * (lpos - max(l_limit_l, r_limit_l)) * (min(l_limit_r, r_limit_r) - rpos));
                res += 1LL * abs(lvalue - rvalue) * cnt;
                rem -= cnt;
            }

            if (l > r) {
                swap(l, r);
            }

            if (l + 1 < r) {
                pq.push({l + 1, r});
            }
            if (l < r - 1) {
                pq.push({l, r - 1});
            }
        }
        return res;
    }
};

