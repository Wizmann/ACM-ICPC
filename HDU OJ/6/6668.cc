#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    int T;
    input(T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> pa(n);
        vector<int> pb(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &pa[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &pb[i]);
        }

        int a = -1;
        int b = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (pa[i] == 0 && pb[i] == 0) {
                continue;
            }

            if (pa[i] == 0) {
                a = 0;
                b = 1;
                break;
            }

            if (pb[i] == 0) {
                a = 1;
                b = 0;
                break;
            }

            a = pa[i];
            b = pb[i];
            break;
        }

        if (a && b) {
            int g = gcd(a, b);
            a /= g;
            b /= g;
        }

        printf("%d/%d\n", a, b);
    }
    return 0;
}
