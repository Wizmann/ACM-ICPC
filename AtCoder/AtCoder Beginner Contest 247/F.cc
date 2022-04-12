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
const llint MOD = 998244353;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int N = 212345;

vector<bool> visited;
vector<int> g[N];

llint dp[N];

llint do_solve(int n) {
    if (n == 0) {
        assert(false);
        return 0;
    }
    if (n == 1) {
        return 2;
    }
    if (n == 2) {
        return 3;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    llint res = 0;
    res = (res + do_solve(n - 1)) % MOD;
    res = (res + do_solve(n - 2)) % MOD;
    return dp[n] = res % MOD;
}

llint solve(int n) {
    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 3;
    }

    if (n == 3) {
        return 4;
    }

    llint res = do_solve(n - 1) + do_solve(n - 3) % MOD;
    return res;
}

int dfs(int cur) {
    if (visited[cur]) {
        return 0;
    }
    visited[cur] = true;

    int cnt = 1;
    for (int nxt : g[cur]) {
        cnt += dfs(nxt);
    }
    return cnt;
}

int main() {
    int n;
    input(n);
    memset(dp, -1, sizeof(dp));

    vector<int> A(n);
    vector<int> B(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < n; i++) {
        int a = A[i];
        int b = B[i];
        g[a].push_back(b);
        g[b].push_back(a);
    }

    llint res = 1;
    visited = vector<bool>(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int u = dfs(i);
            // print(i, u, solve(u));
            res = res * solve(u) % MOD;
        }
    }

    print(res);

    return 0;
}

/*

^^^TEST^^^
3
1 2 3
2 1 3
-----
3
$$$TEST$$$

^^^TEST^^^
5
2 3 5 4 1
4 2 1 3 5
-----
12
$$$TEST$$$

^^^TEST^^^
8
1 2 3 4 5 6 7 8
1 2 3 4 5 6 7 8
-----
1
$$$TEST$$$

^^^TEST^^^
10
10 5 3 7 8 4 1 2 9 6
6 4 1 8 9 3 2 5 10 7
--------
121
$$$TEST$$$

^^^TEST^^^
3
1 3 2
2 1 3
--------
4
$$$TEST$$$

^^^TEST^^^
4
2 4 3 1
3 2 1 4
--------
7
$$$TEST$$$

*/
