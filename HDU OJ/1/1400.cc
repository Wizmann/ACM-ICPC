#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int N = 11;

llint dp[2][1 << N];
vector<int> line[N + 1];

void do_init(int n) {
    int status_all = 1;
    {
        for (int i = 0; i < n; i++) {
            status_all *= 3;
        }
    }
    
    for (int i = 0; i < status_all; i++) {
        vector<int> mp(n, 0);
        int status = i;
        int plug_status = 0;
        bool flag = true;
        for (int j = 0; j < n; j++) {
            int cur = status % 3;
            status /= 3;
            if (cur == 0) {
                // pass
            } else if (cur == 1) {
                if (mp[j] != 0 || j + 1 >= n) {
                    flag = false;
                    break;
                }
                mp[j] = mp[j + 1] = 1;
            } else if (cur == 2) {
                if (mp[j] != 0) {
                    flag = false;
                    break;
                }
                mp[j] = 1;
                plug_status |= 1 << j;
            } else {
                assert(false);
            }
        }
        if (flag) {
            line[n].push_back(i);
        }
    }
}

void init() {
    for (int i = 1; i <= N; i++) {
        do_init(i);
    }
}

llint solve(int n, int m) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int p = 0;
    for (int i = 0; i < n; i++) {
        int q = p ^ 1;
        memset(dp[q], 0, sizeof(dp[q]));

        for (auto status : line[m]) {
            int cur_status = 0;
            int nxt_status = 0;
            for (int k = 0; k < m; k++) {
                int cur = status % 3;
                status /= 3;
                if (cur == 0) {
                    // pass
                } else if (cur == 1) {
                    cur_status |= 1 << k;
                    cur_status |= 1 << (k + 1);
                } else if (cur == 2) {
                    cur_status |= 1 << k;
                    nxt_status |= 1 << k;
                } else {
                    assert (false);
                }
            }
            cur_status ^= ((1 << m) - 1);
            dp[q][nxt_status] += dp[p][cur_status];
        }
        p = q;
    }
    return dp[p][0];
}

int main() {
    int n, m;
    init();
    while (input(n, m) && n + m) {
        printf("%lld\n", solve(n, m));
    }

    return 0;
}

/*

^^^TEST^^^
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
-----
1
0
1
2
3
5
144
51205
$$$TEST$$$

*/
