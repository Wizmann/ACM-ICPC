#include <bits/stdc++.h>
using namespace std;

struct Node {
    int mn = INT_MAX;
    int mx = INT_MIN;
    int minPos = -1;
    int maxPos = -1;
};

Node mergeNode(const Node& a, const Node& b) {
    Node res;

    if (a.mn <= b.mn) {
        res.mn = a.mn;
        res.minPos = a.minPos;
    } else {
        res.mn = b.mn;
        res.minPos = b.minPos;
    }

    if (a.mx >= b.mx) {
        res.mx = a.mx;
        res.maxPos = a.maxPos;
    } else {
        res.mx = b.mx;
        res.maxPos = b.maxPos;
    }

    return res;
}

struct SegmentTree {
    int size;
    vector<Node> tree;

    SegmentTree(const vector<int>& p) {
        size = 1;
        while (size < (int)p.size()) size <<= 1;

        tree.assign(2 * size, Node{});

        for (int i = 0; i < (int)p.size(); ++i) {
            tree[size + i] = {p[i], p[i], i, i};
        }
        for (int i = size - 1; i >= 1; --i) {
            tree[i] = mergeNode(tree[2 * i], tree[2 * i + 1]);
        }
    }

    // 查询半开区间 [l, r)
    Node query(int l, int r) const {
        Node leftResult, rightResult;
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) leftResult = mergeNode(leftResult, tree[l++]);
            if (r & 1) rightResult = mergeNode(tree[--r], rightResult);
            l >>= 1;
            r >>= 1;
        }

        return mergeNode(leftResult, rightResult);
    }

    void update(int pos, int value) {
        int i = size + pos;
        tree[i] = {value, value, pos, pos};

        while (i > 1) {
            i >>= 1;
            tree[i] = mergeNode(tree[2 * i], tree[2 * i + 1]);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> P(N);
    for (int& x : P) cin >> x;

    SegmentTree seg(P);

    while (M--) {
        int L, R;
        cin >> L >> R;

        Node res = seg.query(L - 1, R);
        int i = res.minPos;
        int j = res.maxPos;

        swap(P[i], P[j]);
        seg.update(i, P[i]);
        seg.update(j, P[j]);
    }

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << P[i];
    }
    cout << '\n';
}
