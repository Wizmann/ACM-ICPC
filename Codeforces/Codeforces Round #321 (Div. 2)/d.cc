#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 18;

int n, m, r;
int score[SIZE];
int rules[SIZE][SIZE];
llint dp[SIZE][1 << SIZE]; // [the last dish][the dishes Kefa got in binary]

inline int lowbit(int x) {
    return x & (-x);
}

int count_digit(int u) {
    int res = 0;
    while (u) {
        res++;
        u -= lowbit(u);
    }
    return res;
}

llint solve() {
    llint ans = 0;

    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = score[i];
    }

    for (int i = 0; i < (1 << n); i++) {
        if (count_digit(i) > m) {
            continue;
        }

        for (int j = 0; j < n; j++) {
            int is_exist1 = i & (1 << j);
            if (is_exist1 == 0) {
                continue;
            }

            for (int k = 0; k < n; k++) {
                int is_exist2 = i & (1 << k);
                if (is_exist2 == 0) {
                    continue;
                }
                if (k == j) {
                    continue;
                }
                int u = i ^ (1 << j);
                dp[j][i] = max(dp[j][i], dp[k][u] + rules[k][j] + score[j]);
            }

            if (count_digit(i) == m) {
                // print(j << ' ' << i << ' ' << dp[j][i]);
                ans = max(ans, dp[j][i]);
            }
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b, c;
    input(n >> m >> r);
    for (int i = 0; i < n; i++) {
        input(score[i]);
    }
    memset(rules, 0, sizeof(rules));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < r; i++) {
        input(a >> b >> c);
        a--;
        b--;
        rules[a][b] = max(rules[a][b], c);
    }
    llint ans = solve();
    print(ans);
    return 0;
}
