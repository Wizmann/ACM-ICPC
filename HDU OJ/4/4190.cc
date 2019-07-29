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
    int n, b;
    while (input(n >> b) && n + b >= 0) {
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        int l = 0;
        int r = 5000123;

        while (l <= r) {
            int m = (1LL * l + r) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (ns[i] + m - 1) / m;
            }
            // print(l << ' ' << r << ' ' << cnt);
            if (cnt <= b) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        print(l);
    }
    return 0;
}
