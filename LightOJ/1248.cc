/*
URL: https://vjudge.net/problem/LightOJ-1248

### Description

给定一个N面的骰子，问N面至少都能投出一次的数学期望。

### Solution

我们可以列出期望的方程，设我们已经投出了`i`面，还有`n - i`面没有投出，`dp[i]`代表还需要投的次数的期望。此时有：

```math

dp[i] = \frac{i}{n} \times dp[i] + \frac{n - i}{n} \times dp[i + 1] + 1

\Downarrow

dp[i] = dp[i + 1] + \frac{n}{n - i}

```
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;

int n;
double dp[SIZE];

double solve(int k) {
    if (dp[k] >= 0) {
        return dp[k];
    }
    if (k == 0) {
        return 0;
    }
    return solve(k - 1) + 1.0 * n / k;
}

int main() {
    int T;
    int case_ = 0;
    input(T);
    while (T--) {
        scanf("%d", &n);
        fill(dp, dp + SIZE, -1);
        printf("Case %d: %.6lf\n", ++case_, solve(n));
    }

    return 0;
}
