#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int n;
vector<llint> g;

double Rand() { return (double)rand() / RAND_MAX; }

llint get_next(llint now, double t) {
    auto nxt = now;
    for (int i = 0; i < 5; i++) {
        int idx = min(n - 1, int(Rand() * n));
        nxt ^= (1LL << idx) * (Rand() < 0.5 * t ? 1: 0);
    }
    return nxt;
}

int calc(llint cur) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cur & (1LL << i)) {
            llint u = cur & g[i];
            if ((u | (1LL << i)) != cur) {
                return 0;
            }
            cnt++;
        }
    }
    return cnt;
}

int maxi = 0;
llint ans;

void simulateAnneal() {
    double t = 1;
    llint now = 0;
    int now_value = 0;

    while (t > 1. / RAND_MAX) {
        for (int i = 0; i < 10; /* pass */) {
            llint nxt = get_next(now, t);
            int nxt_value = calc(nxt);
            if (nxt_value == 0) {
                continue;
            }
            i++;
            if (nxt_value > maxi) {
                maxi = nxt_value;
                ans = nxt;
                /*
                printf("%d\n", maxi);
                for (int i = 0; i < n; i++) {
                    if (ans & (1LL << i)) {
                        printf("%d ", i);
                    }
                }
                puts("");
                */
            }
            double delta = nxt_value - now_value;
            if (delta >= 0 || exp(delta / t) > Rand()) {
                now = nxt;
                now_value = nxt_value;
            }
        }
        t *= 0.99;
    }
}

int main() {
    srand(time(nullptr));

    while (input(n) && n) {
        maxi = 0;
        ans = 0;

        g = vector<llint>(n, 0);

        int a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a);
                if (a) {
                    g[i] |= 1LL << j;
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            simulateAnneal();
        }
        print(maxi);
    }
    return 0;
}

/*
 *
^^^^^^^TEST^^^^^^^
5
0 1 1 0 1
1 0 1 1 1
1 1 0 1 1
0 1 1 0 1
1 1 1 1 0
0
--------
4
$$$$$TEST$$$


 *
 */
