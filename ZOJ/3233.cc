#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

llint gcd(llint a, llint b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

llint lcm(llint a, llint b) {
    if (numeric_limits<llint>::max() / a <= b / gcd(a, b)) {
        return numeric_limits<llint>::max();
    }
    return a / gcd(a, b) * b;
}

llint do_solve(const vector<llint>& ns, llint l1, llint u) {
    llint res = 0;
    int n = ns.size();
    for (int i = 1; i < (1 << n); i++) {
        llint l2 = 1;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                l2 = lcm(l2, ns[j]);
                cnt++;
            }
        }

        llint t = u / l2 - u / lcm(l1, l2);
        if (cnt % 2 == 0) {
            res -= t;
        } else {
            res += t;
        }
    }
    return res;
}

llint solve(const vector<llint>& ns, const vector<llint>& ms, llint low, llint high) {
    llint l = 1;
    for (size_t i = 0; i < ms.size(); i++) {
        l = lcm(l, ms[i]);
    }
    return do_solve(ns, l, high) - do_solve(ns, l, low - 1);
}

int main() {
    llint n, m;
    llint low, high;
    while (input(n >> m >> low >> high) && n + m + low + high) {
        vector<llint> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &ns[i]);
        }
        vector<llint> ms(m);
        for (int i = 0; i < m; i++) {
            scanf("%lld", &ms[i]);
        }
        print(solve(ns, ms, low, high));
    }
    return 0;
}
