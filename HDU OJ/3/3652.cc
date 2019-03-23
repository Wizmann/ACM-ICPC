#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

llint dp[20][15][20];

llint dfs(const string& ns, const int pre, const int p, const int rem, const bool lt){
    int pos = ns.size() - p;
    if (lt && dp[pos][pre][rem] != -1) {
        return dp[pos][pre][rem];
    }

    if (p == ns.size()) {
        return rem == 0 && pre == 10? 1: 0;
    }

    int cur = ns[p] - '0';
    llint res = 0;
    for (int i = 0; i <= (lt? 9: cur); i++) {
        int pp = i;
        if (pre == 10 || (pre == 1 && i == 3)) {
            pp = 10;
        }

        res += dfs(ns, pp, p + 1, (rem * 10 + i) % 13, lt || i < cur);
    }

    if (lt) {
        return dp[pos][pre][rem] = res;
    } else {
        return res;
    }
}

llint solve(llint x) {
    string xs = to_string(x);
    return dfs(xs, 0, 0, 0, false);
}

int main() {
    llint x;
    memset(dp, -1, sizeof(dp));
    while (scanf("%lld", &x) != EOF) {
        printf("%lld\n", solve(x));
    }
    return 0;
}
