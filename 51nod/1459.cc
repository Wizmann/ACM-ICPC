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

const int SIZE = 555;
const int INF = 0x3f3f3f3f;

struct Edge {
    int dest;
    int cost;
};

vector<Edge> g[SIZE];
vector<int> rooms;

int n, m, xstart, xend;

void spfa() {
    // pair<dis, score>
    vector<pair<int, int> > dis;
    dis.resize(n);
    fill(dis.begin(), dis.end(), pair<int, int>({INF, -INF}));
    
    dis[xstart] = {0, rooms[xstart]};
    
    queue<int> q;
    q.push(xstart);
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        int nowdis = dis[now].first;
        int score = dis[now].second;
        
        for (auto edge: g[now]) {
            int dest = edge.dest;
            int cost = edge.cost;
            int sc   = rooms[dest];
            
            if (nowdis + cost < dis[dest].first ||
                    (nowdis + cost == dis[dest].first && score + sc > dis[dest].second)) {
                dis[dest] = {nowdis + cost, score + sc};
                q.push(dest);
            }
        }
    }
    
    print(dis[xend].first << ' ' << dis[xend].second);
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b, c;
    input(n >> m >> xstart >> xend);
    rooms.resize(n);
    
    for (int i = 0; i < n; i++) {
        input(rooms[i]);
    }
    
    for (int i = 0; i < m; i++) {
        input(a >> b >> c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    spfa();
    return 0;
}
