#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

class SegmentTree {
    static constexpr int root = 1;

    struct Value {
        double x, x2;
    };

    struct LazyTag {
        double add;
    };
public:
    SegmentTree(int m_) : m(m_) {
        tag = vector<LazyTag>(m * 4, {0});
        seg = vector<Value>(m * 4, {0, 0});
    };

    void Add(int ql, int qr, double k) {
        return do_Add(root, 1, m, ql, qr, k);
    }

    void Query(int ql, int qr, double& x, double& x2) {
        return do_Query(root, 1, m, ql, qr, x, x2);
    }

private:
    inline int left(int x) { return x * 2; }
    inline int right(int x) { return x * 2 + 1; }

    void PushDown(int cur, int l, int r) {
        if (tag[cur].add) {
            double x = 0;
            double x2 = 0;
            calc(cur, l, r, x, x2);
            seg[cur] = {x, x2};
            if (l != r) {
                tag[left(cur)].add += tag[cur].add;
                tag[right(cur)].add += tag[cur].add;
            }
            tag[cur].add = 0;
        }
    }

    void do_Add(int cur, int l, int r, int ql, int qr, double k) {
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return;
        }

        if (l >= ql && qr >= r) {
            tag[cur].add += k;
            PushDown(cur, l, r);
            return;
        }

        assert(l != r);

        do_Add(left(cur), l, (l + r) / 2, ql, qr, k);
        do_Add(right(cur), (l + r) / 2 + 1, r, ql, qr, k);
        PushUp(cur, l, r);
    }

    void do_Query(int cur, int l, int r, int ql, int qr, double& x, double& x2) {
        x = 0;
        x2 = 0;
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return;
        }

        if (l >= ql && qr >= r) {
            x = seg[cur].x;
            x2 = seg[cur].x2;
            return;
        }

        assert(l != r);

        double a = 0;
        double a2 = 0;
        do_Query(left(cur), l, (l + r) / 2, ql, qr, a, a2);

        double b = 0;
        double b2 = 0;
        do_Query(right(cur), (l + r) / 2 + 1, r, ql, qr, b, b2);

        x = a + b;
        x2 = a2 + b2;
    }

    void PushUp(int cur, int l, int r) {
        assert(l != r);

        double a = 0;
        double a2 = 0;
        calc(left(cur), l, (l + r) / 2, a, a2);

        double b = 0;
        double b2 = 0;
        calc(right(cur), (l + r) / 2 + 1, r, b, b2);

        seg[cur].x = a + b;
        seg[cur].x2 = a2 + b2;
    }

    void calc(int cur, int l, int r, double& x, double& x2) {
        (void)l;
        (void)r;

        x = seg[cur].x + tag[cur].add * (r - l + 1);
        x2 = seg[cur].x2 + 2 * seg[cur].x * tag[cur].add + (tag[cur].add * tag[cur].add) * (r - l + 1);
    }

private:
    int m;

    vector<LazyTag> tag;
    vector<Value> seg;
};

int main() {
    int n, q;
    input(n, q);

    SegmentTree segTree(n);

    double v;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &v);
        segTree.Add(i, i, v);
        // assert(segTree.Query(i, i) == a);
    }

    int a, b, c;
    for (int i = 1; i <= q; i++) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%lf", &b, &c, &v);
            segTree.Add(b, c, v);
        } else if (a == 2) {
            scanf("%d%d", &b, &c);
            double x, x2;
            segTree.Query(b, c, x, x2);
            printf("%.4lf\n", x / (c - b + 1));
        } else if (a == 3) {
            scanf("%d%d", &b, &c);
            double x, x2;
            segTree.Query(b, c, x, x2);
            double e_x2 = x2 / (c - b + 1);
            double e_x = x / (c - b + 1);
            printf("%.4lf\n", e_x2 - e_x * e_x);
        }
        /*
        for (int j = 1; j <= n; j++) {
            double x, x2;
            segTree.Query(j, j, x, x2);
            printf("%.4lf ", x);
        }
        puts("");
        */
    }
    return 0;
}

/*

^^^TEST^^^
5 5
1 5 4 2 3
2 1 4
3 1 5
1 1 1 1
1 2 2 -1
3 1 5
-----
3.0000
2.0000
0.8000
$$$TEST$$$

^^^TEST^^^
2 2
1 1 
1 1 2 1
2 1 2
-----
2.0000
$$$TEST$$$

^^^TEST^^^
5 2
1 1 1 1 1
1 1 5 1
2 1 2
-----
2.0000
$$$TEST$$$

*/
