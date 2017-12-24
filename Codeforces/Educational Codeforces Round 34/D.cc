#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

class BITree {
public:
    BITree(int n_): n(n_ + 1), tree(n_ + 1) {
        // pass
    }

    void add(int pos, int value) {
        while (pos < n) {
            tree[pos] += value;
            pos += lowbit(pos);
        }
    }

    llint sum(int pos) {
        llint res = 0;
        while (pos > 0) {
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    llint sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int lowbit(int x) {
        return (x) & (-x);
    }
private:
    int n;
    vector<llint> tree;
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, x;
    input(n);
    vector<pair<int, int> > ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        ns[i] = {x, i + 1};
    }

    sort(ns.begin(), ns.end());
    reverse(ns.begin(), ns.end());
    int p = 0;
    int q = 0;
    BITree ta(n);
    BITree tb(n);
    long double res = 0;
    while (q < n) {
        int v = ns[q].first;
        int u = ns[q].second;
        llint a = ta.sum(u, n) - tb.sum(u, n) * v;
        llint b = ta.sum(1, u) - tb.sum(1, u) * v;
        res = res + a - b;
        // print(q << ' ' << a << ' ' << b);
        q++;

        while (p < q && ns[p].first > ns[q].first + 1) {
            ta.add(ns[p].second, ns[p].first);
            tb.add(ns[p].second, 1);
            p++;
        }
    }

    printf("%.0Lf\n", res);
    return 0;
}
