#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

class Solution {
public:
    Solution(int n_, const vector<int>& nums) : n(n_) {
        for (int i = 0; i < n; i++) {
            ps.push_back({nums[i], i});
        }
        sort(ps.begin(), ps.end());
    }

    vector<int> solve() {
        res.resize(n);
        do_solve(0, n);
        return res;
    }
private:
    void do_solve(int l, int r) {
        if (l == r) {
            return;
        }
        
        assert (l >= 0 && l < n);
        assert (r >= 0 && r <= n);
        
        int mini = ps[l].first;

        int mini_cnt = 0;
        for (int i = l; i < r; i++) {
            if (ps[i].first == mini) {
                mini_cnt++;
            }
        }

        int cur = l + mini_cnt / 2;
        assert (0 <= cur && cur < n);
        swap(ps[l], ps[cur]);

        int ll = l;
        int rr = r - 1;
        int mid = ps[l].second;

        for (int i = r - 1; i >= l; i--) {
            int value = ps[i].first;
            int pos = ps[i].second;
            
            assert (value - mini < n);
            assert (value - mini >= 0);

            if (pos > mid && pos <= rr) {
                res[value - mini] += (mid - ll + 1) * (rr - pos + 1);
                rr = pos - 1;
            } else if (pos < mid && pos >= ll) {
                res[value - mini] += (rr - mid + 1) * (pos - ll + 1);
                ll = pos + 1;
            } else if (pos == mid) {
                res[0]++;
                ll = rr = pos;
            }
        }

        int pivot = partition(l, r, l);
        sort(ps.begin() + l, ps.begin() + pivot);
        sort(ps.begin() + pivot + 1, ps.begin() + r);
        do_solve(l, pivot);
        do_solve(pivot + 1, r);
    }

    int partition(int l, int r, int pidx) {
        swap(ps[l], ps[pidx]);

        int pivot = ps[l].second;

        int ll = l;
        int rr = r - 1;
        while (ll <= rr) {
            while (ll <= rr && ps[ll].second <= pivot) {
                assert (0 <= ll && ll < n);
                ll++;
            }
            while (ll <= rr && ps[rr].second > pivot) {
                assert (0 <= rr && rr < n);
                rr--;
            }
            if (ll <= rr) {
                assert (0 <= ll && ll < n);
                assert (0 <= rr && rr < n);
                swap(ps[ll], ps[rr]);
                ll++;
                rr--;
            }
        }
        assert (0 <= l && l < n);
        assert (0 <= rr && rr < n);
        swap(ps[l], ps[rr]);
        return rr;
    }
private:
    int n;
    vector<pair<int, int> > ps;
    vector<int> res;
};

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    input(T);
    while (T--) {
        int n;
        vector<int> ns;

        input(n);
        ns.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        auto S = Solution(n, ns);
        auto res = S.solve();

        llint prev = 0;
        for (auto num: res) {
            printf("%lld\n", 1LL * num + prev);
            prev += num;
        }
    }
    return 0;
}

