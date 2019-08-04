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

typedef long long llint;

const int INF = 0x7fffffff;

int main() {
    int n, q;
    while (input(n >> q) && n + q) {
        vector<pair<int, int> > ns(n + 1);

        ns[0].first = 0;
        ns[0].second = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &ns[i].first);
            ns[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            ns[i].first += ns[i - 1].first;
        }
        sort(ns.begin(), ns.end());

        while (q--) {
            int query;
            int mini = INF;
            int ansl, ansr;
            scanf("%d", &query);
            int l = 0;
            int r = 1;
            while (l <= n && r <= n) {
                int u = ns[r].first - ns[l].first;
                if (abs(query - u) < abs(query - mini)) {
                    mini = u;
                    ansl = min(ns[l].second, ns[r].second);
                    ansr = max(ns[l].second, ns[r].second);
                }
                if (u < query) {
                    r++;
                } else if (u > query) {
                    l++;
                } else {
                    break;
                }
                r = max(l + 1, r);
            }
            printf("%d %d %d\n", mini, ansl + 1, ansr);
        }
    }
    return 0;
}
