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

const int N = 123456;

vector<int> g[N];
vector<bool> visited;

void dfs(int pre, int cur, int color, int& cnt0, int& cnt1) {
    if (color == 0) {
        cnt0++;
    } else {
        cnt1++;
    }
    visited[cur] = true;

    for (auto nxt : g[cur]) {
        if (nxt != pre) {
            dfs(cur, nxt, color ^ 1, cnt0, cnt1);
        }
    }
}

int main() {
    int n;
    input(n);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    visited = vector<bool>(n + 1, false);

    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(-1, 1, 0, cnt0, cnt1);
        }
    }

    print(1LL * cnt0 * cnt1 - (n - 1));

    return 0;
}

/*

^^^TEST^^^
3
1 2
1 3
-----
0
$$$TEST$$$

^^^TEST^^^
5
1 2
2 3
3 4
4 5
-----
2
$$$TEST$$$

*/
