#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;


const int SIZE = 20002 * 4;
const llint INF = 1LL * SIZE * 1000111 * 2;

int n, m;
int m1, m2;

vector<pair<int, int> > g1[SIZE];

llint dis[SIZE];
vector<bool> visit;
int mini[SIZE];

llint spfa(const int src, const int dest) {
    for (int i = 0; i < SIZE; i++) {
        dis[i] = INF;
    }
    dis[src] = 0;
    visit = vector<bool>(SIZE, false);

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visit[cur] = 0;

        for (auto p: g1[cur]) {
            int next = p.first;
            int d = p.second;

            if (dis[next] > dis[cur] + d) {
                dis[next] = dis[cur] + d;
                if (!visit[next]) {
                    visit[next] = 1;
                    q.push(next);
                }
            }
        }
    }
    /*
    for (int i = 1; i <= n + m; i++) {
        printf("%lld ", dis[i]);
    }
    puts("");
    */
    
    
    llint ans = dis[dest];
    if (ans >= INF) {
        return -1;
    }
    return ans;
}


int main() {    
    int a, b, c;
    input(n >> m);

    for (int i = 1; i <= m; i++) {
        input(a);
        for (int j = 0; j < a; j++) {
            scanf("%d", &b);
            g1[b].push_back({n + i * 2 - 1, 0});
            g1[n + i * 2].push_back({b, 0});
        }
    }

    input(m1);
    for (int i = 0; i < m1; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g1[a].push_back({b, c});
        g1[b].push_back({a, c});
    }

    input(m2);
    for (int i = 0; i < m2; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g1[n + a * 2 - 1].push_back({n + b * 2, c});
        g1[n + b * 2 - 1].push_back({n + a * 2, c});
    }

    input(a >> b);
    print(spfa(a, b));

    return 0;
}
