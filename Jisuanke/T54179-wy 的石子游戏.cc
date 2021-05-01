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

#define print(x) cout << x << endl
#define input(x) cin >> x

const int BIT = 60;

char dp[BIT + 12][BIT + 12];

bool dfs(llint a, llint b, int p, int q) {
    // print(p, q);
    if (p >= 0 && q >= 0 && dp[p][q] != -1) {
        return dp[p][q];
    }

    while (q >= 0 && !(b & (1LL << q))) {
        q--;
    }
    while (p >= 0 && !(a & (1LL << p))) {
        p--;
    }

    if (p < 0 && q < 0) {
        return true;
    }
    if (p < 0 || q < 0) {
        return false;
    }
    assert(a & (1LL << p));
    assert(b & (1LL << q));

    if (p > q) {
        return false;
    }

    bool res = false;
    if (p < q) {
        res |= dfs(a, b, p - 1, q);
    }
    res |= dfs(a, b, p - 1, q - 1);

    if (p >= 0 && q >= 0) {
        return dp[p][q] = res;
    }
    return res;
}

bool solve(llint a, llint b) {
    memset(dp, -1, sizeof(dp));
    return dfs(a, b, BIT, BIT);
}

int main() {
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    
    int T;
    input(T);

    llint a, b;
    while (T--) {
        scanf("%lld%lld", &a, &b);

        if (solve(a, b)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}

/*

^^^TEST^^^
3
3 6
1 6
5 5
-----
YES
NO
YES
$$$TEST$$$

^^^TEST^^^
8
1 1
1 2
1 3
1 1024
1024 1
3 1025
7 1025
13 9
-----
YES
YES
NO
YES
NO
YES
YES
NO
$$$TEST$$$

^^^TEST^^^
1
13 9
----
NO
$$$TEST$$$$

*/
