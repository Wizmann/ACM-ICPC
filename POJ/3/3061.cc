#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int T;
    input(T);
    while (T--) {
        int n, s;
        scanf("%d%d", &n, &s);
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        int p = 0;
        int q = 0;
        int tot = 0;
        int res = n + 1;
        while (p < n) {
            while (q < n && tot < s) {
                tot += ns[q];
                q++;
            }
            if (tot >= s) {
                res = min(res, q - p);
            }
            tot -= ns[p];
            p++;
        }
        if (res > n) {
            res = 0;
        }
        print(res);
    }
    return 0;
}
