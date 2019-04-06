#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;

int n;
double dp[SIZE];

double dfs(int cur) {
    if (dp[cur] >= 0) {
        return dp[cur];
    }

    if (cur == 1) {
        return 0;
    }

    int tot = 0;
    double e = 0;
    for (int i = 1; 1LL * i * i <= cur; i++) {
        if (cur % i != 0) {
            continue;
        }
        if (i > 1) {
            tot++;
            e += dfs(cur / i);
        }

        if (cur / i != i) {
            tot++;
            e += dfs(i);
        }
    }
    assert(tot != 0);
    e = e / tot + 1.0 * (tot + 1) / tot;
    return dp[cur] = e;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        fill(dp, dp + SIZE, -1);
        input(n);
        printf("Case %d: %.6lf\n", ++case_, dfs(n));
    }
    return 0;
}
