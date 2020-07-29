// Solution1: O(3^n * n)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;

struct Point {
    int x, y, p;
};

int main() {
    int n;
    vector<Point> ps;
    vector<pair<int, int> > xs;
    vector<pair<int, int> > ys;

    input(n);

    int x, y, p;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &x, &y, &p);
        ps.push_back({x, y, p});

        xs.push_back({ x, i });
        ys.push_back({ y, i });
    }

    vector<llint> ans(n + 1, INFLL);
    vector<vector<int> > disx(1 << n);
    vector<vector<int> > disy(1 << n);

    for (int i = 0; i < (1 << n); i++) {
        disx[i] = vector<int>(n, INF);
        for (int j = 0; j < n; j++) {
            disx[i][j] = min(disx[i][j], abs(ps[j].x));
            if ((i & (1 << j)) == 0) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                disx[i][k] = min(disx[i][k], abs(ps[j].x - ps[k].x));
            }
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        disy[i] = vector<int>(n, INF);
        for (int j = 0; j < n; j++) {
            disy[i][j] = min(disy[i][j], abs(ps[j].y));
            if ((i & (1 << j)) == 0) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                disy[i][k] = min(disy[i][k], abs(ps[j].y - ps[k].y));
            }
        }
    }

    int status = 1;
    for (int i = 0; i < n; i++) {
        status *= 3;
    }

    for (int i = 0; i < status; i++) {
        int yy = 0;
        int xx = 0;

        int cur = i;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            xx <<= 1;
            yy <<= 1;
            int c = cur % 3;
            if (c == 0) {
                // pass
            } else if (c == 1) {
                xx |= 1;
                cnt++;
            } else {
                yy |= 1;
                cnt++;
            }
            cur /= 3;
        }

        vector<int> dis(n, INF);
        for (int j = 0; j < n; j++) {
            dis[j] = min(abs(ps[j].x), abs(ps[j].y));
        }

        for (int j = 0; j < n; j++) {
            dis[j] = min(dis[j], disx[xx][j]);
            dis[j] = min(dis[j], disy[yy][j]);
        }

        llint tot = 0;
        for (int j = 0; j < n; j++) {
            tot += 1LL * dis[j] * ps[j].p;
        }
        ans[cnt] = min(ans[cnt], tot);
    }

    for (int i = 0; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}


// Solution2: O(2^n * n^2)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int N = 18;

struct Point {
    int x, y, p;
};

llint dp1[N][N];
llint dp2[N][N];

llint calc(const vector<Point>& ps, const vector<int>& disx, int l, int r) {
    if (l == r) {
        return 0;
    }
    int n = ps.size();
    if (dp2[l][r] < INFLL) {
        return dp2[l][r];
    }
    llint tot = 0;
    for (int i = l + 1; i <= r; i++) {
        if (i <= 0 || i > n) {
            continue;
        }
        int ll = l > 0?  ps[l - 1].y: -INF;
        int rr = r <= n? ps[r - 1].y: INF;

        int mini = min(ps[i - 1].y - ll, rr - ps[i - 1].y);
        mini = min(mini, disx[i - 1]);
        mini = min(mini, abs(ps[i - 1].y));

        tot += 1LL * mini * ps[i - 1].p;
    }

    return dp2[l][r] = tot;
}

void solve(const vector<Point>& ps, vector<int>& dis, vector<llint>& ans, int status) {
    int n = ps.size();
    int cntx = 0;
    for (int i = 0; i < n; i++) {
        if (status & (1 << i)) {
            cntx++;
        }
    }

    {
        llint tot = 0;
        for (int j = 0; j < n; j++) {
            tot += 1LL * dis[j] * ps[j].p;
        }
        ans[cntx] = min(ans[cntx], tot);
    }

    int cnty = n - cntx;

    memset(dp1, 0xFF & INFLL, sizeof(dp1));
    memset(dp2, 0xFF & INFLL, sizeof(dp2));
    dp1[0][0] = 0;

    /*
    for (int i = 1; i <= n; i++) {
        dp1[i][0] = dp1[i - 1][0] + 1LL * dis[i - 1] * ps[i - 1].p;
    }
    */

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cnty; j++) {
            for (int k = 0; k <= i - 1; k++) {
                dp1[i][j] = min(dp1[i][j], dp1[k][j - 1] + calc(ps, dis, k, i));
            }
        }
    }
    /*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%lld ", dp1[i][j]);
        }
        puts("");
    }
    puts("--");
    */

    // print(status);
    for (int i = 1; i <= cnty; i++) {
        for (int j = i; j <= n; j++) {
            ans[i + cntx] = min(ans[i + cntx], dp1[j][i] + calc(ps, dis, j, n + 1));
            // printf("%d %d, %lld %lld\n", j, i, dp1[j][i], calc(ps, dis, j, n + 1));
        }
    }
    // puts("--");
}

int main() {
    int n;
    vector<Point> ps;

    input(n);

    int x, y, p;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &x, &y, &p);
        ps.push_back({x, y, p});
    }

    vector<llint> ans(n + 1, INFLL);

    sort(ps.begin(), ps.end(), [](const Point& pa, const Point& pb) {
        return pa.y < pb.y;
    });

    for (int i = 0; i < (1 << n); i++) {
        vector<int> dis(n);

        for (int j = 0; j < n; j++) {
            dis[j] = min(abs(ps[j].y), abs(ps[j].x));
        }

        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                dis[k] = min(dis[k], abs(ps[j].x - ps[k].x));
            }
        }

        solve(ps, dis, ans, i);
    }

    for (auto num: ans) {
        printf("%lld\n", num);
    }

    return 0;
}
