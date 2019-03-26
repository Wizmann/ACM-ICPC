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

llint dp[10][5555];

llint dfs(const string& ns, const int p, const int fa, const bool st, const bool lt) {
    int l = ns.size() - p;

    if (fa < 0) {
        return 0;
    }

    if (l == 0) {
        return fa >= 0? 1: 0;
    }

    llint& u = dp[l][fa];
    if (st && lt && u != -1) {
        return u;
    }

    int cur = ns[p] - '0';
    llint res = 0;

    for (int i = 0; i < (lt? 10: cur + 1); i++) {
        int score = (1 << (l - 1)) * i;
        bool nst = true;
        if (st == false && i == 0) {
            nst = false;
        }
        res += dfs(ns, p + 1, fa - score, nst, lt || i < cur);
    }
    
    if (st && lt) {
        return u = res;
    }

    return res;
}

llint solve(int x, int fa) {
    if (x < 0)  {
        return 0;
    }
    string xs = to_string(x);
    return dfs(xs, 0, fa, false, false);
}

int F(int x) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        int u = x % 10;
        x /= 10;
        res += (1 << i) * u;
    }
    return res;
}

int main() {
    int T;
    input(T);
    int case_ = 1;
    memset(dp, -1, sizeof(dp));
    while (T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int fa = F(a);
        printf("Case #%d: %lld\n", case_++, solve(b, fa));
    }
    return 0;
}
