/*
URL: https://vjudge.net/problem/LightOJ-1274

### Description

给定N道题，N道题的答案分别是"YES"或"NO"当中的一种。

现在你没有时间做题了，你想靠RP骗分。

已知这N道题有y道题的答案是"YES"，有n道题的答案是"NO"。并且你可以知道之前一道题的正确答案。

你的策略是第一题答"YES"，之后的每一道题都使用前一道题的答案。

问错误答案个数的期望。

### Solution

直接列式：

$$
DP[y][n][eYES] = P_{y}DP[y - 1][n][eYES] + P_{n}(DP[y][n - 1][eNO] + 1) 
$$

$$
DP[y][n][eNO] = P_{y}(DP[y - 1][n][eYES] + 1) + P_{n}DP[y][n - 1][eNO]
$$

y代表当前还剩余多少个"YES"，n代表还剩余多少个"NO"。eYES和eNO代表上一个答案是"YES"还是"NO"。

我们使用滚动数组进行DP。

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5555;

const int eYES = 0;
const int eNO = 1;
const int INF = 0x3f3f3f3f;

double dp[2][2][SIZE];

double solve(int n, int s) {
    int nYes = s - 2 * n;
    int nNo = n - nYes;
    memset(dp, 0, sizeof(dp));
    int p = 0;

    for (int i = n - 1; i >= 0; i--) {
        int q = p ^ 1;

        int minYes = max(0, i - nNo);
        int maxYes = min(nYes, i);

        for (int j = minYes; j <= maxYes; j++) {
            double py = 1.0 * (nYes - j) / (n - i);
            double pn = 1 - py;
            dp[q][eYES][j] = py * (dp[p][eYES][j + 1] + 1) + pn * (dp[p][eNO][j]);
            dp[q][eNO][j]  = py * (dp[p][eYES][j + 1]) + pn * (dp[p][eNO][j] + 1);
        }
        p = q;
    }
    return n - dp[p][eYES][0];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    int case_ = 0;

    while (T--) {
        int a, b;
        input(a >> b);
        printf("Case %d: %.9lf\n", ++case_, solve(a, b));
    }

    return 0;
}
