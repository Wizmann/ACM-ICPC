#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;
const int INF = 0x3f3f3f3f;

struct STree {
    int do_gcd(int a, int b) {
        if (a < b) {
            swap(a, b);
        }
        if (a % b == 0) {
            return b;
        }
        return do_gcd(b, a % b);
    }

    void init(int n) {
        do_init(0, n - 1, 0);
    }
    void do_init(int l, int r, int p) {
        if (l != r) {
            stree[p] = {l, r, INF, INF, 0};
        } else {
            stree[p] = {l, r, nums[l], nums[l], 1};
            return;
        }
        int m = (l + r) >> 1;
        do_init(l, m, LEFT(p));
        do_init(m + 1, r, RIGHT(p));
        do_merge(p);
    }

    void do_merge(int p) {
        int l = LEFT(p);
        int r = RIGHT(p);
        stree[p]._gcd = do_gcd(stree[l]._gcd, stree[r]._gcd);
        int cnt = 0;
        if (stree[p]._gcd % stree[l]._mini == 0) {
            stree[p]._mini = stree[l]._mini;
            cnt += stree[l]._mini_cnt;
        }
        if (stree[p]._gcd % stree[r]._mini == 0) {
            stree[p]._mini = stree[r]._mini;
            cnt += stree[r]._mini_cnt;
        }
        stree[p]._mini_cnt = cnt;
    }

    int search(int l, int r) {
        int gcd, mini, mini_cnt;
        return do_search(l, r, 0, gcd, mini, mini_cnt);
    }

    int do_search(int l, int r, int p, 
            int& gcd, int& mini, int& mini_cnt) {
        if (stree[p].equal(l, r)) {
            gcd = stree[p]._gcd;
            mini = stree[p]._mini;
            mini_cnt = stree[p]._mini_cnt;
            if (gcd % mini == 0) {
                return mini_cnt;
            } else {
                return 0;
            }
        }

        int m = stree[p].mid();
        if (r <= m) {
            return do_search(l, r, LEFT(p), gcd, mini, mini_cnt);
        } else if (l > m) {
            return do_search(l, r, RIGHT(p), gcd, mini, mini_cnt);
        } else {
            int lgcd, lmini, lmini_cnt;
            int rgcd, rmini, rmini_cnt;
            do_search(l, m, LEFT(p), lgcd, lmini, lmini_cnt);
            do_search(m + 1, r, RIGHT(p), rgcd, rmini, rmini_cnt);
            int res = 0;
            mini = INF;
            if (rgcd % lmini == 0) {
                res += lmini_cnt;
                mini = lmini;
            }
            if (lgcd % rmini == 0) {
                res += rmini_cnt;
                mini = rmini;
            }
            gcd = do_gcd(lgcd, rgcd);
            mini_cnt = res;
            return res;
        }
    }
        
    inline int LEFT(int x) { return 2 * x + 1; }
    inline int RIGHT(int x) { return 2 * x + 2; }
    struct node {
        int l, r;
        int _gcd, _mini, _mini_cnt;
        bool equal(int il, int ir) { return l == il && r == ir; }
        int mid() { return (l + r) >> 1; }
    };
    int nums[SIZE];
    node stree[SIZE * 8];
};

int n, q;
STree st;

int main()
{
    freopen("f.txt", "r", stdin);
    int l, r ;
    input(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &st.nums[i]);
    }
    st.init(n);
    input(q);
    while (q--) {
        scanf("%d %d", &l, &r);
        print(r - l + 1 - st.search(l -1 , r - 1));
    }
    return 0;
}

