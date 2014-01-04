//Result: 10341 Solve It    Accepted    C++ 0.035   2013-12-23 06:38:22
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const double eps = 1e-8;

double p, q, r, s, t, u;

inline double lambda(double x)
{
     return p * exp(-x) + 
        q * sin(x) + 
        r * cos(x) + 
        s*tan(x) + 
        t * x * x + u;
}

bool solve(double& ans) 
{
    double l = 0, r = 1;
    if (lambda(l) * lambda(r) > 0) {
        return false;
    }
    while (fabs(l - r) > eps) {
        double mid = (l + r) / 2;
        if (lambda(mid) > 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ans = r;

    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    while (input(p >> q >> r >> s >> t >> u)) {
        double ans = 0;
        if (!solve(ans)) {
            print("No solution");
        } else {
            printf("%.4lf\n", ans);
        }
    }
    return 0;
}


