#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n, k;

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);

    int case_ = 0;

    while (T--) {
        input(n >> k);
        vector<int> ns(n);

        int cn = 0;
        int tn = 0;

        int cp = 0;
        int tp = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);

            if (ns[i] < 0) {
                cn++;
                tn += abs(ns[i]);
            }

            if (ns[i] > 0) {
                cp++;
                tp += abs(ns[i]);
            }
        }

        int kk = k;
        double u = -1;

        double avep = 1.0 * tp / cp;
        double aven = 1.0 * tn / cn;

        if (cn == n) {
            u = -1;
            k = -1;
        } else if (cn == 0) {
            u = 1.0 * tp / cp;
            kk = 0;
        } else if (k >= cn) {
            kk = cn;
            u = avep;
        } else {
            u = (1.0 * cp * avep + 1.0 * (cn - k) * aven) / (n - cn);
            kk = k;
        }

        for (int i = kk - 1; i >= 0; i--) {
            u = avep * cp / (n - i) + aven * (cn - i) / (n - i) + 1.0 * (cn - i) / (n - i) * u;
        }

        if (k == -1) {
            printf("Case %d: -1\n", ++case_);
        } else {
            printf("Case %d: %.7f\n", ++case_, u);
        }
    }

    return 0;
}
