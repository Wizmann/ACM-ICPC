// https://codeforces.com/contest/355/problem/C

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    int n, l, r, ql, qr;
    input(n >> l >> r >> ql >> qr);

    vector<llint> ws(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ws[i]);
    }

    for (int i = 1; i < n; i++) {
        ws[i] += ws[i - 1];
    }

    auto segsum = [&](int a, int b) -> llint {
        assert(a >= 0 && a <= b && b < n);
        return ws[b] - (a - 1 >= 0? ws[a - 1]: 0);
    };


    llint res = INF;
    for (int i = -n; i <= n; i += 2) {
        int a = (n + i) / 2;
        assert((n + i) % 2 == 0);
        int b = n - a;

        // print(a << ' ' << b);

        int c = min(a, b);

        llint cur = 0;
        if (c) {
            cur += 1LL * segsum(0, c - 1) * l;
            cur += 1LL * segsum(n - c, n - 1) * r;
        }

        a -= c;
        b -= c;

        if (a) {
            assert (b == 0);
            cur += 1LL * segsum(c, n - c - 1) * l + 1LL * (a - 1) * ql;
        } else if (b) {
            assert (a == 0);
            cur += 1LL * segsum(c, n - c - 1) * r + 1LL * (b - 1) * qr;
        }
        // print(cur);

        res = min(res, cur);
    }
    print(res);

    return 0;
}

