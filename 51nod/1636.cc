#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123;

struct Course {
    llint a, b, c;
};

int n, m, kk;
vector<Course> ps;

llint dp[SIZE][SIZE][SIZE];

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> m >> kk);

    llint a, b, c;
    for (int i = 0; i < m; i++) {
        input(a >> b >> c);
        ps.push_back({a, b, c});
    }

    sort(ps.begin(), ps.end(), [](const Course& c1, const Course& c2) {
        return c1.c < c2.c;
    });


    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                for (int k = 0; ps[j].a + k <= ps[j].b; k++) {
                    dp[i][j][k] = ps[j].a + k;
                }
                continue;
            } 

            for (int k = 0; k < j; k++) {
                if (ps[k].c >= ps[j].c) {
                    continue;
                }

                llint base = ps[k].a;
                for (int l = 0; l < SIZE; l++) {
                    if (dp[i - 1][k][l] == -1) {
                        continue;
                    }
                    llint u = (base + l) * kk;
                    llint v = (base + l) + kk;

                    if (ps[j].a <= u && u <= ps[j].b) {
                        dp[i][j][u - ps[j].a] = max(dp[i][j][u - ps[j].a], dp[i - 1][k][l] + u);
                    }

                    if (ps[j].a <= v && v <= ps[j].b) {
                        dp[i][j][v - ps[j].a] = max(dp[i][j][v - ps[j].a], dp[i - 1][k][l] + v);
                    }
                }
            }

            /*
            for (int k = 0; k < SIZE; k++) {
                if (dp[i][j][k] > 0) {
                    print(">>" << i << ' ' << j << ' ' << ps[j].a + k);
                }
            }
            */
        }
    }

    llint ans = -1;
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < SIZE; k++) {
            ans = max(ans, dp[n - 1][i][k]);
        }
    }
    if (ans == -1) {
        puts("NO");
    } else {
        puts("YES");
        print(ans);
    }
    return 0;
}