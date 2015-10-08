#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

inline int lowbit(int x) { return x & (-x); }

struct BITree {
    vector<llint> _tree;

    void init(int size) {
        _tree.resize(size + 1);
    }

    void add(int pos, int value) {
        while (pos < _tree.size()) {
            _tree[pos] += value;
            pos += lowbit(pos);
        }
    }

    llint sum(int pos) {
        llint res = 0;
        while (pos > 0) {
            res += _tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    llint sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
};

struct BITree_2D {
    vector<BITree> _tree;

    void init(int n, int m) {
        _tree.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            _tree[i].init(m);
        }
    }

    void add(int y, int x, int value) {
        while (y < _tree.size()) {
            _tree[y].add(x, value);
            y += lowbit(y);
        }
    }

    llint sum(int y, int x) {
        llint res = 0;
        while (y > 0) {
            res += _tree[y].sum(x);
            y -= lowbit(y);
        }
        return res;
    }

    llint sum(int y1, int x1, int y2, int x2) {
        llint a = sum(y2, x2);
        llint b = sum(y1 - 1, x1 - 1);
        llint c = sum(y2, x1 - 1);
        llint d = sum(y1 - 1, x2);

        return a - c - d + b;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int a, b, c, d, e;
    BITree_2D tree;
    while (input(a) && a != 3) {
        if (a == 0) {
            input(b);
            tree.init(b, b);
        }
        if (a == 1) {
            scanf("%d%d%d", &b, &c, &d);
            b++;
            c++;
            tree.add(c, b, d);
        }
        if (a == 2) {
            scanf("%d%d%d%d", &b, &c, &d, &e);
            b++;
            c++;
            d++;
            e++;
            print(tree.sum(c, b, e, d));
        }
    }
    return 0;
}
