#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define FOR(i, n) for (int i = 0; i < n; i++)
#define RFOR(i, n) for (int i = n - 1; i >= 0; i--)

typedef long long llint;

const int MOD = 1000000000 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1111;
const int P = 57;

int n;
vector<string> board;
vector<vector<int> > dp1, dp2;

int char2int(char c) {
    if ('a' <= c && c <= 'z') {
        return c - 'a' + 1;
    }
    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 1 + 26;
    }
    assert (false);
    return -1;
}

int fastpow(int a, int b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int get_hash_x(int y, int x, int m) {
    if (m == 0) {
        return 0;
    }
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return -INF;
    }
    int pre = x - m;
    if (pre == -1) {
        return dp1[y][x];
    }
    if (pre < 0) {
        return -INF;
    }

    pre = dp1[y][pre];

    llint res = (1LL * dp1[y][x] - 1LL * pre * fastpow(P, m) % MOD) % MOD;
    return (res % MOD + MOD) % MOD;
}

int get_hash_y(int y, int x, int m) {
    if (m == 0) {
        return 0;
    }
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return -INF;
    }
    int nxt = y + m;
    if (nxt == n) {
        return dp2[y][x];
    }
    if (nxt > n) {
        return -INF;
    }

    nxt = dp2[nxt][x];

    llint res = (1LL * dp2[y][x] - 1LL * nxt * fastpow(P, m) % MOD) % MOD;
    return (res % MOD + MOD) % MOD;
}

bool solve(int m) {
    int y = 0;
    int x = 0;
    int delta_y = 0;
    int delta_x = 1;
    while (y != n + 1) {
        int ny = y + delta_y;
        int nx = x + delta_x;

        if (nx == n) {
            ny = 1;
            nx = n - 1;
            delta_y = 1;
            delta_x = 0;
        }

        int cnt = 0;
        int l = m;

        while (y < n && x >= 0) {
            int ha = get_hash_x(y, x - 1, l - 1);
            int hb = get_hash_y(y + 1, x, l - 1);

            if (ha >= 0 && hb >= 0 && ha == hb) {
                // print(y << ' ' << x << ' ' << m);
                cnt++;
                l--;
            } else {
                // print(y << ' ' << x << ' ' << m << " NE");
                cnt = 0;
                l = m;
            }

            if (cnt >= m) {
                return true;
            }

            y += 1;
            x -= 1;
        }
        
        y = ny;
        x = nx;
    }

    return false;
}


int main() {
    char buffer[N];

    while (input(n) && n) {
        board.clear();

        for (int i = 0; i < n; i++) {
            scanf("%s", buffer);
            board.push_back(buffer);
        }

        dp1.resize(n);
        dp2.resize(n);
        FOR (i, n) {
            dp1[i] = vector<int>(n, 0);
            dp2[i] = vector<int>(n, 0);
        }

        FOR (i, n) {
            llint h = 0;
            FOR (j, n) {
                h = (h * P) + char2int(board[i][j]);
                h %= MOD;
                dp1[i][j] = h;
            }
        }

        FOR (j, n) {
            llint h = 0;
            RFOR (i, n) {
                h = (h * P) + char2int(board[i][j]);
                h %= MOD;
                dp2[i][j] = h;
            }
        }

        // print(get_hash_x(0, 1, 2));
        // print(get_hash_y(1, 2, 2));

        int l = 0;
        int r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (solve(m)) {
                // print(m << ' ' << "TRUE");
                l = m + 1;
            } else {
                // print(m << ' ' << "FALSE");
                r = m - 1;
            }
        }
        printf("%d\n", r);
    }

    return 0;
}
