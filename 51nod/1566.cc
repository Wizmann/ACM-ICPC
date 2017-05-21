#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 333;

int dp1[SIZE][SIZE];
int dp2[SIZE][SIZE];
int dp3[SIZE][SIZE];
map<int, int> mp;
vector<int> ns;

int n, t;

int main() {
    input(n >> t);

    ns.resize(SIZE);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
        mp[ns[i]] = -1;
    }

    int idx = 1;
    for (auto& item: mp) {
        item.second = idx++;
    }

    for (int i = 0; i < n; i++) {
        ns[i] = mp[ns[i]];
    }

    memset(dp1, 0, sizeof(dp1));
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < n; j++) {
            int cur = ns[j];
            if (cur < i) {
                continue;
            }
            dp1[i][j] = 1;
            for (int k = 0; k < j; k++) {
                if (cur >= ns[k] && ns[k] >= i) {
                    dp1[i][j] = max(dp1[i][j], dp1[i][k] + 1);
                }
            }
        }
    }
    
    memset(dp2, -1, sizeof(dp2));

    dp2[0][0] = 0;

    for (int i = 1; i <= min(t, SIZE - 1); i++) {
        for (int j = 0; j < n; j++) {
            int cur = ns[j];
            assert (cur <= n);
            for (int pre = 0; pre <= cur; pre++) {
                int cnt = dp1[pre][j];
                dp2[i][cur] = max(dp2[i][cur], dp2[i - 1][pre] + cnt);
                // print(i << ' ' << pre << ' ' << cur << ' ' << dp2[i - 1][pre] + cnt << ' ' << cnt);
            }
        }
    }

    map<int, int> counter;
    for (int i = 0; i < n; i++) {
        counter[ns[i]]++;
    }

    int ans = 0;

    if (t < SIZE) {
        for (int i = 0; i < SIZE; i++) {
            ans = max(ans, dp2[t][i]);
        }
    } else {
        memset(dp3, 0, sizeof(dp3));
        int delta = max(0, t - (SIZE - 1) * 2);
        for (int i = 0; i < n; i++) {
            int cur = ns[i];
            dp3[0][cur] = dp2[SIZE - 1][cur] + delta * counter[cur];
        }
        
        for (int i = 1; i <= (t - delta - (SIZE - 1)); i++) {
            for (int j = 0; j < n; j++) {
                int cur = ns[j];
                for (int pre = 0; pre <= cur; pre++) {
                    dp3[i][cur] = max(dp3[i][cur], dp3[i - 1][pre] + dp1[pre][j]);
                }
            }
        }
        
        for (int i = 0; i < SIZE; i++) {
            ans = max(ans, dp3[t - delta - (SIZE - 1)][i]);
        }
    }

    print(ans);
    return 0;
}
