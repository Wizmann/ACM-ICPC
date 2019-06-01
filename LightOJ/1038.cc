/*
URL: https://vjudge.net/problem/LightOJ-1038

### Description

给一个数N，每一步都可以将N整除，直到除到1为止。

问步数的期望。

### Solution

非常简单的DP，由于数据规模不大，可以直接在DFS的过程中求约数。

`P`代表数字`i`约数个数的倒数。


```math
dp[i] = \sum{dp[i / k] * P} \quad \mid \quad  i \bmod k == 0
```
*/
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
