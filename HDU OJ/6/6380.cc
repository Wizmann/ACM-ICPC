#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    while (T--) {
        int n, m, k;
        input(n >> m >> k);
        vector<int> deg(n);

        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            deg[a]++;
            deg[b]++;
        }

        int maxi = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, deg[i]);
        }

        print(min(n - 1, maxi + (n - 1 - m + k)));
    }
    return 0;
}
