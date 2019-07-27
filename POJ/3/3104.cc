#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int main() {
    int n;
    input(n);

    vector<int> ns(n);
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
        maxi = max(maxi, ns[i]);
    }

    int k;
    input(k);

    if (k == 1) {
        print(maxi);
        return 0;
    }

    llint l = 0;
    llint r = 1e10;

    while (l <= r) {
        llint m = (l + r) / 2;
        llint extra = 0;
        for (int i = 0; i < n; i++) {
            llint cur = max(0LL, ns[i] - m);
            extra += (cur + k - 2) / (k - 1);
        }

        // print(m << ' ' << extra);

        if (extra <= m) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    print(l);

    return 0;
}
