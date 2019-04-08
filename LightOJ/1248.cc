#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;

int n;
double dp[SIZE];

double solve(int k) {
    if (dp[k] >= 0) {
        return dp[k];
    }
    if (k == 0) {
        return 0;
    }
    return solve(k - 1) + 1.0 * n / k;
}

int main() {
    int T;
    int case_ = 0;
    input(T);
    while (T--) {
        scanf("%d", &n);
        fill(dp, dp + SIZE, -1);
        printf("Case %d: %.6lf\n", ++case_, solve(n));
    }

    return 0;
}
