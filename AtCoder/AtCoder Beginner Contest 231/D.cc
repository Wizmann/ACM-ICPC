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

const int SIZE = 123456;

int n, m;
vector<int> g[SIZE];
vector<bool> visited;

bool dfs(int pre, int cur) {
    if (g[cur].size() > 2) {
        return false;
    }

    visited[cur] = true;

    for (auto nxt : g[cur]) {
        if (nxt == pre) {
            continue;
        }
        if (visited[nxt]) {
            return false;
        }
        if (!dfs(cur, nxt)) {
            return false;
        }
    }
    return true;
}

int main() {
    input(n, m);

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    visited = vector<bool>(n, false);

    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        flag = dfs(-1, i);
        if (!flag) {
            break;
        }
    }
    if (flag) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}

/*

^^^TEST^^^
4 2
1 3
2 3
-----
Yes
$$$TEST$$$

^^^TEST^^^
4 3
1 4
2 4
3 4
-----
No
$$$TEST$$$

*/
