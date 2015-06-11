#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

llint gcdEx(llint a, llint b, llint &x, llint &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        llint r = gcdEx(b, a % b, x, y);
        llint t = x;
        x = y;
        y = t - a / b * y;
        return r;
    }
}

llint solve(llint n, llint a, llint b) {
    llint x = 0;
    llint y = 0;
    llint g = gcdEx(a, b, x, y);
    llint l = a * b / g;
    
    if ((n + 1) % g != 0) {
        return 0;
    }
    llint f = (n + 1) / g;
    llint aa = x * f;
    llint bb = y * f;
    
    if (aa > bb) {
        swap(a, b);
        swap(aa, bb);
    }
    
    if (aa <= 0) {
        llint diff = abs(aa) / (l / a) + 1;
        bb -= (l / b) * diff;
        aa += (l / a) * diff;
    }
    
    if (bb <= 0) {
        return 0;
    }
    
    bb *= b;

    return 1 + (bb - 1) / l + (n - bb) / l;
}

int main() {
    int T;
    int n, a, b;
    input(T);
    while (T--) {
        scanf("%d%d%d", &n, &a, &b);
        llint ans = solve(n, a, b);
        printf("%lld\n", ans);
    }
    return 0;
}
