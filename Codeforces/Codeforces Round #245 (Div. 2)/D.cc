// https://codeforces.com/problemset/problem/430/D
/*
此题题意不明，应该为：
1. A从左上到右下，B从左下到右上。
2. 两人的路径有且只有一个交点
3. 交点上的值不记入最终的值
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1234;

llint dp1[SIZE][SIZE];
llint dp2[SIZE][SIZE];
llint dp3[SIZE][SIZE];
llint dp4[SIZE][SIZE];
llint maze[SIZE][SIZE];

int n, m;

int main() {
    input(n >> m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &maze[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            llint a = dp1[i - 1][j];
            llint b = dp1[i][j - 1];
            dp1[i][j] = maze[i][j] + max(a, b);
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            llint a = dp2[i + 1][j];
            llint b = dp2[i][j + 1];
            dp2[i][j] = maze[i][j] + max(a, b);
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            llint a = dp3[i + 1][j];
            llint b = dp3[i][j - 1];
            dp3[i][j] = maze[i][j] + max(a, b);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            llint a = dp4[i - 1][j];
            llint b = dp4[i][j + 1];
            dp4[i][j] = maze[i][j] + max(a, b);
        }
    }

    llint res = 0;
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            llint a = dp1[i - 1][j] + dp2[i + 1][j];
            llint b = dp3[i][j - 1] + dp4[i][j + 1];
            res = max(res, a + b);

            llint c = dp1[i][j - 1] + dp2[i][j + 1];
            llint d = dp3[i + 1][j] + dp4[i - 1][j];
            res = max(res, c + d);
        }
    }
    print(res);
    return 0;
}
