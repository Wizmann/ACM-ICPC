/*
URL: https://vjudge.net/problem/LightOJ-1027

### Description

现在你身处一个迷宫，你的面前有n个门`d[0...n]`，你会等概率的随机打开一个门`i`。

如果`d[i] > 0`，你会花`d[i]`时间走出迷宫。如果`d[i] < 0`，你会花`abs(d[i])`的时间回到原处。

问你走出迷宫的数学期望是多少？

### Solution

设最终走出迷宫的数学期望为`E`。

正数门的个数为`N0`，选中标号为正数的门的概率为`P0`，正数门的标号之和为`Sum0`，平均值为`Ave0`。

与此对应的负数门的个数为`N0`，选中概率`P1`，标号之和`Sum1`，平均值`Ave1`。

我们可以列出等式：

```math
 E = P_{0} Ave_{0} + P_{1} (Ave_{1} + E)
```

* 如果我们选中了正数门，那么会消耗`Ave0`的时间，并且走出迷宫。
* 如果我们选中的负数门，那么会消耗`Ave1`的时间，回到原地，需要期望为`E`时间才能走出迷宫。

接下来我们进行等式的进行一步推导，得到：

```math
E = \frac{Sum_{0} + Sum_{1}}{N_{0}}
```

最后使用分数化简就可以得到最终答案。
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

llint gcd(llint a, llint b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    input(T);
    int case_ = 1;
    while (T--) {
        printf("Case %d: ", case_++);
        int n;
        input(n);
        vector<int> ns(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        llint ca = 0;
        llint cb = 0;
        llint sa = 0;
        llint sb = 0;

        for (int i = 0; i < n; i++) {
            if (ns[i] > 0) {
                ca++;
                sa += ns[i];
            } else {
                cb++;
                sb += -ns[i];
            }
        }

        if (cb == ns.size()) {
            puts("inf");
            continue;
        }

        llint l = (n - cb);
        llint r = sa + sb;
        llint g = gcd(l, r);

        printf("%lld/%lld\n", r / g, l / g);
    }
    return 0;
}
