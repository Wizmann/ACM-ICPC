/*
URL: https://vjudge.net/problem/LightOJ-1104

### Description

给定一年有n天，求最小的m，使m个人当中有两个人的生日相同的概率超过0.5。

### Solution

生日悖论问题。

```math

P = 1 \times \frac{n - 1}{n} \times \frac{n - 2}{n} \dotsb \frac{n - m + 1}{n}

```

因为n比较大以及数据组数T比较多，所以我们可以预处理出所有的结果。

不过直接算也能过。

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

typedef long long llint;

int main() {
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        int n;
        scanf("%d", &n);

        double p = 1.0;

        int cnt = n;

        while (p > 0.5) {
            p = p * (cnt - 1) / n;
            cnt--;
        };

        printf("Case %d: %d\n", ++case_, n - cnt);
    }
    return 0;
}
