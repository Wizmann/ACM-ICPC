#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

llint solve(llint a, llint b) {
    if (a > b) {
        swap(a, b);
    }
    
    llint res = 0;
    for (llint i = 0; i < 64; i++) {
        llint u = a & (1LL << i);
        if (!u) {
            continue;
        }
        llint v = (1LL << i) - (a & ((1LL << i) - 1));
        if (b - a >= v) {
            continue;
        }
        res |= 1LL << i;
    }
    return res;
}

int main() {
    int T;
    input(T);
    while (T--) {
        llint a, b;
        input(a >> b);
        print(solve(a, b));
    }
    return 0;
}
