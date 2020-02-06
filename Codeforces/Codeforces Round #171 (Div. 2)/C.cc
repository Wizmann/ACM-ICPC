#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 123456;
const int LOGN = 17;
const int INF = 0x3f3f3f3f;

class RMQ {
public:
    RMQ(int n_, const vector<int>& nums_) : n(n_) {
        for (int i = 0; i <= LOGN; i++) {
            nums[i] = vector<pair<int, int> >(n, {0, 0});
        }

        for (int i = 0; i < n; i++) {
            nums[0][i] = {nums_[i], i};
        }

        doInit();
    }

    pair<int, int> query(int a, int b) {
        int dis = b - a + 1;
        pair<int, int> maxi = {-INF, -INF};

        for (int i = LOGN; i >= 0; i--) {
            if (dis & (1 << i)) {
                maxi = max(maxi, nums[i][a]);
                a += 1 << i;
            }
        }
        return maxi;
    }
private:
    void doInit() {
        for (int i = 1; i <= LOGN; i++) {
            for (int j = 0; j < n; j++) {
                int l = j;
                int r = min(n - 1, j + (1 << (i - 1)));
                nums[i][j] = max(nums[i - 1][l], nums[i - 1][r]);
            }
        }
    }
private:
    int n;
    vector<pair<int, int> > nums[LOGN + 1];
};

void makeLR(const vector<int>& ns, vector<int>& ls, vector<int>& rs) {
    int n = ns.size();
    {
        int pre = INF;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ns[i] >= pre) {
                cnt++;
            } else {
                cnt = 1;
            }

            ls[i] = cnt;

            pre = ns[i];
        }
    }
    {
        int pre = INF;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (ns[i] >= pre) {
                cnt++;
            } else {
                cnt = 1;
            }

            rs[i] = cnt;

            pre = ns[i];
        }
    }
}

void test() {
    vector<int> ns = {1, 2, 1, 3, 3, 5, 2, 1};
    int n = ns.size();
    auto r = RMQ(n, ns);

    assert((r.query(0, 1) == pair<int, int>{2, 1}));
    assert((r.query(0, 2) == pair<int, int>{2, 1}));
    assert((r.query(0, 3) == pair<int, int>{3, 3}));

    assert((r.query(1, 1) == pair<int, int>{2, 1}));
    assert((r.query(1, 2) == pair<int, int>{2, 1}));
    assert((r.query(1, 5) == pair<int, int>{5, 5}));

    vector<int> ls(n), rs(n);
    makeLR(ns, ls, rs);

    assert((ls == vector<int>{1, 2, 1, 2, 3, 4, 1, 1}));
    assert((rs == vector<int>{1, 2, 1, 2, 1, 3, 2, 1}));
}

int main() {
    test();

    int n, q;
    input(n >> q);

    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    auto r = RMQ(n, ns);
    vector<int> ls(n), rs(n);

    makeLR(ns, ls, rs);

    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;

        auto maxip = r.query(a, b);

        int idx = maxip.second;

        int l = idx - ls[idx] + 1;
        int r = idx + rs[idx] - 1;

        if (l <= a && b <= r) {
            puts("Yes");
        } else {
            puts("No");
        }
    }

    return 0;
}
