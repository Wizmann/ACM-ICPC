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

int main() {
    int n, C;
    input(n, C);

    llint a, b, c;
    vector<llint> dp(C + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        dp[a] = max(dp[a], b * c);
    }

    for (int i = 1; i <= C; i++) {
        if (dp[i] == 0) {
            continue;
        }
        for (int j = 2; 1LL * i * j <= C; j++) {
            dp[i * j] = max(dp[i * j], dp[i] * j);
        }
    }

    for (int i = 1; i <= C; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &a, &b);

        auto iter = upper_bound(dp.begin(), dp.end(), a * b);
        int res = distance(dp.begin(), iter);
        if (res > C) {
            puts("-1");
        } else {
            printf("%d ", res);
        }
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
3 10
3 4 6
5 5 5
10 3 4
3
8 3
5 4
10 15
-----
5 3 -1 
$$$TEST$$$

^^^^TEST^^^^
5 15
14 10 3
9 2 2
10 4 3
7 3 5
4 3 1
6
11 2
1 1
4 7
2 1
1 14
3 3
--------
14 4 14 4 7 7 
$$$TEST$$$

^^^^TEST^^^^
5 13
13 1 9
6 4 5
12 18 4
9 13 2
5 4 5
2
16 3
6 2
--------
12 5 
$$$TEST$$$


*/
