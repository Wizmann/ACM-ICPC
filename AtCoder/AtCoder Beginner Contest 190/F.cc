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
#include <queue>
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

struct Edge {
    int dest;
    llint cost;
};

const int N = 123456;
const int M = 123456;
const int K = 17;

int n, m, k;
vector<int> g[N];
vector<int> trace;
vector<Edge> g2[K + 1];
vector<int> dis;

void spfa(int st) {
    dis = vector<int>(n + 1, INF);
    queue<int> q;
    q.push(st);
    dis[st] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : g[cur]) {
            if (dis[nxt] == INF) {
                dis[nxt] = dis[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

vector<llint> dis2[1 << (K + 1)];

llint spfa2() {
    for (int i = 0; i < (1 << (k + 1)); i++) {
        dis2[i] = vector<llint>(k + 1, INFLL);
    }
    dis2[1][0] = 0;
    queue<pair<int, int> > q;
    set<pair<int, int> > visited;
    // pos, status
    visited.insert({0, 1});
    q.push({0, 1});

    while (!q.empty()) {
        const auto& cur = q.front();
        int pos = cur.first;
        int status = cur.second;
        visited.erase(visited.find(cur));
        q.pop();

        for (auto pp : g2[pos]) {
            llint nxt = pp.dest;
            llint cost = pp.cost;

            int ns = status | (1 << nxt);
            llint ds = dis2[status][pos] + cost;

            if (dis2[ns][nxt] > ds) {
                dis2[ns][nxt] = ds;
                if (visited.count({nxt, ns}) == 0) {
                    visited.insert({nxt, ns});
                    q.push({nxt, ns});
                }
            }
        }
    }
    llint res = INFLL;
    for (int i = 1; i <= k; i++) {
        res = min(res, dis2[(1 << (k + 1)) - 1][i]);
    }
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

    input(k);
    trace.resize(k + 1);

    for (int i = 1; i <= k; i++) {
        scanf("%d", &a);
        trace[i] = a;
    }

    for (int i = 1; i <= k; i++) {
        a = trace[i];
        spfa(a);
        for (int j = 1; j <= k; j++) {
            if (i == j) {
                continue;
            }
            llint dd = dis[trace[j]];
            if (dd >= INF) {
                dd = INFLL;
            }
            g2[i].push_back({j, dd});
        }
    }

    for (int i = 1; i <= k; i++) {
        g2[0].push_back({i, 0});
    }

    llint res = spfa2();
    if (res >= INFLL) {
        puts("-1");
    } else {
        print(res + 1);
    }

    return 0;
}

/*
^^^TEST^^^
4 3
1 4
2 4
3 4
3
1 2 3
-----
5
$$$TEST$$$$


^^^TEST^^^
4 3
1 4
2 4
1 2
3
1 2 3
----
-1
$$$TEST$$$

^^^TEST^^^
10 10
3 9
3 8
8 10
2 10
5 8
6 8
5 7
6 7
1 6
2 4
4
1 2 7 9
-----
11
$$$TEST$$$


*/
