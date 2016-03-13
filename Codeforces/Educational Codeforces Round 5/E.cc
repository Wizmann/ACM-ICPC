#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000000 + 7;

llint n, m;

llint fast_pow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    llint ans = 0;
    input(n >> m);
    
    //llint rev2 = fast_pow(2, MOD - 2);
    llint rev2 = 500000004;

    if (m > n) {
        ans += (((m - n) % MOD) * (n % MOD)) % MOD;
        m = n;
    }

    llint idx = m;
    for (llint i = 2; i <= n; /* pass */) {
        llint a = n / i;
        a++;

        if (a == 1) {
            break;
        }

        if (a <= idx) {
            llint x = n % idx;
            llint y = n % a;

            llint v0 = (x + y) % MOD;
            llint v1 = (idx - a + 1) % MOD;
            llint v2 = rev2 % MOD;
            
            ans = (ans % MOD + (((v0 * v1) % MOD) * v2) % MOD) % MOD;
            idx = a - 1;
        }

        if (n / (i + 1) == 0) {
            break;
        }
        i = max(i + 1, n / (n / (i + 1)));
    }
    print(ans % MOD);
    return 0;
}
