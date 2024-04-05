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
vector<int> colors;

bool dfs(int pre, int cur, int color, int& cnt0, int& cnt1) {
    if (color == 0) {
        cnt0++;
    } else {
        cnt1++;
    }
    colors[cur] = color;

    bool flag = true;
    for (auto nxt : g[cur]) {
        if (colors[cur] == colors[nxt]) {
            return false;
        }
        if (colors[nxt] == -1) {
            flag = dfs(cur, nxt, color ^ 1, cnt0, cnt1);
        }
        if (!flag) {
            break;
        }
    }
    return flag;
}

int main() {
    int n;
    int m;
    input(n, m);

    colors = vector<int>(n + 1, -1);

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int res = 0;
    bool flag = true;

    for (int i = 1; i <= n; i++) {
        if (colors[i] != -1) {
            continue;
        }
        int t0 = 0;
        int t1 = 0;
        flag = dfs(-1, i, 0, t0, t1);
        if (!flag) {
            break;
        }
        res += min(t0, t1);
    }
    if (!flag) {
        puts("Impossible");
    } else {
        print(res);
    }

    return 0;
}

/*

^^^TEST^^^
3 3
1 2
1 3
2 3
-----
Impossible
$$$TEST$$$

^^^TEST^^^
3 2
1 2
2 3
-----
1
$$$TEST$$$

*/
