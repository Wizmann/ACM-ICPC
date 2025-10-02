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

const int MOD = 998244353;
const int N = 7777;

int n;
int dp[N][N];

int dfs(int rem, int dis) {
    if (rem == 0) {
        if (dis >= 1) {
            return 1;
        }
        return 0;
    }

    if (dp[rem][dis] != -1) {
        return dp[rem][dis];
    }

    llint res = 0;
    int nxts[] = { dis - 2, dis - 1, dis };

    for (int i = 0; i < 3; i++) {
        int nxt = nxts[i];
        nxt = min(nxt, n - nxt);

        if (nxt <= 0) {
            continue;
        }

        res += dfs(rem - 1, nxt);
    }

    return dp[rem][dis] = res % MOD;
}

int main() {
    int x, y, k;
    input(n, x, y, k);

    int dis = abs(x - y);
    dis = min(dis, n - dis);

    memset(dp, -1, sizeof(dp));
    print(dfs(k, dis));

    return 0;
}

/*

^^^TEST^^^
5 1 4 3
-----
4
$$$TEST$$$

^^^TEST^^^
7 1 5 6
-----
28
$$$TEST$$$

^^^TEST^^^
1145 141 919 810
-----
783109298
$$$TEST$$$

*/
