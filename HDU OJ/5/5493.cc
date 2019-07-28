#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int lowbit(int x) {
    return x & (-x);
}

class Bitree {
public:
    Bitree(int n_) : n(n_), tree(n + 1, 0) {
        // pass
    }

    void add(int pos, int value) {
        while (pos <= n) {
            tree[pos] += value;
            pos += lowbit(pos);
        }
    }

    int query(int pos) {
        int res = 0;
        while (pos) {
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
private:
    int n;
    vector<int> tree;
};

int do_place(Bitree& tree, int n, int v, int k) {
    int l = 1;
    int r = n;
    while (l <= r) {
        int m = (l + r) >> 1;
        int u = m - 1 - tree.query(m);
        if (u < k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    if (l < 1 || l > n) {
        return -1;
    }
    if (tree.query(l, l) != 0) {
        return -1;
    }
    int u = l - 1 - tree.query(l);
    if (u != k) {
        return -1;
    }
    return l;
}

int place(Bitree& tree, int n, int v, int k1, int k2) {
    // print(n << ' ' << v << ' ' << k1 << ' ' << k2);
    int idx1 = do_place(tree, n, v, k1);
    int idx2 = do_place(tree, n, v, k2);
    if (max(idx1, idx2) == -1) {
        return -1;
    }
    int idx = -1;
    if (min(idx1, idx2) == -1) {
        idx = idx1 != -1? idx1: idx2;
    } else {
        idx = min(idx1, idx2);
    }
    tree.add(idx, 1);
    return idx;
}

int main() {
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        int n;
        input(n);

        vector<pair<int, int> > ps;
        Bitree tree(n);
        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            ps.push_back(pair<int, int>(a, b));
        }
        sort(ps.begin(), ps.end());

        bool flag = true;
        vector<int> res(n + 1, -1);

        for (int i = 0; i < n; i++) {
            const pair<int, int>& p = ps[i];
            a = p.first;
            b = p.second;
            int b1 = min(b, n - i - 1 - b);
            int b2 = max(b, n - i - 1 - b);
            int idx = place(tree, n, a, b1, b2);
            if (idx == -1) {
                flag = false;
                break;
            }
            res[idx] = a;
        }

        printf("Case #%d: ", ++case_);

        if (flag == false) {
            puts("impossible");
        } else {
            for (int i = 1; i <= n; i++) {
                if (i > 1) {
                    printf(" ");
                }
                printf("%d", res[i]);
            }
            puts("");
        }
    }
    return 0;
}
