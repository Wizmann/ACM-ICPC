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

const int SIZE = 22;

int n;
int board[SIZE];
int current[SIZE];

const int my[] = {-1, 0, 0};
const int mx[] = {0, 1, -1};

bool dfs(int cur) {
    if (cur == n) {
        return true;
    }

    int line = 0;
    for (int i = 0; i < n; i++) {
        int tot = 0;
        for (int j = 0; j < 3; j++) {
            int ny = (cur - 1) + my[j];
            int nx = i + mx[j];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
                continue;
            }

            int u = (current[ny] & (1 << nx)) ? 1 : 0;
            tot ^= u;
        }
        line ^= tot << i;
    }
    // print(line);

    int u = line & board[cur];
    if ((u & board[cur]) != board[cur]) {
        return false;
    }
    current[cur] = line;

    return dfs(cur + 1);
}

int check() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int u = (board[i] & (1 << j)) ? 1 : 0;
            int v = (current[i] & (1 << j)) ? 1 : 0;
            if (u && !v) {
                assert(false);
            }
            if (u != v) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    int T;
    input(T);

    int case_ = 0;

    while (T--) {
        input(n);

        memset(board, 0, sizeof(board));
        int x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &x);
                board[i] |= x << j;
            }
        }

        int res = INF;
        for (int i = 0; i < (1 << n); i++) {
            int u = board[0] & i;
            if ((u & board[0]) != board[0]) {
                continue;
            }

            current[0] = i;
            if (dfs(1)) {
                res = min(res, check());
            }
        }

        if (res >= INF) {
            res = -1;
        }

        printf("Case %d: %d\n", ++case_, res);
    }
    return 0;
}

/*

^^^TEST^^^
3
3
0 0 0
0 0 0
0 0 0
3
0 0 0
1 0 0
0 0 0
3
1 1 1
1 1 1
0 0 0
-----
Case 1: 0 
Case 2: 3 
Case 3: -1
$$$TEST$$$

*/
