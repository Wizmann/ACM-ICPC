#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5555;

const int eYES = 0;
const int eNO = 1;
const int INF = 0x3f3f3f3f;

double dp[2][2][SIZE];

double solve(int n, int s) {
    int nYes = s - 2 * n;
    int nNo = n - nYes;
    memset(dp, 0, sizeof(dp));
    int p = 0;

    for (int i = n - 1; i >= 0; i--) {
        int q = p ^ 1;

        int minYes = max(0, i - nNo);
        int maxYes = min(nYes, i);

        for (int j = minYes; j <= maxYes; j++) {
            double py = 1.0 * (nYes - j) / (n - i);
            double pn = 1 - py;
            dp[q][eYES][j] = py * (dp[p][eYES][j + 1] + 1) + pn * (dp[p][eNO][j]);
            dp[q][eNO][j]  = py * (dp[p][eYES][j + 1]) + pn * (dp[p][eNO][j] + 1);
        }
        p = q;
    }
    return n - dp[p][eYES][0];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    int case_ = 0;

    while (T--) {
        int a, b;
        input(a >> b);
        printf("Case %d: %.9lf\n", ++case_, solve(a, b));
    }

    return 0;
}
