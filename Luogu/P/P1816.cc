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
        int tag;
    };
public:
    SegmentTree(int m_) : m(m_) {
        tag = vector<LazyTag>(m * 4, {0});
        seg = vector<int>(m * 4, 0);
    };

    void Assign(int ql, int qr, int k) {
        return do_Assign(root, 1, m, ql, qr, k);
    }

    int Query(int ql, int qr) {
        return do_Query(root, 1, m, ql, qr);
    }
private:
    inline int left(int x) { return x * 2; }
    inline int right(int x) { return x * 2 + 1; }

    void PushDown(int cur, int l, int r) {
        if (tag[cur].tag) {
            seg[cur] = tag[cur].tag;
            if (l != r) {
                tag[left(cur)].tag = tag[cur].tag;
                tag[right(cur)].tag = tag[cur].tag;
            }
            tag[cur].tag = 0;
        }
    }

    void do_Assign(int cur, int l, int r, int ql, int qr, int k) {
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return;
        }

        if (l >= ql && qr >= r) {
            tag[cur] = {k};
            PushDown(cur, l, r);
            return;
        }

        assert(l != r);

        do_Assign(left(cur), l, (l + r) / 2, ql, qr, k);
        do_Assign(right(cur), (l + r) / 2 + 1, r, ql, qr, k);
        seg[cur] = min(calc(left(cur), l, (l + r) / 2),
                       calc(right(cur), (l + r) / 2 + 1, r));
    }

    int do_Query(int cur, int l, int r, int ql, int qr) {
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return INF;
        }

        if (l >= ql && qr >= r) {
            return calc(cur, l, r);
        }

        assert(l != r);

        return min(do_Query(left(cur), l, (l + r) / 2, ql, qr),
                   do_Query(right(cur), (l + r) / 2 + 1, r, ql, qr));
    }

    int calc(int cur, int l, int r) {
        (void)l;
        (void)r;
        if (tag[cur].tag) {
            return tag[cur].tag;
        } else {
            return seg[cur];
        }
    }

private:
    int m;

    vector<LazyTag> tag;
    vector<int> seg;
};

int main() {
    int n, q;
    input(n, q);

    SegmentTree segTree(n);

    int a, b;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        segTree.Assign(i, i, a);
        // assert(segTree.Query(i, i) == a);
    }

    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &a, &b);
        printf("%d ", segTree.Query(a, b));
        /*
        for (int j = 1; j <= n; j++) {
            printf("%d ", segTree.Query(j, j));
        }
        puts("");
        */
    }
    puts("");
    return 0;
}

/*

^^^TEST^^^
10 3
1 2 3 4 5 6 7 8 9 10
2 7
3 9
1 10
-----
2 3 1
$$$TEST$$$

*/
