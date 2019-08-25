#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

int dp[2][SIZE * 4];

int main() {
    int T;
    input(T);
    while (T--) {
        int n;
        scanf("%d", &n);
        map<int, int> mp;
        vector<pair<int, int> > ps;

        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);

            mp[a + 1] = -1;
            mp[a] = -1;
            mp[b - 1] = -1;
            mp[b] = -1;
            
            ps.push_back({a, b});
        }

        memset(dp[0], 0, sizeof(dp[0]));

        int idx = 0;
        for (auto kv : mp) {
            int key = kv.first;
            mp[key] = idx++;
        }

        unordered_map<int, int> ump;
        unordered_map<int, int> rmp;
        for (auto kv : mp) {
            int key = kv.first;
            int value = kv.second;

            ump[key] = value;
            rmp[value] = key;
        }

        int p = 0;
        for (int i = 0; i < n; i++) {
            int q = p ^ 1;
            memset(dp[q], INF, sizeof(dp[q]));

            int prel = ump[ps[max(0, i - 1)].first];
            int prer = ump[ps[max(0, i - 1)].second];

            // print(i << ' ' << prel << ' ' << prer);
            assert(prel <= prer);

            int l = ps[i].first;
            int r = ps[i].second;

            for (int j = prel; j <= prer; j++) {
                {
                    int cur = rmp[j];
                    int nxt = -1;
                    int step = 0;

                    if (cur <= l) {
                        step = (l - cur + 1) / 2;
                        cur = l;
                    } else if (cur >= r) {
                        step = (cur - r + 1) / 2;
                        cur = r;
                    } else {
                        // pass
                    }

                    nxt = ump[cur];

                    dp[q][nxt] = min(dp[q][nxt], dp[p][j] + step);
                }

                if (l != r) {
                    int cur = rmp[j];
                    int nxt = -1;
                    int step = 0;

                    if (cur <= l + 1) {
                        step = (l + 1 - cur + 1) / 2;
                        assert(step >= 0);
                        cur = l + 1;
                    } else if (cur >= r - 1) {
                        step = (cur - (r - 1) + 1) / 2;
                        assert(step >= 0);
                        cur = r - 1;
                    } else {
                        // pass
                    }
                    nxt = ump[cur];

                    dp[q][nxt] = min(dp[q][nxt], dp[p][j] + step);
                }
            }

            p = q;
        }
        int mini = INF;
        for (int i = 0; i < idx; i++) {
            mini = min(mini, dp[p][i]);
        }
        printf("%d\n", mini);
    }
    return 0;
}
