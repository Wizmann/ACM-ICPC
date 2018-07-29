#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000000 + 7;

llint mypow(llint a, llint b, llint c) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % c;
        }
        b >>= 1;
        a = (a * a) % c;
    }
    return res % c;
}

llint f1(llint n) {
    llint a = mypow(4, (n / 2 - 1), MOD);
    llint b = 8;
    llint c = (a * b % MOD - 2 + MOD) % MOD;
    llint d = mypow(3, MOD - 2, MOD);

    return c * d % MOD;
}

llint f2(llint n) {
    llint a = mypow(4, n / 2, MOD);
    llint b = 4;
    llint c = (a * b % MOD - 1 + MOD) % MOD;
    llint d = mypow(3, MOD - 2, MOD);

    return c * d % MOD;
}

llint solve(llint n, llint m) {
    if (n == 1) {
        return 1;
    }
    if (m == 1) {
        return 1;
    }

    if (n % 2 == 0) {
        llint u = f1(n);
        llint v1 = (mypow(2, n, MOD) - 1 + MOD) % MOD;
        llint v2 = u * mypow(v1, m - 2, MOD) % MOD;
        return v2;
    } else {
        llint u = f2(n);
        llint v1 = (mypow(2, n, MOD) - 1 + MOD) % MOD;
        llint v2 = (2LL * (v1 - 1 + MOD) % MOD * u % MOD - (u - 1) + MOD) % MOD;
        llint v3 = mypow(v1, m - 2, MOD);
        llint v4 = (v2 * v3 % MOD + (u - 1)) % MOD;
        llint v5 = mypow(2 * (v1 - 1), MOD - 2, MOD);
        return v4 * v5 % MOD;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    llint n, m;
    input(T);

    assert(solve(31, 3) == 233745826);
    assert(solve(31, 2) == 431655758);
    assert(solve(31, 5) == 451197930);
    assert(f1(2) == 2);
    assert(f1(4) == 10);

    assert(f2(1) == 1);
    assert(f2(3) == 5);

    assert(solve(1, 2) == 1);
    assert(solve(1, 1) == 1);
    assert(solve(2, 2) == 2);
    assert(solve(2, 10) == 13122);
    assert(solve(18, 2) == 174762);
    assert(solve(18, 3) == 812634651);
    assert(solve(3, 4) == 229);
    assert(solve(3, 3) == 33);
    assert(solve(11, 3) == 2793473);
    assert(solve(19, 4) == 623271582);
    assert(solve(19, 2) == 349525);
    assert(solve(19, 3) == 251237632);
    assert(solve(19, 1) == 1);
    assert(solve(5, 123) == 857639541);
    assert(solve(6, 123) == 254293711);

    while (T--) {
        input(n >> m);
        print(solve(n, m));
    }
    return 0;
}

