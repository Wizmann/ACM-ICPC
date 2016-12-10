// Result: wizmann	2686	Accepted	1052K	1360MS	G++	2636B	2016-12-03 00:31:42
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int TICKET = 10;
const int SIZE = 33;
const int INF = 0x3f3f3f3f;
const int FACTOR = 100000;

struct Edge {
    Edge(int a_, int b_, int c_): a(a_), b(b_), c(c_) {}
    int a, b, c;
};

int n, m, p;
vector<int> tickets;
vector<Edge> g[SIZE];
int dis[1 << TICKET][SIZE];
set<pair<int, int> > visit;

void init() {
    tickets.clear();
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
    }
    visit.clear();
}

bool is_visit(int cur, int status) {
    pair<int, int> p(cur, status);
    return !(visit.find(p) == visit.end());
}

int spfa(int src, int dest) {
    memset(dis, INF, sizeof(dis));
    queue<pair<int, int> > q;
    q.push(pair<int, int>(src, 0));

    dis[0][src] = 0;
    visit.insert(pair<int, int>(src, 0));

    while (!q.empty()) {
        pair<int, int> cur_p = q.front();
        q.pop();
        visit.erase(visit.find(cur_p));

        int cur = cur_p.first;
        int status = cur_p.second;

        for (int idx = 0; idx < g[cur].size(); idx++) {
            Edge edge = g[cur][idx];
            int next = edge.b;
            int d = edge.c;

            for (int i = 0; i < n; i++) {
                if (status & (1 << i)) {
                    continue;
                }

                int t = 1.0 * FACTOR * d / tickets[i];
                int s = status | (1 << i);

                if (dis[s][next] > dis[status][cur] + t) {
                    dis[s][next] = dis[status][cur] + t;
                    if (!is_visit(next, s)) {
                        visit.insert(pair<int, int>(next, s));
                        q.push(pair<int, int>(next, s));
                    }
                }
            }
        }
    }

    int mini = INF;
    for (int i = 0; i < (1 << n); i++) {
        mini = min(mini, dis[i][dest]);
    }
    return mini;
}

int main() {
    freopen("input.txt", "r", stdin);

    int src, dest;
    while (input(n >> m >> p >> src >> dest) && n + m + p + src + dest) {
        init();
        tickets.resize(n);
        for (int i = 0; i < n; i++) {
            input(tickets[i]);
        }

        int x, y, z;
        for (int i = 0; i < p; i++) {
            input(x >> y >> z);
            g[x].push_back(Edge(x, y, z));
            g[y].push_back(Edge(y, x, z));
        }

        int ans = spfa(src, dest);
        if (ans == INF) {
            puts("Impossible");
        } else {
            printf("%.3f\n", 1.0 * ans / FACTOR);
        }
    }
    return 0;
}
