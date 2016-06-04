#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 222;
const int INF = 0x3f3f3f3f;

typedef long long llint;

llint gcd(llint a, llint b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

llint lcm(llint a, llint b) {
    return a / gcd(a, b) * b;
}

int n;
llint g[SIZE][SIZE];
int trans[SIZE];

int main() {
    freopen("input.txt", "r", stdin);
    input(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &trans[i]);
    }
    
    memset(g, INF, sizeof(g));
    for(int i = 1; i <= n; i++) {
        g[i][trans[i]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }

    llint cir = 1;
    llint step = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i][i] < INF) {
            cir = lcm(cir, g[i][i]);
        } else {
            llint tmp = INF;
            for (int j = 1; j <= n; j++) {
                if (g[i][j] < INF && g[j][j] < INF) {
                    tmp = min(tmp, g[i][j]);
                }
            }
            step = max(step, tmp);
        }
    }

    for (int i = 1; /* pass */; i++) {
        if (cir * i >= step) {
            print(i * cir);
            break;
        }
    }

    return 0;
}
