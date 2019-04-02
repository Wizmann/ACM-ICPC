#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
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

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    input(T);
    int case_ = 1;
    while (T--) {
        printf("Case %d: ", case_++);
        int n;
        input(n);
        vector<int> ns(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        llint ca = 0;
        llint cb = 0;
        llint sa = 0;
        llint sb = 0;

        for (int i = 0; i < n; i++) {
            if (ns[i] > 0) {
                ca++;
                sa += ns[i];
            } else {
                cb++;
                sb += -ns[i];
            }
        }

        if (cb == ns.size()) {
            puts("inf");
            continue;
        }

        llint l = (n - cb);
        llint r = sa + sb;
        llint g = gcd(l, r);

        printf("%lld/%lld\n", r / g, l / g);
    }
    return 0;
}
