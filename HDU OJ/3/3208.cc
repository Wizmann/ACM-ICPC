#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const double eps = 1e-6;
const int PN = 66;

bool isoverflow(llint a, llint b) {
    llint u = numeric_limits<llint>::max() / a;
    return u <= b;
}

llint fastpow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            if (isoverflow(res, a)) {
                return numeric_limits<llint>::max();
            }
            res *= a;
        }
        b >>= 1;
        if (isoverflow(a, a)) {
            a = numeric_limits<llint>::max();
        } else {
            a = a * a;
        }
    }
    return res;
}

llint fastsqrt(llint a, llint b) {
    llint l = 0;
    llint r = numeric_limits<llint>::max();

    while (l <= r) {
        llint m = (l >> 1) + (r >> 1) + (l & r & 1);
        if (fastpow(m, b) > a) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return r;
}

llint do_solve(llint n, llint p) {
    return fastsqrt(n, p) - 1;
}

llint solve(llint n) {
    vector<llint> ns(PN, 0);
    for (int i = 1; i < PN; i++) {
        ns[i] = do_solve(n, i);
    }
    llint res = 0;
    for (int i = PN - 1; i > 0; i--) {
        res += ns[i] * i;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                ns[j] -= ns[i];
            }
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);

    assert(fastsqrt(100, 1) == 100);
    assert(fastsqrt(1024, 10) == 2);
    assert(fastsqrt(1025, 10) == 2);
    assert(fastsqrt(2047, 10) == 2);
    assert(fastsqrt(2048, 11) == 2);
    assert(fastsqrt(12, 21345) == 1);
    assert(fastsqrt(2, 63) == 1);
    assert(solve(100) == 124);
    assert(solve(2) == 1);
    assert(solve(4) == 4);

    llint a, b;
    while (input(a >> b) && a + b) {
        print(solve(b) - solve(a - 1));
    }
    return 0;
}
