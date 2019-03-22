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

const int LEN = 20;
const int PRE = 10;

llint dp[LEN][PRE];

llint dfs(const string& ns, int p, int pre, bool lt) {
    if (lt && dp[ns.size() - p][pre] != -1) {
        return dp[ns.size() - p][pre];
    }

    if (p == ns.size()) {
        return 1;
    }

    llint res = 0;
    int cur = ns[p] - '0';
    for (int i = 0; i < 10; i++) {
        if (lt == false && i <= cur) {
            if (pre != 4 || i != 9) {
                res += dfs(ns, p + 1, i, i < cur);
            }
        }
        if (lt) {
            if (pre != 4 || i != 9) {
                res += dfs(ns, p + 1, i, true);
            }
        }
    }
    if (lt) {
        return dp[ns.size() - p][pre] = res;
    } else {
        return res;
    }
}

llint solve(llint n) {
    string ns = to_string(n);
    return dfs(ns, 0, 0, false);
}

int main() {
    int T;
    input(T);
    memset(dp, -1, sizeof(dp));
    while (T--) {
        llint n;
        scanf("%lld", &n);
        printf("%lld\n", n - solve(n) + 1);
    }
    return 0;
}
