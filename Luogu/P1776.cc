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

const int SIZE = 41234;

int n, w;

llint dp[SIZE];

int main() {
    input(n, w);

    memset(dp, -INF, sizeof(dp));
    dp[0] = 0;

    int a, b, c;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        int rem = c;
        int cnt = 1;
        while (rem) {
            cnt = min(rem, cnt);
            rem -= cnt;

            llint ww = 1LL * cnt * b;
            llint vv = 1LL * cnt * a;

            for (int i = w; i >= 0; i--) {
                if (dp[i] >= 0 && i + ww <= w) {
                    dp[i + ww] = max(dp[i + ww], dp[i] + vv);
                }
            }

            cnt *= 2;
        }
    }

    llint ans = 0;
    for (int i = 0; i <= w; i++) {
        ans = max(ans, dp[i]);
    }
    print(ans);

    return 0;
}

/*

^^^TEST^^^
4 20
3 9 3
5 9 1
9 4 2
8 1 3
-----
47
$$$TEST$$$

^^^TEST^^^
20 300
18 30 3
2 20 2
19 16 1
3 25 5
13 12 4
1 22 1
11 2 5
3 26 9
10 29 6
4 13 2
15 8 2
10 1 3
16 25 1
16 5 8
11 8 9
13 21 4
16 4 9
17 16 2
13 27 1
6 20 8
-----
607
$$$TEST$$$


*/
