#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

llint calc(llint m, int step, llint ub) {
    llint a = m - 1;
    llint b = m + step - 1;

    llint ta = (a * (a + 1) * (2 * a + 1) / 6);
    llint tb = (b * (b + 1) * (2 * b + 1) / 6);

    return tb - ta;
}

int main() {
    llint n;
    input(n);

    vector<pair<int, llint> > res;

    for (int i = 1; /* pass */; i++) {
        llint l = 1;
        llint r = (sqrt(n / i)) + 123;

        while (l <= r) {
            llint m = (l + r) / 2;

            llint tot = calc(m, i, n);

            if (tot > n) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        // print(i << ' ' << r);

        if (r == 0) {
            break;
        }

        llint tot = calc(r, i, n);
        assert(tot <= n);
        if (tot == n) {
            // print(i << ' ' << r << ' ' << tot);
            res.push_back(pair<int, llint>(i, r));
        }
    }

    printf("%d\n", int(res.size()));

    for (int i = res.size() - 1; i >= 0; i--) {
        int step = res[i].first;
        llint r = res[i].second;
        printf("%d", step);
        for (int j = 0; j < step; j++) {
            printf(" %lld", r + j);
        }
        puts("");
    }

    return 0;
}
