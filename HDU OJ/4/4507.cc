#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <climits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1e9 + 7;

struct Node {
    llint v1;
    llint v2;
    llint cnt;
};

Node dp[20][11][11];

llint mod_plus(llint a, llint b) {
    assert(a >= 0);
    assert(b >= 0);
    a %= MOD;
    b %= MOD;
    assert(numeric_limits<llint>::max() - b >= a);
    llint res = (a + b) % MOD;
    assert(res >= 0);
    return res;
}

llint mod_mult(llint a, llint b) {
    assert(a >= 0);
    assert(b >= 0);
    a %= MOD;
    b %= MOD;
    if (a && b) {
        assert(numeric_limits<llint>::max() / b >= a);
    }
    llint res = (a * b) % MOD;
    assert(res >= 0);
    return res;
}

Node dfs(const string& ns, int pos, int dsum, int nsum, bool lt) {
    const int l = ns.size() - pos;
    auto& u = dp[l][dsum][nsum];
    if (lt && u.cnt != -1) {
        return u;
    }

    if (l == 0) {
        if (dsum != 0 && nsum != 0) {
            return {0, 0, 1};
        } else {
            return {0, 0, 0};
        }
    }

    llint cur = ns[pos] - '0';
    Node res = {0, 0, 0};
    for (llint i = 0; i < (lt? 10: cur + 1); i++) {
        if (i == 7) {
            continue;
        }
        
        llint ii = i;
        for (int j = 0; j < l - 1; j++) {
            ii = (ii * 10) % MOD;
        }
        assert(ii >= 0);

        llint iip = (ii * ii) % MOD;
        assert(iip >= 0);

        auto p = dfs(ns, pos + 1, (dsum + i) % 7, (nsum * 10 + i) % 7, lt || i < cur);
        p.v1 %= MOD;
        p.v2 %= MOD;
        p.cnt %= MOD;

        res.v1 %= MOD;
        res.v2 %= MOD;
        res.cnt %= MOD;

        res.v1 = mod_plus(res.v1, mod_mult(ii, p.cnt)) % MOD;
        assert(res.v1 >= 0);
        res.v1 = mod_plus(res.v1, p.v1) % MOD;
        assert(res.v1 >= 0);

        res.v2 = mod_plus(res.v2, mod_mult(iip, p.cnt)) % MOD;
        assert(res.v2 >= 0);
        res.v2 = mod_plus(res.v2, p.v2) % MOD;
        assert(res.v2 >= 0);
        res.v2 = mod_plus(res.v2, mod_mult(ii, p.v1)) % MOD;
        assert(res.v2 >= 0);
        res.v2 = mod_plus(res.v2, mod_mult(ii, p.v1)) % MOD;
        assert(res.v2 >= 0);

        res.cnt = mod_plus(res.cnt, p.cnt);
        assert(res.cnt >= 0);
    }
    if (lt) {
        return u = res;
    } else {
        return res;
    }
}

llint solve(llint x) {
    string xs = to_string(x);
    return dfs(xs, 0, 0, 0, false).v2 % MOD;
}

int main() {
    int T;
    input(T);

    memset(dp, -1, sizeof(dp));

    llint l, r;
    while (T--) {
        scanf("%lld%lld", &l, &r);
        llint a = solve(r);
        llint b = solve(l - 1);
        llint ans = ((a - b) % MOD + MOD) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
