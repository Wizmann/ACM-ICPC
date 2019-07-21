#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

#define max(a, b) (a > b? a: b)

typedef long long llint;

const int SIZE = 123456;
const llint INF = 1LL << 60;

int n;
llint ns[SIZE];

llint mylog(llint sum) {
    for (int i = 0; i < 35; i++) {
        if ((1LL << i) == sum) {
            return i;
        } else if ((1LL << i) > sum) {
            return max(0, i - 1);
        }
    }
    return -1;
}

llint brute_force() {
    llint res = 0;
    for (int i = 0; i < n; i++) {
        llint sum = 0;
        for (int j = i; j < n; j++) {
            sum += ns[j];
            res += 1LL * (mylog(sum) + 1) * (i + j + 2);
            print(i << ' ' << j << ' ' << 1LL * (mylog(sum) + 1) * (i + j + 2));
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    input(T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &ns[i]);
        }

        // llint bf = brute_force();
        // print(">> " << bf);

        for (int i = 1; i < n; i++) {
            ns[i] += ns[i - 1];
        }

        
        llint res = 0;
        for (int i = 0; i < 35; i++) {
            llint u = i == 0? 0: (1LL << i);
            llint v = i == 0? 1: (1LL << (i + 1)) - 1;

            // print(">> " << u << ' ' << v << ' ' << i);

            int l = 0;
            int r = 0;
            llint sum = 0;
            for (int j = 0; j < n; j++) {
                sum += ns[j];
                llint pre = j == 0? 0: ns[j - 1];

                l = max(l, j);
                r = max(r, j);

                while (l < n && ns[l] - pre < u) {
                    l++;
                }
                while (r < n && ns[r] - pre <= v) {
                    r++;
                }

                if (l >= n) {
                    break;
                }

                int m = r - l;
                llint inc = 1LL * (i + 1) * (m * (j + 1) + (1LL * (l + 1 + r) * m / 2));
                // print(i << ' ' << j << ' ' << l << ' ' << r << ' ' << inc);
                res += inc;
            }
        }

        printf("%lld\n", res);
    }
    return 0;
}
