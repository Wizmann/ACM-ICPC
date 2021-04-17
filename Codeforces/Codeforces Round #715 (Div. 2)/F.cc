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

class DisjointSet {
public:
    DisjointSet() {}
    DisjointSet(int n_) : n(n_), father(n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);

        father[fb] = fa;
    }

    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }
private:
    int n;
    vector<int> father;
};

struct Edge {
    int a, b, w;
}; 

const int SIZE = 212345;

int n, m;
vector<int> g[SIZE];
vector<Edge> edges;
DisjointSet ds;
set<int> nodes;
llint rem;
vector<bool> visited;

void dfs(int cur) {
    queue<int> q;
    q.push(cur);

    if (nodes.count(cur)) {
        nodes.erase(nodes.find(cur));
    } else {
        return;
    }

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (visited[cur]) {
            continue;
        }
        visited[cur] = 1;

        for (int i = 1; i <= n; /* pass */) {
            auto iter = nodes.lower_bound(i);
            if (iter == nodes.end()) {
                break;
            }
            int u = *iter;
            if (!binary_search(g[cur].begin(), g[cur].end(), u)) {
                ds.make_union(cur, u);
                // print(cur, u);
                nodes.erase(iter);
                rem--;
                q.push(u);
            }
            i = u + 1;
        }
    }
}

int main() {
    input(n, m);
    rem = 1LL * n * (n - 1) / 2 - m;
    int left = 0;

    // print(rem);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({a, b, c});
        g[a].push_back(b);
        g[b].push_back(a);
        left ^= c;
    }


    for (int i = 1; i <= n; i++) {
        nodes.insert(i);
        sort(g[i].begin(), g[i].end());
    }

    ds = DisjointSet(n + 1);

    visited = vector<bool>(n + 1, false);
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    // print(rem);

    if (rem > 0) {
        left = 0;
    }

    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
        return e1.w < e2.w;
    });

    DisjointSet ds2(n + 1);

    llint ans = 0;
    for (const auto& e : edges) {
        if (ds.find_father(e.a) != ds.find_father(e.b)) {
            ans += e.w;
            ds.make_union(e.a, e.b);
            ds2.make_union(e.a, e.b);
        } else if (ds2.find_father(e.a) != ds2.find_father(e.b)) {
            left = min(left, e.w);
            ds2.make_union(e.a, e.b);
        }
    }

    print(ans + left);

    return 0;
}

/*

^^^TEST^^^
4 4
2 1 14
1 4 14
3 2 15
4 3 8
-----
15
$$$TEST$$$

^^^TEST^^^
6 6
3 6 4
2 4 1
4 5 7
3 4 10
3 5 1
5 2 15
----
0
$$$TEST$$$

^^^TEST^^^
5 6
2 3 11
5 3 7
1 4 10
2 4 14
4 3 8
2 5 6
----
6
$$$TEST$$$

*/
