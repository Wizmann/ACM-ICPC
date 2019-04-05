// Source: luogu P3385
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 2222;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;

struct Edge {
    int dest, cost;
};

struct Solution {
    Solution(int n_): n(n_), dis(n, INF), cntq(n, 0), visited(n, false), cir(n, false) {
        // pass
    }

    void addEdge(int st, int dest, int cost) {
        g[st].push_back({dest, cost});
    }

    bool solve() {
        queue<int> q;
        q.push(0);

        visited[0] = true;
        cntq[0]++;
        dis[0] = 0;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = false;

            if (cir[cur]) {
                continue;
            }

            for (auto p: g[cur]) {
                int next = p.dest;
                int cost = p.cost;
                if (dis[next] > dis[cur] + cost) {
                    dis[next] = dis[cur] + cost;
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                        cntq[next]++;

                        if (cntq[next] > n) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    int n;
    vector<Edge> g[N];
    vector<llint> dis;
    vector<int> cntq;
    vector<bool> visited;
    vector<bool> cir;
};

int main() {
    int T;

    input(T);
    while (T--) {
        int n, m;
        input(n >> m);
        auto S = Solution(n);

        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            a--;
            b--;
            if (c < 0) {
                S.addEdge(a, b, c);
            } else {
                S.addEdge(a, b, c);
                S.addEdge(b, a, c);
            }
        }

        if (!S.solve()) {
            puts("YE5");
        } else {
            puts("N0");
        }
    }

    return 0;
}
