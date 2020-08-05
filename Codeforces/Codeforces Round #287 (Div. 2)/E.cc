#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111'111;
const int INF = 0x3f3f3f3f;

struct Edge {
    int src, dest, status;
};

struct Distance {
    int dis, change;
    Edge pre;

    bool operator < (const Distance& other) const {
        if (dis != other.dis) {
            return dis < other.dis;
        }
        return change > other.change;
    }
};

int n, m;
vector<Edge> g[SIZE];
map<pair<int, int>, int> mp;
vector<Distance> distances;

vector<Edge> spfa() {
    queue<int> q;
    q.push(1);
    vector<bool> inq(n + 1, false);
    inq[1] = true;

    distances.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        distances[i].dis = INF;
        distances[i].change = INF;
    }
    distances[1].dis = 0;
    distances[1].change = 0;
    distances[1].pre = {-1, -1, -1};

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        inq[cur] = false;

        for (auto e: g[cur]) {
            Distance d = {
                distances[cur].dis + 1,
                distances[cur].change + (e.status == 1),
                e
            };
            if (d < distances[e.dest]) {
                distances[e.dest] = d;
                if (!inq[e.dest]) {
                    q.push(e.dest);
                    inq[e.dest] = true;
                }
            }
        }
    }

    int cur = n;
    vector<Edge> edges;
    set<pair<int, int>> st;
    while (cur != 1) {
        if (distances[cur].pre.status == 0) {
            edges.push_back(distances[cur].pre);
        }
        int a = min(distances[cur].pre.src, distances[cur].pre.dest);
        int b = max(distances[cur].pre.src, distances[cur].pre.dest);
        st.insert({a, b});
        cur = distances[cur].pre.src;
    }
    // edges.push_back({-1, -1, -1});
    for (auto p: mp) {
        if (st.count(p.first) == 0 && p.second == 1) {
            edges.push_back({p.first.first, p.first.second, p.second});
        }
    }
    return edges;
}

int main() {
    input(n >> m);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c); 

        g[a].push_back({a, b, c});
        g[b].push_back({b, a, c});
        mp[{min(a, b), max(a, b)}] = c;
    }

    vector<Edge> edges = spfa();

    print(edges.size());
    for (const auto& edge: edges) {
        printf("%d %d %d\n", edge.src, edge.dest, edge.status ^ 1);
    }

    return 0;
}
