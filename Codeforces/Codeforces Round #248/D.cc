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

typedef long long llint;

const int SIZE = 1234;

int n, m, q;
int board[SIZE][SIZE];
int toright[SIZE][SIZE], toleft[SIZE][SIZE];

void modify(int y)
{
    int cnt;

    cnt = 0;
    for (int i = 0; i < m; i++) {
        if (board[y][i]) {
            cnt++;
        } else {
            cnt = 0;
        }
        toleft[y][i] = cnt;
    }

    cnt = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (board[y][i]) {
            cnt++;
        } else {
            cnt = 0;
        }
        toright[y][i] = cnt;
    }
}


void preload()
{
    for (int i = 0; i < n; i++) {
        modify(i);
    }
}

int judge_y(int y, int x, int dir)
{
    int ans = 0;
    int dis = 1;
    int maxil = toleft[y][x];
    int maxir = toright[y][x];
    for (int i = y; i < n && i >=0; i += dir) {
        if (!toleft[i][x]  || !toright[i][x]) {
            break;
        }
        maxil = min(maxil, toleft[i][x]);
        maxir = min(maxir, toright[i][x]);
        ans = max(ans, maxil * dis + maxir * dis - dis);
        dis++;
    }
    return ans;
}

int judge_x(int y, int x, int d[SIZE][SIZE])
{
    int l = y, r = y;
    int ans = 0;
    int now = d[y][x];
    while (1) {
        int vl = 0, vr = 0;
        if (l - 1 >= 0) {
            vl = d[l - 1][x];
        }
        if (r + 1 < n) {
            vr = d[r + 1][x];
        }
        if (!vl && !vr) break;
        if (vl > vr) {
            l--;
            now = min(now, vl);
            ans = max(ans, now * (r - l + 1));
        } else {
            r++;
            now = min(now, vr);
            ans = max(ans, now * (r - l + 1));
        }
    }
    return ans;
} 
        
        

int solve(int y, int x)
{
    int ans = 0;
    // JUDGE UPPER SIDE
    ans = max(ans, judge_y(y, x, +1));
    // JUDGE LOWER SIDE
    ans = max(ans, judge_y(y, x, -1));
    // JUDGE LEFT SIDE
    ans = max(ans, judge_x(y, x, toleft));
    // JUDGE RIGHT SIDE
    ans = max(ans, judge_x(y, x, toright));
    return ans;
}
    


int main()
{
    freopen("input.txt", "r", stdin);
    int a, b, c;
    input(n >> m >> q);
    memset(toleft, 0, sizeof(toleft));
    memset(toright, 0, sizeof(toright));
    memset(board, 0, sizeof(board));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a);
            board[i][j] = a;
        }
    }
    preload();

    while (q--) {
        scanf("%d%d%d", &a, &b, &c);
        b--; c--;
        if (a == 1) {
            board[b][c] ^= 1;
            modify(b);
        } else {
            print(solve(b, c));
        }
    }

    return 0;
}
