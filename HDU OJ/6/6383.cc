#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int INF = 0x3f3f3f3f;

int main() {
    int T;
    input(T);
    while (T--) {
        int n;
        input(n);

        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        int l = 0;
        int r = INF;

        while (l <= r) {
            int m = (1LL * l + r) / 2;
            llint le = 0;
            llint gt = 0;

            for (auto num: ns) {
                if (num > m + 1) {
                    gt += (num - m) / 2;
                }
                if (num <= m) {
                    le += m - num;
                }
            }

            // print(m << ' ' << gt << ' ' << le);

            if (gt >= le) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        llint le = 0;
        llint gt = 0;
        llint lg = 0;

        for (auto num: ns) {
            if (num > r + 1) {
                gt += (num - r) / 2;
                lg += (num - r) % 2 == 0? 1: 0;
            }
            if (num <= r) {
                le += r - num;
                lg += r + 1 - num;
            }
        }

        // cout << le << ' ' << lg << ' ' << gt << endl;

        if (gt >= le && gt <= lg) {
            print(r);
        } else {
            puts("-1");
        }
    }
    return 0;
}
