#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int HALFDAY = 12 * 60 * 60;
const int ROUND = 360;

int main() {
    freopen("input.txt", "r", stdin);
    double angle;
    while (input(angle) && angle >= 0) {
        const double vh = 1.0 * ROUND / (12 * 60 * 60);
        const double vm = 1.0 * ROUND / (60 * 60);
        const double vs = 1.0 * ROUND / (60);

        const double t_hm = 1.0 * ROUND / (vm - vh);
        const double t_hs = 1.0 * ROUND / (vs - vh);
        const double t_ms = 1.0 * ROUND / (vs - vm);

        const double u_hm = angle / (vm - vh);
        const double u_hs = angle / (vs - vh);
        const double u_ms = angle / (vs - vm);

        const double v_hm = (1.0 * ROUND - angle) / (vm - vh);
        const double v_hs = (1.0 * ROUND - angle) / (vs - vh);
        const double v_ms = (1.0 * ROUND - angle) / (vs - vm);

        double ans = 0;

        for (double i = 0; i <= HALFDAY; i += t_hm) {
            for (double j = 0; j <= HALFDAY; j += t_hs) {
                if (j + u_hs > i + v_hm) {
                    break;
                }
                if (i + u_hm > j + v_hs) {
                    continue;
                }
                for (double k = 0; k <= HALFDAY; k += t_ms) {
                    if (k + u_ms > i + v_hm || k + u_ms > j + v_hs) {
                        break;
                    }
                    if (k + v_ms < i + u_hm || k + v_ms < j + u_hs) {
                        continue;
                    }
                    double p = max(i + u_hm, max(j + u_hs, k + u_ms));
                    double q = min(i + v_hm, min(j + v_hs, k + v_ms));

                    ans += max(0.0, q - p);
                }
            }
        }
        printf("%.3lf\n", ans / HALFDAY * 100);
    }
    return 0;
}
