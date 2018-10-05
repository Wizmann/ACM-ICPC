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

llint gcd(llint a, llint b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

llint lcm(llint a, llint b) {
    return 1LL * a * b / gcd(a, b);
}

llint solve(int n, int m, const vector<int>& ns) {
    llint res = 0;
    for (int i = 1; i < (1 << m); i++) {
        llint l = 1;
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                l = lcm(l, ns[j]);
                cnt++;
            }
        }
        if (cnt % 2 == 0) {
            res -= (n - 1) / l;
        } else {
            res += (n - 1) / l;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    vector<int> ns;
    while (input(n >> m)) {
        ns = vector<int>();
        int x;
        for (int i = 0; i < m; i++) {
            scanf("%d", &x);
            if (x > 0) {
                ns.push_back(x);
            }
        }
        m = ns.size();
        print(solve(n, m, ns));
    }
    return 0;
}
