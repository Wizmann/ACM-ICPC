#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
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

struct Edge {
    int a, b, t, k;
};

int n, m, x, y;
vector<Edge> g[N];

llint dijkstra_heap() {
    vector<llint> dis(n + 1, INFLL);
    dis[x] = 0;

    priority_queue<pair<llint, int>,
                   vector<pair<llint, int> >,
                   greater<pair<llint, int> > > pq;
    pq.push({0, x});

    while (!pq.empty()) {
        auto p = pq.top();
        llint tt = p.first;
        int cur = p.second;
        pq.pop();

        if (tt > dis[cur]) {
            continue;
        }

        for (const auto& e : g[cur]) {
            assert(e.a == cur);
            llint nt = ((dis[cur] + e.k - 1) / e.k) * e.k + e.t;
            if (dis[e.b] > nt) {
                dis[e.b] = nt;
                pq.push({dis[e.b], e.b});
            }
        }
    }

    if (dis[y] >= INFLL) {
        return -1;
    } else {
        return dis[y];
    }
}

int main() {
    input(n, m, x, y);

    int a, b, t, k;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &a, &b, &t, &k);

        g[a].push_back({a, b, t, k});
        g[b].push_back({b, a, t, k});
    }

    print(dijkstra_heap());

    return 0;
}

/*

^^^TEST^^^
3 2 1 3
1 2 2 3
2 3 3 4
-----
7
$$$TEST$$$

^^^TEST^^^
3 2 3 1
1 2 2 3
2 3 3 4
-----
5
$$$TEST$$$

^^^TEST^^^
3 0 3 1
-----
-1
$$$TEST$$$

^^^TEST^^^
9 14 6 7
3 1 4 1
5 9 2 6
5 3 5 8
9 7 9 3
2 3 8 4
6 2 6 4
3 8 3 2
7 9 5 2
8 4 1 9
7 1 6 9
3 9 9 3
7 5 1 5
8 2 9 7
4 9 4 4
-----
26
$$$TEST$$$

*/
