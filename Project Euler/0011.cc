#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 20;

int A[SIZE + 5][SIZE + 5];

int par(int y, int x)
{
    int res = 1;
    if (x + 4 < SIZE) {
        for (int i = 0; i < 4; i++) {
            res *= A[y][x + i];
        }
    }
    return res;
}

int dia0(int y, int x)
{
    int res = 1;
    if (x + 4 < SIZE && y + 4 < SIZE) {
        for (int i = 0; i < 4; i++) {
            res *= A[y + i][x + i];
        }
    }
    return res;
}

int dia1(int y, int x)
{
    int res = 1;
    if (x - 4 >= 0 && y + 4 < SIZE) {
        for (int i = 0; i < 4; i++) {
            res *= A[y + i][x - i];
        }
    }
    return res;
}

int solve()
{
    int res = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            res = max(res, par(i, j));
            res = max(res, dia0(i, j));
            res = max(res, dia1(i, j));
        }
    }
    return res;
}

void make_T()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            swap(A[i][j], A[j][i]);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            input(A[i][j]);
        }
    }

    int ans = 0;
    ans = max(ans, solve());
    make_T();
    ans = max(ans, solve());

    print(ans);
    return 0;
}
