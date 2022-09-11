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

const int N = 444;

int n, d;
llint dp[N][N][2];
vector<int> ns;

llint solve(int l, int r, int pre) {
    const int ll = l;
    const int rr = r;
    if (dp[l][r][pre] != -1) {
        return dp[l][r][pre];
    }

    llint delta = 0;
    if (pre == 0 && l - 1 >= 0) {
        delta = -ns[l - 1];
    } else if (pre == 1 && r + 1 < n) {
        delta = -ns[r + 1];
    }

    auto ms = [&](const int idx) {
        return ((1LL * ns[idx] + delta % d) % d + d) % d;
    };

    llint res = INFLL;

    if (l > r) {
        res = 0;
    } else if (l == r) {
        res = min(ms(l), d - ms(l));
    } else {
        res = min(res, min(ms(l), d - ms(l)) + solve(l + 1, r, 0));
        res = min(res, min(ms(r), d - ms(r)) + solve(l, r - 1, 1));
    }

    return dp[ll][rr][pre] = res;
}


int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        memset(dp, -1, sizeof(dp));
        input(n, d);
        ns.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        llint res = solve(0, n - 1, 0);
        printf("Case #%d: %lld\n", case_ + 1, res);
    }

    return 0;
}


/*

^^^TEST^^^
2
6 2
1 1 0 1 0 1
6 2
0 1 0 0 1 1
-------
Case #1: 3
Case #2: 2
$$$TEST$$$

^^^TEST^^^
2
6 10
1 1 2 2 3 3
6 10
1 1 9 9 1 1
-----
Case #1: 3
Case #2: 3
$$$TEST$$$

*/


