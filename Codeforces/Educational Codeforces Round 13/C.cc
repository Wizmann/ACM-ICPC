#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

using llint = long long;

llint gcd(llint a, llint b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

llint lcm(llint a, llint b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n, a, b, p, q;
    input(n >> a >> b >> p >> q);

    llint c0, c1, c2;
    c0 = c1 = c2 = 0;

    llint c = lcm(a, b);
    c0 = n / a;
    c1 = n / b;
    c2 = n / c;

    c0 -= c2;
    c1 -= c2;

    llint res = c0 * p + c1 * q + c2 * max(p, q);
    print(res);

    return 0;
}
