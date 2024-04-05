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

const int SIZE = 1234;

vector<int> g[SIZE];
vector<int> cnt;
vector<int> weight;
vector<int> dis;
int n;
int m;
int ans;

void dfs1(int pre, int cur) {
    int w = cnt[cur];
    int d = 0;
    
    for (auto nxt: g[cur]) {
        if (pre == nxt) {
            continue;
        }
        dfs1(cur, nxt);
        w += weight[nxt];
        d += dis[nxt] + weight[nxt];
    }

    // print(cur, d, w);
    dis[cur] = d;
    weight[cur] = w;
}

void dfs2(int pre, int cur, int d) {
    // print(cur, d);
    ans = min(ans, d);

    for (auto nxt: g[cur]) {
        if (pre == nxt) {
            continue;
        }

        int nd = (d - weight[nxt]) + (m - weight[nxt]);
        dfs2(cur, nxt, nd);
    }
}

int main() {
    input(n);

    int a, b, c;
    cnt.resize(n + 1);
    weight.resize(n + 1);
    dis.resize(n + 1);
    m = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        m += a;
        cnt[i] = a;
        if (b) {
            g[i].push_back(b);
            g[b].push_back(i);
        }

        if (c) {
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }

    ans = INF;

    dfs1(-1, 1);
    dfs2(-1, 1, dis[1]);

    print(ans);

    return 0;
}

/*

^^^TEST^^^
5
13 2 3
4 0 0
12 4 5
20 0 0
40 0 0
-----
81
$$$TEST$$$

*/
