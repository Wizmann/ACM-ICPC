#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 100010;

const int INF = 0x3f3f3f3f;
const llint MOD = 1000000000 + 7;

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

inline llint inv(llint x) {
    return powmod(x, MOD - 2, MOD);
}

const int SIZE = 200010;

int n;
vector<int> ans;
vector<int> dp;
vector<int> cnt;
vector<int> g[SIZE];
vector<int> factor;
vector<int> factorinv;

void init() {
    factor.resize(SIZE);
    factorinv.resize(SIZE);
    factor[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        factor[i] = 1LL * factor[i - 1] * i % MOD;
    }
    for (int i = 0; i < SIZE; i++) {
        factorinv[i] = inv(factor[i]);
    }
}

llint C(int a, int b) {
    return 1LL * ((1LL * factor[b] * factorinv[b - a]) % MOD) * factorinv[a] % MOD;
}

void dfs1(int pre, int cur) {
    cnt[cur] = 1;
    llint res = 1;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        dfs1(cur, nxt);
        cnt[cur] += cnt[nxt];
        llint c = C(cnt[nxt], cnt[cur] - 1);
        res *= 1LL * c * dp[nxt] % MOD;
        res %= MOD;
    }
    dp[cur] = res;
}

void dfs2(int pre, int cur) {
    for (auto nxt : g[cur]) {
        if (pre == nxt) {
            continue;
        }
        ans[nxt] = 1LL * ans[cur] * inv(1LL * dp[nxt] * C(cnt[nxt], n - 1) % MOD) % MOD;
        ans[nxt] = (1LL * ans[nxt] * dp[nxt] % MOD) * C(n - cnt[nxt], n - 1) % MOD;
        dfs2(cur, nxt);
    }
}

int readint() {
    int n = 0; int f = 1; char ch = getchar();
    while ('0' > ch || ch > '9') {
        if(ch == '-') f *= -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9'){
        n = (n << 1) + (n << 3) + ch - '0';
        ch = getchar();
    }
    return f * n;
}

void printllint(llint x) {
    if (x / 10) {
        printllint(x / 10);
    }
    putchar(x % 10 + '0');
}


int main() {
    init();

    input(n);

    int a, b;
    int idx = 0;
    for (int i = 0; i < n - 1; i++) {
        a = readint() - 1;
        b = readint() - 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cnt = vector<int>(SIZE, 0);
    dp  = vector<int>(SIZE, 0);
    ans = vector<int>(SIZE, 0);

    dfs1(-1, 0);
    ans[0] = dp[0];

    dfs2(-1, 0);

    for (int i = 0; i < n; i++) {
        printllint(ans[i]);
        puts("");
    }

    return 0;
}

/*
^^^TEST^^^
3
1 2
1 3
-------
2
1
1
$$$TEST$$$

^^^TEST^^^
2
1 2
-------
1
1
$$$TEST$$$

^^^TEST^^^
5
1 2
2 3
3 4
3 5
-------
2
8
12
3
3
$$$TEST$$$

^^^TEST^^^
8
1 2
2 3
3 4
3 5
3 6
6 7
6 8
------
40
280
840
120
120
504
72
72
$$$TEST$$$
*/

