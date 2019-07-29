#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint INF = llint(1e20);
const llint MOD = 1000000000 + 7;

llint do_sum(int first, int k) {
    int last = first + k - 1;
    return (1LL * first + last) * k / 2;
}

int do_find(int first, int n, int k) {
    int l = first;
    int r = n;
    while (l <= r) {
        int m = (l + r) >> 1;
        llint tot = do_sum(m, k);
        if (tot > n) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int do_multi(int first, int n, int k) {
    llint res = 1;
    while (k) {
        int u = do_find(first, n, k);
        res = (res * u) % MOD;
        n -= u;
        k -= 1;
    }
    return res;
}

int solve(int n, int k) {
    int l = 1;
    int r = n;
    while (l <= r) {
        int m = (1LL * l + r) / 2;
        llint tot = do_sum(m, k);
        if (tot > n) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (r == 0) {
        return -1;
    }
    return do_multi(r, n, k);
}

int main() {
    int T;
    input(T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", solve(n, k));
    }
    return 0;
}
