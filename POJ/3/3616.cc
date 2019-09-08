#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 1234567;
const int SIZE = 1234;
const int INF = 0x3f3f3f3f;

struct Interval {
    int st, end, e;

    Interval() {}
    Interval(int st_, int end_, int e_) : \
            st(st_), end(end_), e(e_) {
        // pass
    }

    bool operator < (const Interval& other) const {
        return st < other.st;
    }
};

vector<Interval> g[N];

int main() {
    freopen("input.txt", "r", stdin);
    int n, m, r;
    while (input(n >> m >> r)) {
        for (int i = 0; i < N; i++) {
            g[i].clear();
        }

        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            a++;
            b++;
            g[a].push_back(Interval(a, b, c));
        }
        n += 1;

        vector<int> dp(n + 1, -INF);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], dp[i - 1]);

            for (int j = 0; j < g[i].size(); j++) {
                const Interval& it = g[i][j];

                int pre = i - r >= 0? dp[i - r]: 0;
                dp[it.end] = max(dp[it.end], pre + it.e);
            }
        }
        print(dp[n]);
    }

    return 0;
}
