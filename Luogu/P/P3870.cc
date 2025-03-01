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
        int lazy;
    };
public:
    SegmentTree(int m_) : m(m_) {
        tag = vector<LazyTag>(m * 4, {0});
        seg = vector<int>(m * 4, 0);
    };

    void Modify(int ql, int qr) {
        return do_Modify(root, 1, m, ql, qr);
    }

    int Query(int ql, int qr) {
        return do_Query(root, 1, m, ql, qr);
    }
private:
    inline int left(int x) { return x * 2; }
    inline int right(int x) { return x * 2 + 1; }

    void PushDown(int cur, int l, int r) {
        if (tag[cur].lazy) {
            seg[cur] = (r - l + 1) - seg[cur];

            if (l != r) {
                tag[left(cur)].lazy ^= 1;
                tag[right(cur)].lazy ^= 1;
            }

            tag[cur] = {0};
        }
    }

    void do_Modify(int cur, int l, int r, int ql, int qr) {
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return;
        }

        if (l >= ql && qr >= r) {
            tag[cur].lazy ^= 1;
            PushDown(cur, l, r);
            return;
        }

        assert(l != r);

        do_Modify(left(cur), l, (l + r) / 2, ql, qr);
        do_Modify(right(cur), (l + r) / 2 + 1, r, ql, qr);
        seg[cur] = calc(left(cur), l, (l + r) / 2) + calc(right(cur), (l + r) / 2 + 1, r);
    }

    int do_Query(int cur, int l, int r, int ql, int qr) {
        PushDown(cur, l, r);

        if (l > qr || r < ql) {
            return 0;
        }

        if (l >= ql && qr >= r) {
            return calc(cur, l, r);
        }

        assert(l != r);

        int res = 0;
        res += do_Query(left(cur), l, (l + r) / 2, ql, qr);
        res += do_Query(right(cur), (l + r) / 2 + 1, r, ql, qr);

        return res;
    }

    int calc(int cur, int l, int r) {
        if (tag[cur].lazy) {
            return (r - l + 1) - seg[cur];
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

    SegmentTree segTree(n + 1);

    int a, b, c;
    for (int i = 1; i <= q; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0) {
            segTree.Modify(b + 1, c + 1);
        } else {
            printf("%d\n", segTree.Query(b + 1, c + 1));
        }
    }
    return 0;
}

/*

^^^TEST^^^
4 5
0 1 2
0 2 4
1 2 3
0 2 4
1 1 4
-----
1
2
$$$TEST$$$

*/
