#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n, k;
vector<int> ns;

bool solve() {
    if (k == 0) {
        return true;
    }

    if (n % (2 * k) != 0) {
        return false;
    }

    for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
            swap(ns[i + j], ns[i + j + k]);
        }
    }
    return true;
}

int main() {
    int T;
    input(T);
    while (T--) {
        input(n >> k);
        ns.resize(n);
        iota(ns.begin(), ns.end(), 1);

        bool flag = solve();
        if (flag == 0) {
            print("-1");
        } else {
            for (int i = 0; i < n; i++) {
                if (i) {
                    printf(" ");
                }
                printf("%d", ns[i]);
            }
            puts("");
        }
    }
    return 0;
}

