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

const int SIZE = 212345;

vector<int> g[SIZE];
vector<bool> visited;

int dfs1(int pre, int cur) {
    if (visited[cur]) {
        return 0;
    }

    int cnt = 1;
    visited[cur] = true;
    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        cnt += dfs1(cur, nxt);
    }
    return cnt;
}

int main() {
    int n, l, r;
    input(n, l, r);

    int u, v;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> cs;
    visited = vector<bool>(SIZE, false);
    for (int i = 1; i <= n; i++) {
        int cnt = dfs1(-1, i);
        if (cnt) {
            cs.push_back(cnt);
        }
    }

    int res = 0;
    for (auto num : cs) {
        if (l <= num && num < l + r) {
            res ^= num / l;
        }
    }

    if (res == 0) {
        puts("Bob");
    } else {
        puts("Alice");
    }

    return 0;
}

/*

^^^TEST^^^
6 2 3
1 2
2 3
3 1
4 5
5 6
6 4
-----
Bob
$$$TEST$$$

^^^^^TEST^^^^
6 1 2
1 2
2 3
3 1
4 5
5 6
6 4
--------
Bob
$$$TEST$$$$

^^^^TEST^^^^
12 1 3
1 2
2 3
3 1
4 5
5 6
6 7
7 4
8 9
9 10
10 11
11 12
12 8
--------
Alice
$$$TEST$$$



*/
