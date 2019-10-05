#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <list>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define FOR(i, n) for (int i = 0; i < n; i++)

typedef long long llint;

struct Operation {
    int l, r, d;
};

int main() {
    cin.sync_with_stdio(0);

    int n, m, k;
    input(n >> m >> k);
    vector<llint> ns(n);
    vector<Operation> ops;

    FOR (i, n) {
        input(ns[i]);
    }

    int l, r, d;
    FOR (i, m) {
        input(l >> r >> d);
        l--;
        r--;
        ops.push_back({l, r, d});
    }

    vector<int> delta1(m);
    FOR (i, k) {
        input(l >> r);
        l--;
        r--;
        delta1[l] += 1;
        if (r + 1 < m) {
            delta1[r + 1] -= 1;
        }
    }

    vector<llint> delta2(n);
    llint mult = 0;
    FOR (i, m) {
        mult += delta1[i];
        delta2[ops[i].l] += 1LL * mult * ops[i].d;
        if (ops[i].r + 1 < n) {
            delta2[ops[i].r + 1] -= 1LL * mult * ops[i].d;
        }
    }

    llint acc = 0;
    FOR (i, n) {
        acc += delta2[i];
        llint cur = 1LL * ns[i] + acc;
        if (i) {
            cout << " ";
        }
        cout << cur;
    }
    print("");

    return 0;
}