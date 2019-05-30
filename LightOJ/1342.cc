#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5555;

struct Stick {
    int weight;
    int type;
};

int n;

int cnt1 = 0;
int cnt2 = 0;

int tot1 = 0;
int tot2 = 0;

double dp[2][SIZE];

double solve() {
    int p = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= cnt1; i++) {
        int q = p ^ 1;
        memset(dp[q], 0, sizeof(dp[q]));

        for (int j = 0; j <= cnt2; j++) {
            if (i + j == 0) {
                continue;
            }

            double res = 0;

            int n1 = i;
            int n2 = j;

            if (n2 > 0) {
                res += 1.0 * n2 / (n1 + cnt2) * dp[q][n2 - 1];
            }
            if (n1 > 0) {
                res += 1.0 * n1 / (n1 + cnt2) * dp[p][n2];
            }
            res += 1.0 * tot2 / (n1 + cnt2);

            double p = 1.0 - 1.0 * (cnt2 - n2) / (cnt2 + n1);

            dp[q][n2] = res / p;
        }
        p = q;
    }
    return dp[p][cnt2];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        input(n);
        vector<Stick> sticks;
        sticks = vector<Stick>(n);

        cnt1 = 0;
        cnt2 = 0;

        tot1 = 0;
        tot2 = 0;

        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            sticks[i] = {a, b};

            if (b == 1) {
                cnt1++;
                tot1 += a;
            } else if (b == 2) {
                cnt2++;
                tot2 += a;
            }
        }

        double r = solve() + tot1;

        printf("Case %d: %.7lf\n", ++case_, r);
    }
    return 0;
}
