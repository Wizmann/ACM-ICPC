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

const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

int n, d;
char buffer[SIZE];
vector<int> g[SIZE];
int dis[SIZE];
char visit[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
    }
}

int spfa(int cur) {
    queue<int> q;
    q.push(cur);
    memset(visit, 0, sizeof(visit));
    visit[cur] = 1;
    memset(dis, INF, sizeof(dis));
    dis[cur] = 0;
    
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        visit[cur] = 0;
        
        for (auto next: g[cur]) {
            if (dis[next] > dis[cur] + 1) {
                dis[next] = dis[cur] + 1;
                if (!visit[next]) {
                    visit[next] = 1;
                    q.push(next);
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {

        ans = max(ans, dis[i]);
    }
    return ans;
}

int main() {
    int T;
    input(T);
    while (T--) {
        input(n >> d);
        init();
        for (int i = 0; i < n; i++) {
            scanf("%s", buffer);
            for (int j = 0; j < n; j++) {
                if (buffer[j] == 'Y') {
                    g[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, spfa(i));
        }
        if (ans) {
            print(1LL * ans * d);
        } else {
            print(-1);
        }
    }
    return 0;
}