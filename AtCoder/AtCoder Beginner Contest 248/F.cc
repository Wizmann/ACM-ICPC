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

const int N = 3123;

int p;

int dp[2][N][N];

int do_solve(int n, int m, int flag) {
    if (n <= 0) {
        return 0;
    }
    if (m < 0) {
        return 0;
    }
    if (dp[flag][n][m] != -1) {
        return dp[flag][n][m];
    }
    // print(flag, n, m);

    assert(n);

    if (n == 1) {
        if (m == 0 && flag == 1) {
            return 1;
        }
        if (m == 1 && flag == 0) {
            return 1;
        }
        return 0;
    }

    llint res = 0;
    if (flag == 1) {
        res += do_solve(n - 1, m - 1, 1) % p;
        res %= p;

        res += do_solve(n - 1, m, 0) % p;
        res %= p;

        res += 2LL * do_solve(n - 1, m - 1, 1) % p;
        res %= p;

        res += do_solve(n - 1, m, 1) % p;
        res %= p;
    } else {
        res += do_solve(n - 1, m - 1, 0) % p;
        res %= p;
 
        res += 2LL * do_solve(n - 1, m - 2, 1) % p;
        res %= p;
    }

    return dp[flag][n][m] = res % p;
}

int solve(int n, int m) {
    return do_solve(n, m, 1);
}


int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    input(n, p);

    // print(solve(3, 2));

    for (int i = 1; i < n; i++) {
        printf("%d ", solve(n, i));
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
3 998244353
-----
7 15
$$$TEST$$$

^^^TEST^^^
16 999999937
-----
46 1016 14288 143044 1079816 6349672 29622112 110569766 330377828 784245480 453609503 38603306 44981526 314279703 408855776
$$$TEST$$$

*/
