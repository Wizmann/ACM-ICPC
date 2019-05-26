#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 55;
const double eps = 1e-8;

double p;
int a, b;

int main() {
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        input(p >> a >> b);
        if (p < eps) {
            printf("Case %d: %.6f\n", ++case_, 1.0 * a);
            continue;
        } else if (1 - p < eps) {
            printf("Case %d: %.6f\n", ++case_, 1.0 * b);
            continue;
        }

        double q = 1 - p;

        double u = (1 - pow(q, a - 1)) / p;
        double v = (1 - pow(p, b - 1)) / q;

        double f1 = (p * u * v + u) / (1 - p * q * u * v);
        double g1 = (f1 * q + 1) * v;

        printf("Case %d: %.6f\n", ++case_, q * f1 + p * g1 + 1);
    }
    return 0;
}
