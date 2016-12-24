#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int n;
llint f;
set<llint> uf;
set<llint> factors;

llint gcd(llint a, llint b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    input(n);
    input(f);

    for (int i = 0; i < n; i++) {
        llint x;
        scanf("%lld", &x);
        uf.insert(gcd(f, x));
    }

    for (llint i = 1; i * i <= f; i++) {
        if (f % i == 0) {
            factors.insert(i);
            factors.insert(f / i);
        }
    }

    for (auto num: uf) {
        for (auto iter = factors.begin(); 
                iter != factors.end(); 
                /* pass */) {

            if (num % *iter == 0) {
                iter = factors.erase(iter);
            } else {
                ++iter;
            }
        }
        if (factors.empty()) {
            break;
        }
    }

    print(factors.size());

    return 0;
}
