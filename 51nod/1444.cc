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

const int SIZE = 3333;
const int INF = 0x3f3f3f3f;

int n, m;
vector<int> g[SIZE];
vector<int> dis[SIZE];
int s1, t1, l1;
int s2, t2, l2;

void bfs() {
    for (int i = 0; i < n; i++) {
        vector<bool> visit(n);
        queue<int> q;
        vector<int>& dis_ = dis[i];
        dis_ = vector<int>(n, INF);
        
        q.push(i);
        visit[i] = 0;
        dis_[i] = 0;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visit[cur] = 0;
            
            for (auto next: g[cur]) {
                if (dis_[next] > dis_[cur] + 1) {
                    dis_[next] = dis_[cur] + 1;
                    if (!visit[next]) {
                        visit[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    input(n >> m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    input(s1 >> t1 >> l1);
    input(s2 >> t2 >> l2);
    s1--;
    t1--;
    s2--;
    t2--;
    
    bfs();
    
    int d1 = dis[s1][t1];
    int d2 = dis[s2][t2];
    
    if (d1 > l1 && d2 > l2) {
        puts("-1");
        return 0;
    }
    
    int ans = d1 + d2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x1[] = {
                dis[s1][i] + dis[i][j] + dis[j][t1],
                dis[s1][j] + dis[i][j] + dis[i][t1]
            };
            int x2[] = {
                dis[s2][i] + dis[i][j] + dis[j][t2],
                dis[s2][j] + dis[i][j] + dis[i][t2]
            };
            
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    if (x1[a] <= l1 && x2[b] <= l2) {
                        ans = min(ans, x1[a] + x2[b] - dis[i][j]);
                    }
                }
            }            
        }
    }
    print(m - ans);
    return 0;
}
