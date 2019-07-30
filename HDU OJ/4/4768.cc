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

const llint INF = (1LL << 32) + 12345;

struct Flyer {
    int a, b, c;

    Flyer() {
        // pass
    }

    Flyer(int a_, int b_, int c_) : \
            a(a_), b(b_), c(c_) {
        // pass
    }
};

llint countFlyers(const vector<Flyer>& flyers, llint m) {
    const int n = flyers.size();
    llint cnt = 0;
    for (int i = 0; i < n; i++) {
        llint ll = flyers[i].a;
        llint rr = min(m, 1LL * flyers[i].b);
        llint k = flyers[i].c;

        if (ll <= rr) {
            cnt += (rr - ll + k) / k;
        }
    }
    return cnt;
}

int main() {
    int n;
    while (input(n)) {
        vector<Flyer> flyers;
        int a, b, c;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            flyers.push_back(Flyer(a, b, c));
        }

        llint l = 1;
        llint r = INF;

        while (l <= r) {
            llint m = (l + r) / 2;

            llint cnt = countFlyers(flyers, m);

            // print(m << ' ' << cnt);

            if (cnt % 2 == 0) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (l >= INF) {
            puts("DC Qiang is unhappy.");
        } else {
            printf("%lld %lld\n", l, countFlyers(flyers, l) - countFlyers(flyers, l - 1));
        }
    }

    return 0;
}
