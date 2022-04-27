#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const double pi = acos(-1);
const double eps = 1e-9;

typedef long long llint;

int zero(double u) {
    if (u < -eps) {
        return -1;
    } else if (u > eps) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int T;
    input(T);
    while (T--) {
        double R, r, H;
        double V;

        scanf("%lf%lf%lf%lf", &R, &r, &H, &V);

        double bl = 0;
        double br = H;

        while (zero(bl - br) < 0) {
            double m = (bl + br) / 2;

            double h = m;
            double rr = r + (H - h) / H * (R - r);
            double v = pi * h * (rr * rr + R * R + rr * R) / 3;
            if (v <= V) {
                bl = m;
            } else {
                br = m;
            }
            // print(bl << ' ' << br << ' ' << v);
        }
        printf("%.6lf\n", bl);
    }
    return 0;
}
