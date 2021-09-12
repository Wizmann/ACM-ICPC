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

const int N = 444;

int n, m;
vector<int> g[N];
bool inpath[N][N];
int pre[N];
int dis[N];
bool inq[N];

int bfs() {
    memset(inpath, 0, sizeof(inpath));
    memset(dis, INF, sizeof(dis));
    memset(pre, -1, sizeof(pre));
    memset(inq, 0, sizeof(inq));

    queue<int> q;
    q.push(1);
    dis[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        inq[cur] = 0;

        for (auto nxt : g[cur]) {
            if (dis[nxt] > dis[cur] + 1) {
                dis[nxt] = dis[cur] + 1;
                pre[nxt] = cur;
                if (!inq[nxt]) {
                    q.push(nxt);
                    inq[nxt] = 1;
                }
            }
        }
    }

    int cur = n;
    while (cur != -1) {
        int p = pre[cur];
        inpath[p][cur] = 1;
        cur = p;
    }
    return dis[n] >= INF? -1: dis[n];
}

int bfs2(int a, int b) {
    memset(dis, INF, sizeof(dis));
    memset(inq, 0, sizeof(inq));

    queue<int> q;
    q.push(1);
    dis[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        inq[cur] = 0;

        for (auto nxt : g[cur]) {
            if (a == cur && b == nxt) {
                continue;
            }
            if (dis[nxt] > dis[cur] + 1) {
                dis[nxt] = dis[cur] + 1;
                if (!inq[nxt]) {
                    q.push(nxt);
                    inq[nxt] = 1;
                }
            }
        }
    }

    return dis[n] >= INF? -1: dis[n];
}

int main() {
    int a, b;
    scanf("%d%d", &n, &m);

    vector<pair<int, int> > edges;

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        edges.push_back({a, b});
    }

    int dis = bfs();

    for (auto& edge : edges) {
        a = edge.first;
        b = edge.second;

        if (inpath[a][b]) {
            // print("inpath", a, b);
            printf("%d\n", bfs2(a, b));
        } else {
            printf("%d\n", dis);
        }
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
1
2
1
$$$TEST$$$

^^^TEST^^^
4 4
1 2
2 3
2 4
3 4
-----
-1
2
3
2
$$$TEST$$$

^^^TEST^^^
5 10
1 2
1 4
1 5
2 1
2 3
3 1
3 2
3 5
4 2
4 3
-----
1
1
3
1
1
1
1
1
1
1
$$$TEST$$$

^^^TEST^^^
4 1
1 2
-------
-1
$$$TEST$$$

*/
