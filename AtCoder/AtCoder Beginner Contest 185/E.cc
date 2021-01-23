#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int SIZE = 1111;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

int n, m;
int dp[SIZE][SIZE];
vector<int> A;
vector<int> B;

int main() {
    input(n, m);

    A = vector<int>(n + 1, 0);
    B = vector<int>(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &B[i]);
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        }
    }

    print(dp[n][m]);

    return 0;
}

/*
^^^TEST^^^
4 4
123 10 123 123
10 234 10 10
---
4
$$$TEST$$$

^^^TEST^^^
4 4
123 123 123 123
10 10 10 10
---
4
$$$TEST$$$

^^^TEST^^^
1 4
1
10 10 10 10
---
4
$$$TEST$$$

^^^TEST^^^
1 1
1
10
---
1
$$$TEST$$$

^^^TEST^^^
1 1
1
1
---
0
$$$TEST$$$

^^^TEST^^^
4 3
1 2 1 3
1 3 1
---
2
$$$TEST$$$

^^^TEST^^^
4 6
1 3 2 4
1 5 2 6 4 3
-----
3
$$$TEST$$$

^^^TEST^^^
5 5
1 1 1 1 1
2 2 2 2 2
----
5
$$$TEST$$$

*/
