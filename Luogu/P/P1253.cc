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

    struct LazyTag {
        llint assign, add;
    };
public:
    SegmentTree(int m_) : m(m_) {
        tag = vector<LazyTag>(m * 4, {-INFLL, 0});
        seg = vector<llint>(m * 4, 0);
    };

    void Assign(int ql, int qr, int k) {
        return do_Assign(root, 1, m, ql, qr, k);
    }

    void Add(int ql, int qr, int k) {
        return do_Add(root, 1, m, ql, qr, k);
    }

    llint Query(int ql, int qr) {
        return do_Query(root, 1, m, ql, qr);
    }
private:
    inline int left(int x) { return x * 2; }
    inline int right(int x) { return x * 2 + 1; }

    void PushDown(int cur, int l, int r) {
        if (tag[cur].assign != -INFLL || tag[cur].add) {
            if (l != r) {
                if (tag[cur].assign != -INFLL) {
                    tag[left(cur)] = tag[cur];
                    tag[right(cur)] = tag[cur];
                } else {
                    tag[left(cur)].add += tag[cur].add;
                    tag[right(cur)].add += tag[cur].add;
                }
                seg[cur] = max(calc(left(cur), l, (l + r) / 2),
                               calc(right(cur), (l + r) / 2 + 1, r));
            } else {
                if (tag[cur].assign != -INFLL) {
                    seg[cur] = tag[cur].assign + tag[cur].add;
                } else {
                    seg[cur] += tag[cur].add;
                }
            }

            tag[cur] = {-INFLL, 0};
        }
    }

    void do_Assign(int cur, int l, int r, int ql, int qr, int k) {
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return;
        }

        if (l >= ql && qr >= r) {
            tag[cur] = {k, 0};
            PushDown(cur, l, r);
            return;
        }

        assert(l != r);

        do_Assign(left(cur), l, (l + r) / 2, ql, qr, k);
        do_Assign(right(cur), (l + r) / 2 + 1, r, ql, qr, k);
        seg[cur] = max(calc(left(cur), l, (l + r) / 2),
                       calc(right(cur), (l + r) / 2 + 1, r));
    }

    void do_Add(int cur, int l, int r, int ql, int qr, int k) {
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
        seg[cur] = max(calc(left(cur), l, (l + r) / 2),
                       calc(right(cur), (l + r) / 2 + 1, r));
    }

    llint do_Query(int cur, int l, int r, int ql, int qr) {
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return -INFLL;
        }

        if (l >= ql && qr >= r) {
            return calc(cur, l, r);
        }

        assert(l != r);

        return max(do_Query(left(cur), l, (l + r) / 2, ql, qr),
                   do_Query(right(cur), (l + r) / 2 + 1, r, ql, qr));
    }

    llint calc(int cur, int l, int r) {
        (void)l;
        (void)r;
        if (tag[cur].assign != -INFLL) {
            return tag[cur].assign + tag[cur].add;
        } else {
            return seg[cur] + tag[cur].add;
        }
    }

private:
    int m;

    vector<LazyTag> tag;
    vector<llint> seg;
};

int main() {
    int n, q;
    input(n, q);

    SegmentTree segTree(n + 1);

    int a, b, c;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        segTree.Assign(i, i, a);
        // assert(segTree.Query(i, i) == a);
    }

    for (int i = 1; i <= q; i++) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &a, &b, &c);
            segTree.Assign(a, b, c);
        } else if (a == 2) {
            scanf("%d%d%d", &a, &b, &c);
            segTree.Add(a, b, c);
        } else if (a == 3) {
            scanf("%d%d", &a, &b);
            printf("%lld\n", segTree.Query(a, b));
        } else {
            assert(false);
        }

        /*
        for (int j = 1; j <= n; j++) {
            printf("%d ", segTree.Query(j, j));
        }
        puts("");
        */
    }
    return 0;
}

/*

^^^TEST^^^
6 6
1 1 4 5 1 4
1 1 2 6
2 3 4 2
3 1 4
3 2 3
1 1 6 -1
3 1 6
-----
7
6
-1
$$$TEST$$$

^^^TEST^^^
4 4
10 4 -3 -7
1 1 3 0
2 3 4 -4
1 2 4 -9
3 1 4
-----
0
$$$TEST$$$

*/
