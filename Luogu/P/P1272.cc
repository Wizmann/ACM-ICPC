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

const int SIZE = 155;

int n, p;
vector<int> g[SIZE];
bool sub = false;

int dfs(int pre, int cur, vector<int>& dp_) {
    int cnt = 1;

    vector<int> dp[2];
    dp[0] = vector<int>(SIZE, INF);
    dp[1] = vector<int>(SIZE, INF);
    dp[0][0] = dp[1][0] = 0;

    int ptr = 0;

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        vector<int> dpnxt(SIZE, INF);
        dpnxt[0] = 0;

        int subcnt = dfs(cur, nxt, dpnxt);
        if (subcnt == p) {
            sub = true;
        }
        cnt += subcnt;
        dpnxt[subcnt] = 1;

        int qtr = ptr ^ 1;
        dp[qtr] = dp[ptr];
        for (int i = 0; i <= n; i++) {
            if (dp[ptr][i] >= INF) {
                continue;
            }
            for (int j = 0; i + j <= n; j++) {
                if (dpnxt[j] >= INF) {
                    continue;
                }
                dp[qtr][i + j] = min(dp[qtr][i + j], dp[ptr][i] + dpnxt[j]);
            }
        }
        ptr = qtr;
    }

    dp_ = dp[ptr];
    /*
    print(cur);
    for (int i = 0; i <= n; i++) {
        printf("%d ", dp_[i]);
    }
    puts("\n---");
    */
    return cnt;
}

int main() {
    input(n, p);

    if (n == p) {
        print(0);
        return 0;
    }

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        input(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int mini = INF;
    for (int i = 1; i <= n; i++) {
        vector<int> dp(SIZE, INF);
        dfs(-1, i, dp);

        if (sub) {
            mini = min(mini, 1);
        } else {
            mini = min(mini, dp[n - p]);
        }
        // print(i, dp[n - p]);
    }
    print(mini);

    return 0;
}

/*

^^^TEST^^^
1 1
-----
0
$$$TEST$$$

^^^TEST^^^
2 1
1 2
-----
1
$$$TEST$$$

^^^TEST^^^
3 1
1 2
2 3
-----
1
$$$TEST$$$

^^^TEST^^^
5 1
1 2
1 3
3 4
3 5
-----
1
$$$TEST$$$

^^^TEST^^^
5 2
1 2
2 3
3 4
4 5
-----
1
$$$TEST$$$

^^^TEST^^^
11 6
1 2
1 3
1 4
1 5
2 6
2 7
2 8
4 9
4 10
4 11
-----
2
$$$TEST$$$


^^^TEST^^^
13 3
1 12
1 5 
1 2 
1 3 
1 4
2 7
2 8
2 13
2 6
4 9
4 10
4 11
-----
2
$$$TEST$$$


*/
