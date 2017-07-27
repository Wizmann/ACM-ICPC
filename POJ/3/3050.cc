#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 5;
const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

int board[N][N];
set<int> st;

void dfs(int y, int x, int step, int cur) {
    if (step == 0) {
        // print(cur);
        st.insert(cur);
        return;
    }
    cur = cur * 10 + board[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + my[i];
        int nx = x + mx[i];

        if (y < 0 || y >= N || x < 0 || x >= N) {
            continue;
        }

        dfs(ny, nx, step - 1, cur);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dfs(i, j, N + 1, 0);
        }
    }

    print(st.size());
    return 0;
}
