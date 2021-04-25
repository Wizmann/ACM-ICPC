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

int n, m;
vector<int> g[SIZE];
vector<int> colors;
vector<bool> visited;


void dfs1(int cur, vector<int>& path) {
    path.push_back(cur);
    visited[cur] = true;
    for (auto nxt : g[cur]) {
        if (!visited[nxt]) {
            dfs1(nxt, path);
        }
    }
}

llint dfs2(int idx, const vector<int>& path) {
    if (idx == path.size()) {
        return 1;
    }

    int cur = path[idx];

    llint res = 0;

    for (int i = 0; i < 3; i++) {
        colors[cur] = i;
        bool flag = true;
        for (auto nxt : g[cur]) {
            if (colors[nxt] == i) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        res += dfs2(idx + 1, path);
    }

    colors[cur] = -1;
    return res;
}

int main() {
    input(n, m);

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    visited = vector<bool>(n + 1, false);
    colors = vector<int>(n + 1, -1);
    llint ans = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            continue;
        }
        vector<int> path;
        dfs1(i, path);
        llint res = dfs2(0, path);
        if (res == 0) {
            ans = 0;
            break;
        }
        ans *= res;
    }
    print(ans);

    return 0;
}

/*

^^^TEST^^^
1 0
---
3
$$$TEST$$$

^^^TEST^^^
4 3
1 2
1 3
1 4
---
24
$$$TEST$$$
 
^^^TEST^^^
2 1
1 2
---
6
$$$TEST$$$

^^^TEST^^^
3 1
1 2
---
18
$$$TEST$$$

^^^TEST^^^
3 3
1 2
2 3
3 1
-----
6
$$$TEST$$$

^^^TEST^^^
4 6
1 2
2 3
3 4
1 4
1 3
2 4
-----
0
$$$TEST$$$

^^^TEST^^^
6 8
1 2
2 3
3 4
1 4
1 3
2 4
5 2
5 3
-----
0
$$$TEST$$$

^^^TEST^^^
3 0
---
27
$$$TEST$$$

^^^TEST^^^
20 0
----
3486784401
$$$TEST$$$

^^^TEST^^^
4 6
1 2
2 3
3 4
2 4
1 3
1 4
----
0
$$$TEST$$$

^^^TEST^^^
6 6
1 2
2 3
3 4
2 4
1 3
1 4
----
0
$$$TEST$$$

^^^TEST^^^
20 19
1 2
2 3
3 4 
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
20 19
------
1572864
$$$TEST$$$

*/

