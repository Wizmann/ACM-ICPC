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

class SegTree {
    static constexpr int root = 1;
public:
    SegTree() {}

    void Init(const vector<int>& xs_) {
        xs = xs_;

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        m = xs.size();
        for (int i = 0; i < m; i++) {
            mp[xs[i]] = i;
        }

        Clear();
    }

    void Clear() {
        seg = vector<int>(m * 4, 0);
        lazy = vector<int>(m * 4, 0);
        cover = vector<int>(m * 4, 0);
    }

    void AddSeg(int l, int r) {
        assert(l != r);
        l = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
        r = lower_bound(xs.begin(), xs.end(), r) - xs.begin() - 1;
        assert(l != 0 && r != 0);
        Update(root, 1, m - 1, l, r, 1);
    }
     
    void RemoveSeg(int l, int r) {
        assert(l != r);
        l = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
        r = lower_bound(xs.begin(), xs.end(), r) - xs.begin() - 1;
        assert(l != 0 && r != 0);
        Update(root, 1, m - 1, l, r, -1);
    }

    int Query() {
        PushDown(root, 1, m - 1);
        return cover[root];
    }
     
private:
    void PushDown(int cur, int l, int r) {
        if (lazy[cur]) {
            seg[cur] += lazy[cur];
            if (l != r) {
                lazy[left(cur)] += lazy[cur];
                lazy[right(cur)] += lazy[cur];
            }
            if (seg[cur] > 0) {
                assert(r + 1 < (int)xs.size());
                cover[cur] = xs[r + 1] - xs[l];
            } else if (l != r) {
                int m = (l + r) / 2;
                PushDown(left(cur), l, m);
                PushDown(right(cur), m + 1, r);
                seg[cur] = min(seg[left(cur)], seg[right(cur)]);
                cover[cur] = cover[left(cur)] + cover[right(cur)];
            } else {
                cover[cur] = 0;
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
        if (l < r) {
            Update(left(cur), l, (l + r) / 2, ql, qr, delta);
            Update(right(cur), (l + r) / 2 + 1, r, ql, qr, delta);
            seg[cur] = min(seg[left(cur)], seg[right(cur)]);
            cover[cur] = cover[left(cur)] + cover[right(cur)];
        }
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
    vector<int> cover;
    vector<int> xs;
    map<int, int> mp;
    int m;
};

struct Segment {
    int start, end, y, event, length;
    double delta;
};

constexpr double eps = 1e-5;


class Solution {

public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();

        vector<int> xs;
        xs.reserve(n * 2);
        xs.push_back(-1);

        for (const auto& square : squares) {
            int a = square[0];
            int b = square[1];
            int c = square[2];
            segs.push_back({a, a + c, b, 1, 0, 0});
            segs.push_back({a, a + c, b + c, -1, 0, 0});

            xs.push_back(a);
            xs.push_back(a + c);
        }

        segtree.Init(xs);

        sort(segs.begin(), segs.end(), [](const Segment& s1, const Segment& s2) {
            return s1.y < s2.y;
        });

        double S = calc(segs, INF);
        print(S);

        double cur = 0;
        double prev = 0;
        for (auto& seg : segs) {
            if (cur + seg.delta < S / 2) {
                cur += seg.delta;
                prev = seg.y;
                continue;
            }

            double delta = S / 2 - cur;
            return prev + delta / seg.length;
        }

        return -1;
    }
private:
    double calc(vector<Segment>& segs, double filter) {
        segtree.Clear();

        double prev = -1;
        double s = 0;

        for (auto& seg : segs) {
            if (seg.y > filter) {
                break;
            }

            if (prev >= 0) {
                int length = segtree.Query();
                double delta = length * (seg.y - prev);
                seg.delta = delta;
                seg.length = length;
                s += delta;
            }

            if (seg.event > 0) {
                segtree.AddSeg(seg.start, seg.end);
            } else if (seg.event < 0) {
                segtree.RemoveSeg(seg.start, seg.end);
            } else {
                assert(false);
            }
            prev = seg.y;
        }

        if (filter < INF) {
            if (prev >= 0) {
                s += segtree.Query() * (filter - prev);
            }
        }

        return s;
    }
private:
    vector<Segment> segs;
    SegTree segtree;
};
