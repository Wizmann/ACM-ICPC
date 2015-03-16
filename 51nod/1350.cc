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

const llint MAX = 123456789012345678LL;
map<llint, llint> fib;

void init() {
    llint a = 1;
    llint b = 1;
    while (b < MAX) {
        fib[b] = -1;
        llint c = a + b;
        a = b;
        b = c;
    }
    fib[1] = 1;
    fib[2] = 2;
    fib[3] = 3;
}

llint solve(llint u) {
    bool is_fib = fib.find(u) != fib.end();

    if (is_fib && fib[u] != -1) {
        return fib[u];
    }

    pair<llint, llint> p = *(--fib.lower_bound(u));
            
    llint pre_fib = p.first;
    llint delta   = u - p.first;
    llint res = solve(pre_fib) + solve(delta) + delta;

    if (is_fib) {
        fib[u] = --res;
    }

    return res;
}

int main() {
    int T;
    llint n;
    input(T);
    init();
    while (T--) {
        input(n);
        print(solve(n));
    }
    return 0;
}
