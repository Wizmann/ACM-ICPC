#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 100010;

typedef long long llint;

llint fac[SIZE];

llint mod_pow(llint a, llint n, llint mod)
{
    llint ret = 1;
    llint A = a;
    while (n) {
        if (n & 1) {
            ret = (ret * A) % mod;
        }
        A = (A * A) % mod;
        n >>= 1;
    }
    return ret;
}

void do_init(llint p)
{
    fac[0] = 1;
    for (int i = 1; i < p; i++) {
        fac[i] = fac[i - 1] * i % p;
    }
}

llint Lucas(llint a, llint k, llint p)
{
    llint ret = 1;
    while (a && k) {
        llint aa = a % p;
        llint bb = k % p;
        if (aa < bb) {
            return 0;
        }

        ret = ret * fac[aa] * \
              mod_pow(fac[bb] * fac[aa - bb] % p, p - 2, p) % p;
        a /= p;
        k /= p;
    }
    return ret;
}

int main()
{
    int T;
    input(T);
    while (T--) {
        llint n, m, p;
        input(n >> m >> p);
        do_init(p);
        print(Lucas(n + m, m, p));
    }
    return 0;
}
