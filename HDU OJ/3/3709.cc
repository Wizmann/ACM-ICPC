#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

llint dp[20][20][2000];

llint dfs(const string& ns, const int p, const int weight, const int pivot, const bool lt) {
    llint& prev = dp[ns.size() - p][ns.size() - pivot][weight];
    if (lt && prev != -1) {
        return prev;
    }

    if (p == ns.size()) {
        return weight == 0? 1: 0;
    }

    int cur = ns[p] - '0';
    assert(0 <= cur && cur <= 9);
    llint res = 0;
    for (int i = 0; i <= (lt? 9: cur); i++) {
        int u = pivot - p;
        int w = weight + u * i;
        if (w >= 0) {
            res += dfs(ns, p + 1, w, pivot, lt || i < cur);
        }
    }

    if (lt) {
        return prev = res;
    } else {
        return res;
    }
}

llint solve(llint x) {
    if (x == -1) {
        return 0;
    }
    string xs = to_string(x);
    int n = xs.size();
    llint res = 0;
    for (int i = 0; i < n; i++) {
        res += dfs(xs, 0, 0, i, false);
    }
    return res - xs.size() + 1;
}

int main() {
    int T;

    memset(dp, -1, sizeof(dp));
    assert(solve(12345) == 823);
    assert(solve(9) == 10);
    assert(solve(10) == 11);
    assert(solve(99) == 19);
    assert(solve(-1) == 0);
    assert(solve(0) == 1);
    assert(solve(1) == 2);

    input(T);
    while (T--) {
        llint a, b;
        scanf("%lld%lld", &a, &b);
        print(solve(b) - solve(a - 1));
    }
    return 0;
}
