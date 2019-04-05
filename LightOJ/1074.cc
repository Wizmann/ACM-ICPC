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

const int N = 222;
const int INF = 0x3f3f3f3f;

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

    void solve() {
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
                            dfs(next);
                        }
                    }
                }
            }
        }
    }

    int query(int x) {
        if (dis[x] >= INF || cir[x] || dis[x] < 3) {
            return -1;
        }
        return dis[x];
    }

    void dfs(int cur) {
        if (cir[cur]) {
            return;
        }
        cir[cur] = true;
        for (auto p: g[cur]) {
            int next = p.dest;
            dfs(next);
        }
    }

    int n;
    vector<Edge> g[N];
    vector<int> dis;
    vector<int> cntq;
    vector<bool> visited;
    vector<bool> cir;
};

template<typename T>
T tri(const T& t) {
    return t * t * t;
}

int main() {
    int T;

    int case_ = 0;
    input(T);
    while (T--) {
        printf("Case %d:\n", ++case_);
        int n;
        input(n);
        auto S = Solution(n);
        vector<int> biz(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &biz[i]);
        }

        int m;
        input(m);

        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            a--;
            b--;
            S.addEdge(a, b, tri(biz[b] - biz[a]));
        }

        S.solve();
        int q;
        input(q);
        for (int i = 0; i < q; i++) {
            scanf("%d", &a);
            a--;
            int ans = S.query(a);
            if (ans == -1) {
                puts("?");
            } else {
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}
