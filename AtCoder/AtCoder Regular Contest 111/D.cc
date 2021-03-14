#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int SIZE = 111;
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

vector<int> g[SIZE];
int dp[SIZE][SIZE];

vector<int> C;
vector<bool> visited;

void dfs1(int cur, int value) {
    if (visited[cur]) {
        return;
    }
    visited[cur] = true;
    for (const auto& nxt : g[cur]) {
        if (C[nxt] != value) {
            continue;
        }
        if (dp[nxt][cur] == 1) {
            continue;
        }
        dp[cur][nxt] = 1;
        dfs1(nxt, value);
    }
}


int main() {
    int n, m;
    input(n, m);

    vector<pair<int, int> > edges;

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);

        edges.push_back({a, b});
    }
    memset(dp, 0, sizeof(dp));
    C.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &C[i]);
    }

    vector<pair<int, int> > ps;
    for (int i = 1; i <= n; i++) {
        ps.push_back({C[i], i});
    }
    sort(ps.begin(), ps.end(), greater<pair<int, int>>());

    for (const auto& p : ps) {
        int cur = p.second;

        for (auto nxt : g[cur]) {
            if (C[cur] > C[nxt]) {
                if (!dp[cur][nxt] && !dp[nxt][cur]) {
                    dp[cur][nxt] = 1;
                }
            }
        }
    }
    
    visited = vector<bool>(n + 1, false);


    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            continue;
        }
        dfs1(i, C[i]);
    }

    for (const auto& e : edges) {
        a = e.first;
        b = e.second;
        if (dp[a][b]) {
            puts("->");
        } else {
            // assert(dp[b][a]);
            puts("<-");
        }
    }
    return 0;
}

/*

^^^TEST^^^
3 3
1 2
2 3
3 1
3 3 3
---
->
->
->
$$$TEST$$$

^^^TEST^^^
2 1
1 2
1 2
---
<-
$$$TEST$$$

^^^TEST^^^
3 2
1 2
2 3
1 2 3
-----
<-
<-
$$$TEST$$$

^^^TEST^^^
6 3
1 2
4 3
5 6
1 2 1 2 2 1
----
<-
->
->
$$$TEST$$$

^^^TEST^^^
5 5
1 2
2 3
1 3
3 4
4 5 
5 5 5 2 1
----
->
->
<-
->
->
$$$TEST$$$

^^^TEST^^^
7 7
1 2
1 3
2 4
2 5
3 6
3 7
6 7
7 2 3 1 1 3 3
----
->
->
->
->
->
<-
->
$$$TEST$$$

^^^TEST^^^
4 4
1 2
2 3
3 4
4 1
4 4 4 4
----
->
->
->
->
$$$TEST$$$

^^^TEST^^^
4 5
1 2
2 3
1 3
3 4
4 1
4 4 4 4
----
->
->
<-
->
->
$$$TEST$$$

*/
