#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 111111;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;

struct Point {
    int x, y;
};

int n;
vector<int> g[SIZE];
map<int, int> mpx, mpy;
vector<Point> points;
vector<llint> dis;
vector<bool> visit;
queue<int> q;

llint point_dis(int idx_a, int idx_b) {
    const Point& pa = points[idx_a];
    const Point& pb = points[idx_b];
    llint a = abs(pa.x - pb.x);
    llint b = abs(pa.y - pb.y);
    return min(a, b);
}

void spfa() {
    dis = vector<llint>(n, INF);
    visit = vector<bool>(n, false);
    
    dis[0] = 0;
    visit[0] = true;
    q.push(0);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        visit[cur] = 0;
        
        for (auto next: g[cur]) {
            if (dis[cur] + point_dis(cur, next) < dis[next]) {
                dis[next] = dis[cur] + point_dis(cur, next);
                if (!visit[next]) {
                    visit[next] = 1;
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    input(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        mpx[a] = i;
        mpy[b] = i;
        points.push_back({a, b});
    }
    
    for (int i = 0; i < n; i++) {
        int y = points[i].y;
        int x = points[i].x;
        
        auto iter_x = mpx.find(x);
        g[i].push_back(iter_x->second);
        if (iter_x != mpx.begin()) {
            auto iter_tmp = iter_x;
            --iter_tmp;
            g[i].push_back(iter_tmp->second);
        }
        if (iter_x != (--mpx.end())) {
            auto iter_tmp = iter_x;
            ++iter_tmp;
            g[i].push_back(iter_tmp->second);
        }
        
        auto iter_y = mpy.find(y);
        g[i].push_back(iter_y->second);
        if (iter_y != mpy.begin()) {
            auto iter_tmp = iter_y;
            --iter_tmp;
            g[i].push_back(iter_tmp->second);
        }
        if (iter_y != (--mpy.end())) {
            auto iter_tmp = iter_y;
            ++iter_tmp;
            g[i].push_back(iter_tmp->second);
        }
    }
    spfa();
    print(dis[n - 1]);
    return 0;
}
