// Result: Dec 21, 2013 2:02:29 PM  Wizmann  C - Inna and Dima   GNU C++    Accepted    78 ms   18696 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1024;
const int INF = 0x3f3f3f3f;

int my[] = {1, -1, 0, 0};
int mx[] = {0, 0, 1, -1};

int n, m;
char g[SIZE][SIZE];
int dp[SIZE][SIZE];
char visit[SIZE][SIZE];

bool avail(int y, int x)
{
    if (y >= 0 && y < n && 
        x >= 0 && x < m) {
        return true;
    }

    return false;
}

char next_c(char x)
{
    static const string DIMA = "DIMA";
    for (int i = 0; i < 4; i++) {
        if (x == DIMA[i]) {
            return DIMA[(i + 1) % 4];
        }
    }
    return 'X';
}
        

int dfs(int y, int x)
{
    char c = g[y][x];
    if (c == 'D') {
        if (visit[y][x] && dp[y][x] == -1) {
            return INF;
        } else if (visit[y][x]) {
            return dp[y][x];
        }
        visit[y][x] = 1;
    }
        
    int res = 0;
    char nn = next_c(c);
    for (int i = 0; i < 4; i++) {
        int ny = y + my[i];
        int nx = x + mx[i];

        if (avail(ny, nx) && g[ny][nx] == nn) {
            res = max(dfs(ny, nx), res);
        }
    }
    if (c == 'D') {
        dp[y][x] = res;
    }
    return res + (c == 'A'? 1 : 0);
}

int main()
{
    freopen("input.txt", "r", stdin);
    input(n >> m);

    memset(g, 0, sizeof(g));
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'D') {
                //memset(visit, 0, sizeof(visit));
                int t = dfs(i, j);
                ans = max(ans, t);
                dp[i][j] = t;
            }
        }
    }
    
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", dp[i][j]);
        }
        puts("");
    }
    */
    if (ans == 0) {
        print("Poor Dima!");
    } else if(ans >= INF) {
        print("Poor Inna!");
    } else {
        print(ans);
    }

    return 0;
}

