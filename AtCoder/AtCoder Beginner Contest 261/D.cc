#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

vector<llint> xs;
vector<llint> bs;
vector<llint> dp;

int main() {
    int n, m;
    input(n, m);

    xs = vector<llint>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &xs[i]);
    }

    for (int i = 1; i <= n; i++) {
        xs[i] += xs[i - 1];
    }

    bs = vector<llint>(n + 1, 0);

    int a, b;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        bs[a] = b;
    }

    for (int i = 1; i <= n; i++) {
        bs[i] += bs[i - 1];
    }

    dp = vector<llint>(n + 1, 0);

    for (int i = 0; i <= n; i++) {
        llint pre = i - 1 <= 0? 0: dp[i - 1];
        for (int j = 1; i + j <= n; j++) {
            // print(i, j, pre, bs[j], (xs[i + j] - xs[i]));
            dp[i + j] = max(
                    dp[i + j],
                    pre + bs[j] + (xs[i + j] - xs[i]));
        }
    }

    print(dp[n]);

    return 0;
}

/*

^^^TEST^^^
6 3
2 7 1 8 2 8
2 10
3 1
5 5
-----
48
$$$TEST$$$

^^^TEST^^^
3 2
1000000000 1000000000 1000000000
1 1000000000
3 1000000000
-----
5000000000
$$$TEST$$$

*/
