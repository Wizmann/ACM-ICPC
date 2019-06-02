/*
URL: https://vjudge.net/problem/LightOJ-1151

### Description

10x10的棋盘上，顺序标号1\~100。从点1开始，随机扔骰子前进1\~6步。走到点100时（包括走出点100），游戏结束。

棋盘上有梯子和蛇，踩到梯子会向前传送，踩到蛇会向后传送。

问给定棋盘，从1走到100所需要步数的期望。

### Solution

高斯消元模板题。

对于没有梯子或蛇的格子`i`，有：

```math

E_{i} = \frac{E_{i + 1} + E_{i + 2} + \dotsb + E_{i + 6}}{6} + 1 

```

对于有梯子或蛇的格子`i`，如果其终点为格子`j`，有：

```math
E_{i} = E_{j}
```

我们联立方程组，然后使用高斯消元即可求解。
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 101;

double mat[SIZE][SIZE];
int nxt[SIZE];

void swap_line(int a, int b) {
    for (int i = 0; i < SIZE; i++) {
        swap(mat[a][i], mat[b][i]);
    }
}

void gauss() {
    for (int i = 0; i < 100; i++) {
        for (int j = i; j < 100; j++) {
            if (mat[j][i] != 0) {
                swap_line(i, j);
                break;
            }
        }

        if (mat[i][i] == 0) {
            continue;
        }

        double u = mat[i][i];
        for (int j = 0; j < SIZE; j++) {
            mat[i][j] /= u;
        }
        
        for (int j = 0; j < 100; j++) {
            if (j == i) {
                continue;
            }
            double f = mat[j][i] / mat[i][i];
            for (int k = 0; k < SIZE; k++) {
                mat[j][k] -= f * mat[i][k];
            }
        }
    }
}

int main() {
    int T;
    input(T);

    int case_ = 0;
    while (T--) {
        memset(mat, 0, sizeof(mat));
        memset(nxt, -1, sizeof(nxt));

        int k;
        input(k);

        int a, b;
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &a, &b);
            a--;
            b--;
            nxt[a] = b;
        }

        for (int i = 0; i < 100; i++) {
            if (nxt[i] != -1) {
                int v = nxt[i];
                mat[i][i] = 1;
                mat[i][v] = -1;
                continue;
            }

            for (int j = 1; j <= 6; j++) {
                int v = i + j;
                if (v >= 100) {
                    v = i;
                }
                mat[i][v] -= 1;
            }
            mat[i][i] += 6;
            mat[i][SIZE - 1] += 6;
        }
        gauss();
        printf("Case %d: %.10lf\n", ++case_, mat[0][SIZE - 1]);
    }

    return 0;
}
