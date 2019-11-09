#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <cassert>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 1000000;

set<int> primes = {2, 3, 5};

void init() {
    for (int i = 6; i <= N; i++) {
        bool flag = true;
        for (auto p : primes) {
            if (1LL * p * p > i) {
                break;
            }
            if (i % p == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            primes.insert(i);
        }
    }
}

int main() {
    init();

    int n;
    input(n);

    llint x;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        llint y = sqrt(x) + 0.5;
        
        if (x != 1 && y * y == x && primes.count(y)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}


