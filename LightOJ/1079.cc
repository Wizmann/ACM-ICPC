/*
URL: https://vjudge.net/problem/LightOJ-1079

### Description

劫匪想打劫银行，但是希望被抓的概率不大于p。

有n个银行，给定打劫银行`i`的收益`m[i]`和被抓的概率`q[i]`。

问最多能打劫几个银行，使得收益最大。

### Solution

由于银行的个数`n`和抢银行的收益`m[i]`的乘积最大才10000。所以可以用`dp[k]`表示抢银行的总收益为`k`时被抓的概率。

```math
dp[k + m_{i}] = \min(dp[k + m_{i}], 1 - (1 - dp[k])(1 - q_{i}))
```
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;

int n;
vector<pair<double, int> > banks;
double dp[SIZE];

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    int case_ = 0;
    double tp;
    while (T--) {
        input(tp >> n);
        banks.clear();

        int m;
        double p;
        for (int i = 0; i < n; i++) {
            scanf("%d%lf", &m, &p);
            banks.push_back({p, m});
        }
        sort(banks.begin(), banks.end());
        fill(dp, dp + SIZE, 100);
        dp[0] = 0.0;

        for (int i = 0; i < n; i++) {
            int money = banks[i].second;
            p = banks[i].first;

            for (int j = SIZE - 1; j >= 0; j--) {
                if (dp[j] <= 1) {
                    assert(j + money < SIZE);
                    double pp = 1 - (1 - dp[j]) * (1 - p);
                    if (pp >= tp) {
                        continue;
                    }
                    dp[j + money] = min(dp[j + money], pp);
                }
            }
        }

        printf("Case %d: ", ++case_);
        for (int i = SIZE - 1; i >= 0; i--) {
            if (i == 0 || (dp[i] >= 0 && dp[i] <= tp)) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
