// Result: wizmann	3255	Accepted	2528K	219MS	C++	2124B	2015-04-12 16:10:55
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5555;
const int INF = 0x3f3f3f3f;

struct Node {
    int dest;
    int cost;

    Node() {}
    Node(int idest, int icost): dest(idest), cost(icost) {}
};

vector<Node> g[SIZE];
int n, m;
pair<int, int> dis[SIZE];
char visit[SIZE];

bool do_update(int now, int dest, int cost) {
    int d1 = dis[now].first + cost;
    int d2 = dis[now].second + cost;

    bool flag = false;
    
    if (d1 < dis[dest].first) {
        dis[dest].second = dis[dest].first;
        dis[dest].first = d1;
        flag |= true;
    } else if (d1 < dis[dest].second && d1 > dis[dest].first) {
        dis[dest].second = d1;
        flag |= true;
    }
    if (d2 < dis[dest].second) {
        dis[dest].second = d2;
        flag |= true;
    }
    return flag;    
}

int spfa() {
    queue<int> q;
    memset(visit, 0, sizeof(visit));
    memset(dis, INF, sizeof(dis));

    dis[1] = pair<int, int>(0, INF);
    q.push(1);
    visit[1] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        visit[now] = 0;

        for (vector<Node>::iterator iter = g[now].begin();
                iter != g[now].end();
                ++iter) {
            int dest = iter->dest;
            int cost = iter->cost;

            if (do_update(now, dest, cost)) {
                if (!visit[dest]) {
                    q.push(dest);
                    visit[dest] = 1;
                }
            }
        }
    }
    return dis[n].second;
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b, c;
    while (input(n >> m)) {
        for (int i = 0; i < SIZE; i++) {
            g[i].clear();
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            g[a].push_back(Node(b, c));
            g[b].push_back(Node(a, c));
        }
        print(spfa());
    }
    return 0;
}
