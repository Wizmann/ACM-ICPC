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

int n;

llint solve(int n) {
    if (n <= 4) {
        return 1;
    }
    vector<llint> dp(n + 1, INF);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (i + 4 <= n) {
            dp[i + 4] = min(dp[i + 4], dp[i - 1] + 1);
        }
        if (i + 3 <= n) {
            dp[i + 3] = min(dp[i + 3], dp[i - 1] + 1);
        }
    }
    /*
    for (int i = 0; i <= n; i++) {
        printf("%lld ", dp[i]);
    }
    puts("");
    */

    llint res = INF;
    res = min(res, dp[n] - 1);
    res = min(res, dp[n - 1]);
    res = min(res, dp[n - 2]);
    return res;
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        input(n);

        llint res = solve(n);
        printf("Case #%d: %lld\n", case_ + 1, res);
    }

    return 0;
}

/*

^^^TEST^^^
6
1
2
3
4
5
6
-----
Case #1: 1
Case #2: 1
Case #3: 1
Case #4: 1
Case #5: 1
Case #6: 2
$$$TEST$$$

*/
