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

const int SIZE = 444;
char buffer[SIZE];
const llint MOD = 1000000007LL;

int dp[SIZE][SIZE][SIZE];

llint fac[SIZE];
llint inv[SIZE];

llint mypow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
        assert(fac[i] > 0);
    }

    inv[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        inv[i] = mypow(fac[i], MOD - 2);
        assert(inv[i] > 0);
    }
    assert(fac[123] * inv[123] % MOD == 1);
}

llint C(int rem, int n) {
    return (1LL * fac[n] * inv[n - rem] % MOD) * inv[rem] % MOD;
}

llint do_solve(int rem, int n, llint cnt) {
    llint tot = C(rem, n);
    return 1LL * cnt * mypow(tot, MOD - 2) % MOD;

}

llint do_mod(llint x) {
    x %= MOD;
    x += MOD;
    return x % MOD;
}

llint solve(const string& s) {
    const int n = s.size();
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            dp[1][i][j] = j - i + 1;
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int i = len; i <= n; i++) {
            for (int j = 0; i + j - 1 < n; j++) {
                int l = j;
                int r = j + i - 1;
                dp[len][l][r] = do_mod(1LL * dp[len][l + 1][r] + dp[len][l][r - 1] - dp[len][l + 1][r - 1]);
                if (s[l] == s[r]) {
                    int pre = dp[len - 2][l + 1][r - 1];
                    if (len - 2 == 0) {
                        pre = 1;
                    }
                    dp[len][l][r] = do_mod(1LL * dp[len][l][r] + pre);
                }
            }
        }
    }

    llint p = 1;
    for (int i = 1; i < n; i++) {
        llint cnt = dp[i][0][n - 1];
        // print(i, n, cnt, do_solve(i, n, cnt));
        p = do_mod(p + do_solve(i, n, cnt));
    }
    return do_mod(p);

}

int main() {
    init();

    int T;
    input(T);

    
    for (int case_ = 0; case_ < T; case_++) {
        int n;
        input(n);

        scanf("%s", buffer);
        string s(buffer);

        printf("Case #%d: %lld\n", case_ + 1, solve(s));

    }

    return 0;
}

/*

^^^TEST^^^
2
2
ab
3
aba
-----
Case #1: 2
Case #2: 333333338
$$$TEST$$$

^^^TEST^^^
1
100
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
-----
Case #1: asd
$$$TEST$$$

*/
