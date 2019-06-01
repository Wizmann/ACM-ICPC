/*
URL: https://vjudge.net/problem/LightOJ-1030

### Description

题目：[Discovering Gold][3]

给定一个长为N的数组，每个格子里面都有一定数量的金子。

现在你从位置1开始，每轮投骰子向前随机走1~6步，直到走到N点为止。如果你的随机数让你走出了数组，则你需要重新扔骰子。你可以获得每轮起始点和终点的金子。

问你获得金子数量的期望。

### Solution

本题可以用DP来做，但是一定注意DP的顺序。由于到达数组每一个点的概率不同，所以我们不能由`dp[i - k]`等概率的推出`dp[i]`。我们选择从`dp[i + k]`推出`dp[i]`。

设`dp[i]`为从点i到点n所需要步数的期望。`P`代表从`i`到`i+k`的概率。

```math
dp[i] = \sum{dp[i + k] * P}
```
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
vector<double> dp;

int main() {
    int T;
    input(T);
    int case_ = 0;

    while (T--) {
        input(n);
        dp = vector<double>(n, 0);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &dp[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            int cnt = min(n - 1, i + 6) - i;
            for (int j = i + 1; j <= min(n - 1, i + 6); j++) {
                dp[i] += 1.0 / cnt * dp[j];
            }
        }

        printf("Case %d: %.6lf\n", ++case_, dp[0]);
    }

    return 0;
}
