// Result: wizmann	1734	Accepted	360K	32MS	C++	2311B	2015-04-14 01:49:43
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x 

const int SIZE = 111;
const int INF = 0x3f3f3f3f;

int n, m;

int g[SIZE][SIZE];
int pre[SIZE][SIZE];
int dis[SIZE][SIZE];
vector<int> ans;

int find_min_circle() {
    int mini = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pre[i][j] = j;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j != k
                        && dis[j][k] != INF 
                        && g[i][k] != INF
                        && g[j][i] != INF
                        && dis[j][k] + g[j][i] + g[i][k] < mini) {
                    mini = dis[j][k] + g[j][i] + g[i][k];
                    ans.clear();
                    int p = j;
                    while (p != k) {
                        ans.push_back(p);
                        p = pre[p][k];
                    }
                    ans.push_back(k);
                    ans.push_back(i);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dis[j][i] != INF 
                        && dis[i][k] != INF 
                        && dis[j][k] > dis[j][i] + dis[i][k]) {
                    dis[j][k] = dis[j][i] + dis[i][k];
                    pre[j][k] = pre[j][i];
                }
            }
        }
    }
    return mini;
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b, c;
    input(n >> m);
    memset(g, INF, sizeof(g));
    memset(dis, INF, sizeof(dis));
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        g[a][b] = g[b][a] = c;
        dis[a][b] = dis[b][a] = c;
    }
    int v = find_min_circle();
    if (v == INF) {
        puts("No solution.\n");
    } else {
        int u = ans.size();
        for (int i = 0; i < u; i++) {
            if (i) {
                printf(" ");
            }
            printf("%d", ans[i] + 1);
        }
        puts("");
    }
    return 0;
}
        
