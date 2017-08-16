#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    string a, b;
    while (input(a >> b)) {
        if (a == "0" && b == "0") {
            break;
        }
        int n = a.size() - 1;
        int m = b.size() - 1;

        int g = 0;
        int cnt = 0;
        while (n >= 0 || m >= 0) {
            int aa = n >= 0? a[n] - '0': 0;
            int bb = m >= 0? b[m] - '0': 0;

            if (aa + bb + g >= 10) {
                cnt++;
            }
            g = (aa + bb + g) / 10;
            n--;
            m--;
        }

        if (cnt == 0) {
            puts("No carry operation.");
        } else if (cnt == 1) {
            puts("1 carry operation.");
        } else {
            printf("%d carry operations.\n", cnt);
        }
    }
    return 0;
}
