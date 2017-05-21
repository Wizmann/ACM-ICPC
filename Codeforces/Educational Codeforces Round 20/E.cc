#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int K = 1111;
const int N = 1111;

struct Node {
    char cur;
    int pre;
};

Node dp[N][K * 2];
int n, k;
string ans = "";

void dfs(int u, int v) {
    if (u == 0) {
        return;
    }
    ans += dp[u][v].cur;
    dfs(u - 1, dp[u][v].pre);
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> k);
    string s;
    input(s);
    memset(dp, -1, sizeof(dp));

    dp[0][K] = {'x', -1};

    int l = K - k;
    int r = K + k;

    for (int i = 0; i < n; i++) {
        for (int j = l + 1; j <= r - 1; j++) {
            if (dp[i][j].cur == -1) {
                continue;
            }
            if (s[i] == '?') {
                for (int delta = -1; delta <= 1; delta++) {
                    int next = j + delta;
                    if (next < l || next > r) {
                        continue;
                    }
                    char mark;
                    switch (delta) {
                        case -1: mark = 'L'; break;
                        case 0 : mark = 'D'; break;
                        case 1 : mark = 'W'; break;
                    }
                    dp[i + 1][next] = {mark, j};
                }
            } else {
                int next = j;
                switch (s[i]) {
                    case 'L': next -= 1; break;
                    case 'D': /* pass */; break;
                    case 'W': next += 1; break;
                }
                dp[i + 1][next] = {s[i], j};
            }
        }
    }
    if (dp[n][l].cur == -1 && dp[n][r].cur == -1) {
        ans = "ON";
    } else if (dp[n][l].cur != -1) {
        dfs(n, l);
    } else {
        dfs(n, r);
    }
    reverse(ans.begin(), ans.end());
    puts(ans.c_str());
    return 0;
}
