#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

llint mypow(llint a, llint b, llint c) {
    llint ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b >>= 1;
    }
    return ans;
}

int main() {
    llint MOD = 1000000000 + 7;
    int n, m;
    input(n);
    input(m);
    
    if (n > m) {
        swap(n, m);
    }

    llint ans = 1;
    for (int i = 0; i < n - 1; i++) {
        ans *= (m + n - 2 - i);
        ans %= MOD;
        ans *= mypow(n - 1 - i, MOD - 2, MOD);
        ans %= MOD;
    }
    print(ans);
    return 0;
}
