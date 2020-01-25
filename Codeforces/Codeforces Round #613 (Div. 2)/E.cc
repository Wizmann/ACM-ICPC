#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#include <deque>
 
using namespace std;
 
#define input(x) cin >> x
#define print(x) cout << x << endl
 
const int INF = 0x3f3f3f3f;
 
typedef long long llint;
 
struct Interval {
    int l, r;
 
    bool operator < (const Interval& other) const {
        return r < other.l;
    }
};
 
bool do_intersect(const Interval& i1, const Interval& i2) {
    return !(i1 < i2) && !(i2 < i1);
}
 
int main() {
    int T;
    input(T);
    while (T--) {
        int n;
        input(n);
        vector<Interval> intervals;
 
        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            intervals.push_back({a, b});
        }
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) {
            if (i1.l != i2.l) {
                return i1.l < i2.l;
            }
            return i1.r < i2.r;
        });
 
        vector<pair<int, int> > dp1(n);
 
        int maxi = -INF;
        set<Interval> st;
        for (int i = 0; i < n; i++) {
            auto iter = st.find(intervals[i]);
            if (iter == st.end()) {
                st.insert(intervals[i]);
            } else {
                auto cur = *iter;
                st.erase(iter);
                cur.r = max(cur.r, intervals[i].r);
                st.insert(cur);
            }
            maxi = max(maxi, intervals[i].r);
 
            dp1[i] = {st.size(), maxi};
        }
 
        int res = 0;
        deque<Interval> ps;
        for (int i = n - 1; i >= 0; i--) {
            int pre = i == 0? 0: dp1[i - 1].first;
            int nxt = i == 0? -INF: dp1[i - 1].second;
 
            Interval pi = {-INF, nxt};
            auto iter = upper_bound(ps.begin(), ps.end(), pi);
            res = max(res, int(pre + ps.size() - (iter - ps.begin())));
 
            auto cur = intervals[i];
            while (!ps.empty() && do_intersect(cur, *ps.begin())) {
                cur.r = max(cur.r, int(ps.begin()->r));
                ps.pop_front();
            }
            ps.push_front(cur);
        }
        print(res);
    }
    return 0;
}
