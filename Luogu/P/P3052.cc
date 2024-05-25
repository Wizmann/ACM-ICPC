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

const int SIZE = 18;

int n;
llint w;
vector<llint> Ws;

int dp[1 << SIZE];
int lowbit(int x) {
    return x & (-x);
}

int dfs(int status) {
    if (status == 0) {
        return 0;
    }

    if (dp[status] == -1) {
        return INF;
    }

    if (dp[status] != INF) {
        return dp[status];
    }

    int mini = INF;

    for (int i = status; i; i = (i - 1) & status) {
        if ((i & lowbit(status)) == 0) {
            continue;
        }

        llint tot = 0;
        llint except = INFLL;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tot += Ws[j];
            } else if (status & (1 << j)) {
                except = min(except, Ws[j]);
            }
            if (tot > w) {
                break;
            }
        }

        if (tot > w || w - tot >= except) {
            continue;
        }

        mini = min(mini, dfs(status ^ i) + 1);
    }

    if (mini >= INF) {
        mini = -1;
    }
    return dp[status] = mini;
}

int main() {
    input(n, w);

    Ws.resize(n);
    for (int i = 0; i < n; i++) {
        input(Ws[i]);
    }

    memset(dp, INF, sizeof(dp));

    print(dfs((1 << n) - 1));

    return 0;
}

/*

^^^TEST^^^
1 10 
5 
-----
1
$$$TEST$$$

^^^TEST^^^
4 10 
5 
6 
3 
7 
-----
3
$$$TEST$$$

^^^TEST^^^
18 18 
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
-----
10
$$$TEST$$$

*/
