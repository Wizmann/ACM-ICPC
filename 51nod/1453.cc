#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000007LL;

int n;
vector<int> colors;

llint fastpow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

llint C(llint a, llint b) {
    llint res = 1;
    for (int i = 0; i < a; i++) {
        res *= b - i;
        res %= MOD;
        res *= fastpow(i + 1, MOD - 2);
        res %= MOD;
    }
    return res;
}

int main() {
    input(n);
    colors.resize(n);
    llint m = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &colors[i]);
        m += colors[i];
    }

    llint ans = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans = (ans * C(colors[i] - 1, m - 1)) % MOD;
        m -= colors[i];
    }
    print(ans);
    return 0;
}
