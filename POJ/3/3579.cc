#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
vector<int> ns;

int solve(int u) {
    int p = 0;
    int ans = 0;

    for (int i = 1; i < n; i++) {
        while (p < i && ns[i] - ns[p] > u) {
            p++;
        }
        ans += i - p;
    }
    return ans;
}

int main() {
    while (input(n)) {
        ns = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        sort(ns.begin(), ns.end());
        
        int k = ((n * (n - 1) / 2) + 1) / 2;

        int l = 0;
        int r = *ns.rbegin() - *ns.begin();

        while (l <= r) {
            int m = (1LL * l + r) / 2;
            if (solve(m) >= k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        print(l);
    }
    return 0;
}
