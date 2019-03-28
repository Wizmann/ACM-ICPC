#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

llint dp[1111][555][20];

llint dfs(const string& ns, int p, int status, int occur, bool st, bool lt) {
    int l = ns.size() - p;

    if (l == 0) {
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                bool o = occur & (1 << (i / 2));
                int c = status & (1 << i);

                if (o && c == 0) {
                    return 0;
                }
            } else {
                int c = status & (1 << i);
                if (c != 0) {
                    return 0;
                }
            }
        }
        return 1;
    }

    llint& u = dp[status][occur][l];
    if (lt && st && u != -1) {
        return u;
    }

    int cur = ns[p] - '0';
    llint res = 0;
    for (int i = 0; i < (lt? 10: cur + 1); i++) {
        bool nst = true;
        if (st == false && i == 0) {
            nst = false;
        }
        int nstatus = status;
        if (nst) {
            nstatus ^= 1 << i;
        }
        int noccur = occur;
        if (nst && i % 2 == 0) {
            noccur |= 1 << (i / 2);
        }
        res += dfs(ns, p + 1, nstatus, noccur, nst, lt || i < cur);
    }

    if (st && lt) {
        return u = res;
    }
    return res;
}

llint solve(llint x) {
    if (x == 0) {
        return 1;
    }
    string xs = to_string(x);
    return dfs(xs, 0, 0, 0, false, false);
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);

    memset(dp, -1, sizeof(dp));

    while (T--) {
        llint l, r;
        input(l >> r);
        print(solve(r) - solve(l - 1));
    }

    return 0;
}
