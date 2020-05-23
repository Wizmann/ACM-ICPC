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

const int INF = 0x3f3f3f3f;

int solve(int n, int a, int b) {
    const int my[] = {+a, +b, +a, +b, -a, -b, -a, -b};
    const int mx[] = {+b, +a, -b, -a, +b, +a, -b, -a};

    vector<vector<int> > board(n);
    for (int i = 0; i < n; i++) {
        board[i] = vector<int>(n, INF);
    }
    board[0][0] = 0;

    queue<pair<int, int> > q;
    q.push({0, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int y = cur.first;
        int x = cur.second;

        for (int i = 0; i < 8; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
                continue;
            }
            if (board[ny][nx] > board[y][x] + 1) {
                board[ny][nx] = board[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    int res = board[n - 1][n - 1];
    if (res >= INF) {
        return -1;
    }
    return res;
}

int main() {
    int n;
    input(n);

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            printf("%d ", solve(n, i, j));
        }
        puts("");
    }

    return 0;
}
