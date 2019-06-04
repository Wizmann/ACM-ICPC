/*
URL:https://vjudge.net/problem/LightOJ-1265

### Description

一个小岛上有一个人，t个老虎和d只鹿。

每天随机从岛上的生物中选出两个进行PK。如果人成为岛上唯一存活的生物，或者人死掉，游戏结束。

1. 如果选出来的是人和老虎，人死掉
2. 如果选出来一只老虎一只鹿，老虎吃掉鹿
3. 如果选出来两只鹿，什么都不会发生
4. 如果选出来两只老虎，两只老虎会自相残杀，统统挂掉
5. 如果选出来的是人和鹿，人可以选择杀死或是不杀死鹿

问人的一种最优策略，使得自己活下来的机率最大。

### Solution

首先我们可以看出，如果岛上有老虎，人不应该杀鹿。最起码可以多苟几轮。

所以我们可以列式如下：

$$
P(t, d) = P_{TD} * P(t, d - 1) + P_{DD} * P(t, d) + P_{TT} * P(t - 2， d) + P_{HD} * P(t, d)
$$

$P(t, d)$ 代表有t只虎，d只鹿时人存活的概率。

$P_{TD}$ 代表在当前状态下，选出虎（T）和鹿（D）对决的概率。同理$P_{HD}$为选出人（H）和鹿（D）对决的概率。

我们对式子进行化简，就有：

$$
P(t, d) = \frac{1}{1 - P_{DD} - P_{HD}} (P_{TD} * P(t, d - 1) + P_{TT} * P(t - 2, d))
$$

后面就可以使用DP来进行求解了。本题可以使用滚动数组，也可以直接DFS进行记忆化搜索。
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

const int SIZE = 1234;

double dp[SIZE][SIZE];

double C2(int x) {
    return 1.0 * x * (x - 1) / 2;
}

double solve(int t, int d) {
    if (t < 0 || d < 0) {
        return 0;
    }
    if (t == 0) {
        return 1;
    }

    if (dp[t][d] != -1) {
        return dp[t][d];
    }

    double u = C2(t + d + 1);
    double v = 1 - (d + C2(d)) / u;

    double res = C2(t) / u * solve(t - 2, d) + 1.0 * d * t / u * solve(t, d - 1);

    return dp[t][d] = res / v;
}

int main() {
    int T;
    input(T);
    int case_ = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dp[i][j] = -1;
        }
    }

    while (T--) {
        int a, b;
        input(a >> b);
        printf("Case %d: %.9lf\n", ++case_, solve(a, b));
    }

    return 0;
}
