#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int solve(int n, llint k) {
    if (k <= n) {
        return k;
    }

    k -= n + 1;
    k %= (n - 1) * 2;

    if (k < n - 1) {
        return k + 1;
    } else {
        k -= n - 1;
        if (k == n - 2) {
            return n;
        } else {
            return k + 1;
        }
    }
}

int main() {
    int n;
    llint k;
    int case_ = 0;

    while (scanf("%d%lld", &n, &k) != EOF) {
        printf("Case #%d: %d\n", ++case_, solve(n, k));
    }

    return 0;
}
