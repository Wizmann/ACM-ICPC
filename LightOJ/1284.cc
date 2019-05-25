#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

double calc(int p, int n) {
    return 1 - 1.0 * ((p - 1) * (p - 1) + (n - p) * (n - p)) / n / n;
}

double solve(int a, int b, int c, int v) {
    double res = 0;
    for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
    for (int k = 1; k <= c; k++) {
        double pa = calc(i, a);
        double pb = calc(j, b);
        double pc = calc(k, c);
        double p = pa * pb * pc;

        double q = 0.5 - 0.5 * pow(1 - 2 * p, v);

        res += q;
    }
    }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);

    int case_ = 0;
    while (T--) {
        int a, b, c, k;
        input(a >> b >> c >> k);
        printf("Case %d: %lf\n", 
                ++case_, solve(a, b, c, k));
    }

    return 0;
}
