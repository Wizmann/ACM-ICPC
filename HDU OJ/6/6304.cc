#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000000 + 7;
const llint DIV = MOD / 2 + 1;

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    input(T);
    while (T--) {
        llint n;
        scanf("%lld", &n);

        assert(n > 0);
        
        llint l = 1;
        llint r = n;

        while (l <= r) {
            llint m = (l + r) >> 1;
            llint cnt = 1;
            for (llint i = 0; i <= 63; i++) {
                cnt += m >> i;
            }

            if (cnt > n) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        llint m = r;
        llint ans = 0;

        n -= 1;

        for (llint i = 1, j = 1; m / i > 0; i *= 2, j++) {
            llint p = (m / i - m / (i * 2)) % MOD;
            llint pp = p * p % MOD;
            llint ii = i % MOD;
            n -= m / i;
            ans = ans % MOD + ((ii * j % MOD) * pp) % MOD;
        }

        ans += (m + 1) * n % MOD + 1;
        ans %= MOD;

        printf("%lld\n", ans);
    }
    return 0;
}
