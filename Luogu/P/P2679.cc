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

const llint ALPHA = 29;
const llint MOD = (1LL << 62) - 1;

const int MAXN = 1001;
const int MAXM = 202;
const int MAXK = 202;

const llint ANSMOD = 1000000007;

int dp[2][2][MAXM][MAXK];

string A, B;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    input(A, B);
    A = "^" + A;
    B = "^" + B;

    int ptr = 0;
    memset(dp, 0, sizeof(dp));

    dp[ptr][0][0][0] = 1;
    dp[ptr][1][0][0] = 1;

    // dp[a][b][k][False] = dp[a - 1][b - 1][k][False]    (if A[a] == B[b])
    //                    + dp[a - 1][b - 1][k - 1][True] (if A[a] == B[b])
    // dp[a][b][k][True] = dp[a][b][k][False]
    //                   + dp[a - 1][b][k][True]
    for (int i = 1; i <= n; i++) {
        int qtr = ptr ^ 1;
        memset(dp[qtr], 0, sizeof(dp[qtr]));
        dp[qtr][0][0][0] = 1;
        dp[qtr][1][0][0] = 1;
        for (int j = 1; j <= min(i, m); j++) {
            for (int k = 1; k <= min(i, j); k++) {
                if (A[i] == B[j]) {
                    dp[qtr][0][j][k] = (1LL * dp[qtr][0][j][k] + dp[ptr][0][j - 1][k]) % ANSMOD;
                    dp[qtr][0][j][k] = (1LL * dp[qtr][0][j][k] + dp[ptr][1][j - 1][k - 1]) % ANSMOD;
                    dp[qtr][1][j][k] = dp[qtr][0][j][k];
                }
                dp[qtr][1][j][k] = (1LL * dp[qtr][1][j][k] + dp[ptr][1][j][k]) % ANSMOD;
                // printf("[0 %d %d %d] = %d\n", i, j, k, dp[0][ptr][j][k]);
                // printf("[1 %d %d %d] = %d\n", i, j, k, dp[1][ptr][j][k]);
            }
        }
        ptr = qtr;
    }

    print(dp[ptr][1][m][k]);
    return 0;
}

/*

^^^TEST^^^
3 1 1
aaa
a
-----
3
$$$TEST$$$

^^^TEST^^^
3 2 2
aaa
aa
-----
3
$$$TEST$$$

^^^TEST^^^
3 1 2
aaa
a
-----
0
$$$TEST$$$

^^^TEST^^^
3 3 2 
aab
aab
-----
2
$$$TEST$$$

^^^TEST^^^
6 3 1 
aabaab 
aab
-----
2
$$$TEST$$$

^^^TEST^^^
6 3 2 
aabaab 
aab
-----
7
$$$TEST$$$

^^^TEST^^^
6 3 3 
aabaab 
aab
-----
7
$$$TEST$$$

^^^TEST^^^
6 3 3 
aaabbb
zzz
-----
0
$$$TEST$$$

*/
