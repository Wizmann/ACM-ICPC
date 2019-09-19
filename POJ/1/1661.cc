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

typedef long long llint;

const int INF = 0x3f3f3f3f;
const int SIZE = 1111;

struct Board {
    int x0, x1, y;

    Board() {}
    Board(int x0_, int x1_, int y_) : x0(x0_), x1(x1_), y(y_) {
        assert(x0 <= x1);
    }
};

int dp[2][SIZE];
vector<Board> bs;

int dfs(int cur, int lr, int n, int mm) {
    // print(cur << ' ' << n + 1 << ' ' << t);
    if (cur == n + 1) {
        return 0;
    }
    if (dp[lr][cur] < INF) {
        // print(dp[lr][cur] << ' ' << INF);
        return dp[lr][cur];
    }

    int cx = lr == 0? bs[cur].x0 : bs[cur].x1;
    int cy = bs[cur].y;

    int maxi = -INF;
    int maxv = +INF;

    for (int i = 0; i <= n + 1; i++) {
        const Board& b = bs[i];

        if (b.y >= cy || cy - b.y > mm) {
            continue;
        }

        if (b.x0 > cx || b.x1 < cx) {
            continue;
        }

        int tt0 = (cy - b.y) + (i == n + 1? 0: abs(cx - b.x0));
        int tt1 = (cy - b.y) + (i == n + 1? 0: abs(cx - b.x1));

        int v0 = dfs(i, 0, n, mm) + tt0;
        int v1 = dfs(i, 1, n, mm) + tt1;

        if (b.y > maxi) {
            maxi = b.y;
            maxv = min(v0, v1);
        }
    }
    return dp[lr][cur] = maxv;
}

int main() {
    int T;
    input(T);
    while (T--) {
        int n, x, y, mm;

        scanf("%d%d%d%d", &n, &x, &y, &mm);

        bs = vector<Board>(n + 1);

        bs[0] = Board(x, x, y);

        int a, b, c;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            bs[i] = Board(a, b, c);
        }

        bs.push_back(Board(-INF, INF, 0));

        memset(dp, INF, sizeof(dp));

        printf("%d\n", dfs(0, 0, n, mm));
    }
    return 0;
}
