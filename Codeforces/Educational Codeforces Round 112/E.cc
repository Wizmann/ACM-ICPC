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
constexpr llint MAXN = 1234567;

struct Segment {
    int start, end, w;
};

class SegTree {
    static constexpr int root = 1;
public:
    SegTree(int m_) : seg(MAXN * 4, 0), lazy(MAXN * 4, 0), m(m_) {}

    void AddSeg(int l, int r) {
        Update(root, 1, m - 1, l, r - 1, 1);
    }
     
    void RemoveSeg(int l, int r) {
        Update(root, 1, m - 1, l, r - 1, -1);
    }

    int Query() {
        PushDown(root, 1, m - 1);
        return seg[root];
    }
     
private:
    void PushDown(int cur, int l, int r) {
        if (lazy[cur]) {
            seg[cur] += lazy[cur];
            if (l != r) {
                lazy[left(cur)] += lazy[cur];
                lazy[right(cur)] += lazy[cur];
            }
            lazy[cur] = 0;
        }
    }

    void Update(int cur, int l, int r, int ql, int qr, int delta) {
        PushDown(cur, l, r);
        if (r < ql || l > qr) {
            return;
        }
        if (ql <= l && r <= qr) {
            lazy[cur] += delta;
            PushDown(cur, l, r);
            return;
        }
        Update(left(cur), l, (l + r) / 2, ql, qr, delta);
        Update(right(cur), (l + r) / 2 + 1, r, ql, qr, delta);
        seg[cur] = min(seg[left(cur)], seg[right(cur)]);
    }

    int left(int x) {
        return x * 2;
    }

    int right(int x) {
        return x * 2 + 1;
    }
private:
    vector<int> seg;
    vector<int> lazy;
    int m;
};

vector<Segment> segs;
 
int main() {
    int n, m;
    input(n, m);

    int a, b, c;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        segs.push_back({a, b, c});
    }

    sort(segs.begin(), segs.end(), [](const Segment& s1, const Segment& s2) {
        return s1.w < s2.w;
    });

    SegTree segtree(m);

    int l = 0;
    int r = 0;
    int res = INF;
    while (l < n) {
        while (segtree.Query() == 0 && r < n) {
            segtree.AddSeg(segs[r].start, segs[r].end);
            r++;
        }
 
        if (segtree.Query() == 0) {
            break;
        }
 
        res = min(res, segs[r - 1].w - segs[l].w);
        segtree.RemoveSeg(segs[l].start, segs[l].end);
        l++;
    }
    print(res);

    return 0;
}

/*

^^^TEST^^^
5 12
1 5 5
3 4 10
4 10 6
11 12 5
10 12 3
-----
3
$$$TEST$$$

^^^TEST^^^
1 10
1 10 23
-----
0
$$$TEST$$$

*/
