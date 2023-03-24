#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Edge {
    int dest;
    int cost;
};

const int SIZE = 3333;
const int INF = 0x3f3f3f3f;

int n, m;
vector<Edge> g[SIZE];
vector<int> dis;
vector<bool> visit;

int main() {
    int a, b, c;
    input(n >> m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int st;
    input(st);
    st--;
    
    dis = vector<int>(n, INF);
    visit = vector<bool>(n, false);
    dis[st] = 0;    
    
    for (int i = 0; i < n; i++) {
        int mini = INF;
        int ptr = -1;
        
        for (int j = 0; j < n; j++) {
            if (dis[j] < mini && !visit[j]) {
                mini = dis[j];
                ptr = j;
            }
        }
            
        visit[ptr] = true;
        
        for (auto p: g[ptr]) {
            int next = p.dest;
            int cost = p.cost;
            if (!visit[next]) {
                dis[next] = min(dis[next], cost);
            }
        }
    }
    
    print(accumulate(dis.begin(), dis.end(), 0));

    return 0;
}
