#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int MAXN = 1234567;
const int MAXM = 12345;
const int MAXG = 1111;
const int MAXR = 1111;

const llint INF = 0x3f3f3f3f3f3f3f3fLL;

char visited[MAXM][MAXG];
int dis[MAXM][MAXG];

int main() {
    int n, m;
    input(n >> m);

    vector<int> sf(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &sf[i]);
    }
    sort(sf.begin(), sf.end());

    int G, R;
    input(G >> R);

    deque<pair<int, int> > dq;
    dq.push_back({0, 0});

    memset(visited, 0, sizeof(visited));
    memset(dis, 0x3f, sizeof(dis));
    dis[0][0] = 0;

    llint ans = INF;
    while (!dq.empty()) {
        int cur = dq.front().first;
        int mod = dq.front().second;
        dq.pop_front();

        if (visited[cur][mod]) {
            continue;
        }

        visited[cur][mod] = 1;

        if (mod == 0) {
            int disM = n - sf[cur];

            if (disM <= G) {
                llint res = (R + G) * dis[cur][mod] + disM;
                ans = min(ans, res);
            }
        }

        if (mod == G) {
            if (dis[cur][0] > dis[cur][G] + 1) {
                dis[cur][0] = dis[cur][G] + 1;
                dq.push_back({cur, 0});
            }
            continue;
        }

        if (cur - 1 >= 0) {
            int dnxt = mod + sf[cur] - sf[cur - 1];
            if (dnxt <= G) {
                dis[cur - 1][dnxt] = dis[cur][mod];
                dq.push_front({cur - 1, dnxt});
            }
        }

        if (cur + 1 < m) {
            int dnxt = mod + sf[cur + 1] - sf[cur];
            if (dnxt <= G) {
                dis[cur + 1][dnxt] = dis[cur][mod];
                dq.push_front({cur + 1, dnxt});
            }
        }
    }
    if (ans >= INF) {
        ans = -1;
    }
    print(ans);

    return 0;
}
