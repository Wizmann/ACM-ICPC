#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1234;
const int N = 10;
const int M = (1 << N) + 123;

struct Object {
    int v, s;
};

int n, m;
int dp[2][M];
vector<Object> objs;

int solve() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
        int q = p ^ 1;
        memset(dp[q], -1, sizeof(dp[q]));
        for (int j = M - 1; j >= 0; j--) {
            dp[q][j] = max(dp[q][j], dp[p][j]);
            if (dp[p][j] >= 0) {
                int jj = j ^ objs[i].s;
                dp[q][jj] = max(dp[q][jj], dp[p][j] + objs[i].v);
            }
        }
        p = q;
    }

    return dp[p][(1 << m) - 1];
}

int main() {
    int T;
    input(T);

    while (T--) {
        objs.clear();
        scanf("%d%d", &n, &m);

        int a, b, c;
        for (int i = 0; i < n; i++) {
            int status = 0;
            scanf("%d%d", &a, &b);
            for (int j = 0; j < b; j++) {
                scanf("%d", &c);
                c--;
                status |= (1 << c);
            }
            objs.push_back({a, status});
        }

        print(solve());
    }

    return 0;
}

