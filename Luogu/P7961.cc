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

const llint MOD = 998244353;

int n, m, k;
vector<llint> ns;

inline llint powmod(llint a, llint b, llint c) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % c;
        }
        a = a * a % c;
        b >>= 1;
    }
    return res;
}

inline llint invmod(llint x) {
    return powmod(x, MOD - 2, MOD);
}

const int N = 33;
const int K = 33;
const int M = 111;

vector<llint> factorial;
vector<llint> inv;

llint C[M][M];

void init() {
    factorial.resize(M);
    factorial[0] = 1;
    for (int i = 1; i < M; i++) {
        factorial[i] = 1LL * factorial[i - 1] * i % MOD;
    }

    inv.resize(M);
    for (int i = 0; i < M; i++) {
        inv[i] = invmod(factorial[i]);
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = 1LL * (factorial[i] * inv[j] % MOD) * inv[i - j] % MOD;
            C[i][j] %= MOD;
        }
    }

    assert(C[5][3] == (5 * 4 * 3) / (3 * 2));
    assert(C[10][2] == 10 * 9 / 2);
}

llint dp[M + 10][K][N][N];

llint dfs(int cur, int u, llint rem, int tot) {
    // print(cur, u, rem, tot);
    if (cur == -1) {
        if (u == 0 && rem == 0 && tot == n) {
            // print("OK");
            return 1;
        } else {
            return 0;
        }
    }

    if (u < 0) {
        return 0;
    }

    if (rem > n - tot) {
        return 0;
    }

    if (rem < 0) {
        return 0;
    }

    assert(u >= 0);
    assert(tot <= n);
    assert(rem >= 0 && rem < N);
    assert(cur >= 0);
    assert(tot >= 0 && tot < N);

    if (dp[cur][u][rem][tot] != -1) {
        return dp[cur][u][rem][tot] % MOD;
    }

    llint res = 0;

    res += dfs(cur - 1, u, rem * 2, tot);
    res %= MOD;

    res += dfs(cur - 1, u - 1, (rem + 1) * 2, tot);
    res %= MOD;

    for (int i = 1; cur < ns.size() && i + tot <= n; i++) {
        // current pos = 1
        {
            assert(n - tot >= i);
            res += ((1LL * dfs(cur - 1, u - 1, (rem - (i - 1)) * 2, tot + i) * C[n - tot][i]) % MOD * powmod(ns[cur], i, MOD)) % MOD;
            res %= MOD;
        }

        // current pos = 0
        {
            assert(n - tot >= i);
            res += (((1LL * dfs(cur - 1, u, (rem - i) * 2, tot + i) * C[n - tot][i]) % MOD) * powmod(ns[cur], i, MOD)) % MOD;
            res %= MOD;
        }
    }

    return dp[cur][u][rem][tot] = (res % MOD);
}

int main() {
    init();
    input(n, m, k);
    m++;

    ns.resize(m);

    for (int i = 0; i < m; i++) {
        scanf("%lld", &ns[i]);
    }

    memset(dp, -1, sizeof(dp));

    llint res = 0;
    for (int i = 1; i <= k; i++) {
        res += dfs(m + 10, i, 0, 0);
        res %= MOD;
    }
    print(res);

    return 0;
}

/*

^^^TEST^^^
5 1 1
2 1
-----
40
$$$TEST$$$

^^^TEST^^^
5 1 2
2 1
-----
163
$$$TEST$$$

^^^TEST^^^
8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
-----
642171527
$$$TEST$$$

*/
