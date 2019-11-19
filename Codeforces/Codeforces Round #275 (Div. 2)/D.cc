#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define input(x) cin >> x
#define print(x) cout << x << endl

class SegmentTree {
public:
    SegmentTree(const vector<int>& ns): n(ns.size()) {
        init(0, n - 1, ns);
    }

    int query(int l, int r) {
        return do_query(0, l, r);
    }

    void add(int l, int r, int v) {
        return do_add(0, l, r, v);
    }
private:
    struct SegmentTreeNode {
        int l, r;
        int lp, rp;
        int lazy, update;
    };

    int init(int l, int r, const vector<int>& ns) {
        tree.push_back(SegmentTreeNode());
        int cur = tree.size() - 1;

        tree[cur].l = l;
        tree[cur].r = r;
        tree[cur].lp = 0;
        tree[cur].rp = 0;
        tree[cur].update = 0;
        if (l == r) {
            tree[cur].lazy = ns[l];
            tree[cur].lp = -1;
            tree[cur].rp = -1;
        } else {
            int m = (l + r) >> 1;
            int t1 = init(l, m, ns);
            tree[cur].lp = t1;
            int t2 = init(m + 1, r, ns);
            tree[cur].rp = t2;
            tree[cur].lazy = tree[tree[cur].lp].lazy & tree[tree[cur].rp].lazy;
        }

        assert(tree[cur].lp != 0 && tree[cur].rp != 0);
        return cur;
    }

    void push_down(int cur) {
        if (tree[cur].update) {
            tree[tree[cur].lp].update |= tree[cur].update;
            tree[tree[cur].lp].lazy |= tree[cur].update;

            tree[tree[cur].rp].update |= tree[cur].update;
            tree[tree[cur].rp].lazy |= tree[cur].update;

            tree[cur].update = 0;
        }
    }

    void push_up(int cur) {
        tree[cur].lazy = tree[tree[cur].lp].lazy & tree[tree[cur].rp].lazy;
        assert(tree[cur].update == 0);
    }

    int do_query(int cur, int l, int r) {
        assert(tree[cur].l <= l && l <= r && r <= tree[cur].r);

        if (l == tree[cur].l && r == tree[cur].r) {
            return tree[cur].lazy;
        }

        push_down(cur);
        int m = (tree[cur].l + tree[cur].r) >> 1;

        int res = -999;
        if (r <= m) {
            res = do_query(tree[cur].lp, l, r);
        } else if (l >= m + 1) {
            res = do_query(tree[cur].rp, l, r);
        } else {
            res = do_query(tree[cur].lp, l, m) & do_query(tree[cur].rp, m + 1, r);
        }

        push_up(cur);
        return res;
    }

    void do_add(int cur, int l, int r, int v) {
        assert(tree[cur].l <= l && l <= r && r <= tree[cur].r);

        if (l == tree[cur].l && r == tree[cur].r) {
            tree[cur].update |= v;
            tree[cur].lazy |= v;
            return;
        }

        push_down(cur);

        int m = (tree[cur].l + tree[cur].r) >> 1;

        if (r <= m) {
            do_add(tree[cur].lp, l, r, v);
        } else if (l >= m + 1) {
            do_add(tree[cur].rp, l, r, v);
        } else {
            do_add(tree[cur].lp, l, m, v);
            do_add(tree[cur].rp, m + 1, r, v);
        }

        push_up(cur);
    }
private:
    int n;
    vector<SegmentTreeNode> tree;
};

struct Query {
    int l, r, v;
};

int main() {
    int n, q;
    input(n >> q);

    vector<int> ns(n, 0);
    auto tree = SegmentTree(ns);

    vector<Query> qs;
    int a, b, c;
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        qs.push_back({a, b, c});
        tree.add(a, b, c);
    }

    bool flag = true;
    for (int i = 0; i < q; i++) {
        auto q = qs[i];
        int u = tree.query(q.l, q.r);
        if (u != q.v) {
            flag = false;
            break;
        }
    }

    if (flag == false) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i < n; i++) {
            ns[i] = tree.query(i, i);
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", ns[i]);
        }
        puts("");
    }

    return 0;
}
