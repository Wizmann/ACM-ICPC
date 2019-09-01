#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <list>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int main() {
    int n;
    while (input(n) && n) {
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        int maxi = 0;
        vector<int> dp = ns;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (ns[i] > ns[j]) {
                    dp[i] = max(dp[i], dp[j] + ns[i]);
                }
                maxi = max(maxi, dp[i]);
            }
        }
        printf("%d\n", maxi);
    }
    return 0;
}
