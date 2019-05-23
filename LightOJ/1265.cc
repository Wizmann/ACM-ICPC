#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1234;

double dp[SIZE][SIZE];

double C2(int x) {
    return 1.0 * x * (x - 1) / 2;
}

double solve(int t, int d) {
    if (t < 0 || d < 0) {
        return 0;
    }
    if (t == 0) {
        return 1;
    }

    if (dp[t][d] != -1) {
        return dp[t][d];
    }

    double u = C2(t + d + 1);
    double v = 1 - (d + C2(d)) / u;

    double res = C2(t) / u * solve(t - 2, d) + 1.0 * d * t / u * solve(t, d - 1);

    return dp[t][d] = res / v;
}

int main() {
    int T;
    input(T);
    int case_ = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dp[i][j] = -1;
        }
    }

    while (T--) {
        int a, b;
        input(a >> b);
        printf("Case %d: %.9lf\n", ++case_, solve(a, b));
    }

    return 0;
}
