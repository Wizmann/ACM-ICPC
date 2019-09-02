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

const int N = 12345;
const int INF = 0x3f3f3f3f;

int main() {
    int T;
    input(T);
    while (T--) {
        int e, f;
        scanf("%d%d", &e, &f);

        int w = f - e;

        int n;
        scanf("%d", &n);
        vector<pair<int, int> > ns(n);

        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            ns[i] = {a, b};
        }

        vector<int> dp(N, INF);
        dp[0] = 0;

        for (const auto& p: ns) {
            for (int i = 1; 1LL * p.second * i <= w; i *= 2) {
                for (int j = w; j >= 0; j--) {
                    if (dp[j] == -1) {
                        continue;
                    }
                    int nxt = j + p.second * i;
                    if (nxt > w) {
                        continue;
                    }

                    dp[nxt] = min(dp[nxt], dp[j] + i * p.first);
                }
            }
        }

        if (dp[w] >= INF) {
            puts("This is impossible.");
        } else {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[w]);
        }
    }

    return 0;
}
