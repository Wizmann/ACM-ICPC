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

llint calc(int i, int j) {
    i++;
    j++;
    return 1LL * i * i + 100000LL * i + 1LL * j * j - 100000LL * j + 1LL * i * j;
}

llint do_count(llint line, llint n, llint value) {
    llint l = 0;
    llint r = n - 1;

    while (l <= r) {
        llint m = (l + r) / 2;
        if (calc(m, line) > value) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

llint solve(llint n, llint k) {
    llint l = -(1LL << 40);
    llint r = (1LL << 40);
    
    while (l <= r) {
        llint m = (l + r) / 2;

        llint tot = 0;
        for (llint i = 0; i < n; i++) {
            tot += do_count(i, n, m);
        }

        if (tot >= k) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    int T;
    input(T);

    while (T--) {
        int n;
        llint m;
        scanf("%d%lld", &n, &m);
        printf("%lld\n", solve(n, m));
    }
    return 0;
}
