#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 333;

int n, m, r;
int matrix[SIZE][SIZE];

const int mx[] = {0, 1, 0, -1};
const int my[] = {1, 0, -1, 0};

void rotate(int y, int x, int step) {
    int nn = n - y * 2;
    int mm = m - x * 2;
    while (step--) {
        int tmp = -1;
        int dy = 0;
        int dx = 0;
        int dir = 0;

        do {
            int cur_y = dy + y;
            int cur_x = dx + x;
            swap(tmp, matrix[cur_y][cur_x]);

            int dy_next = dy + my[dir];
            int dx_next = dx + mx[dir];
            
            if (dy_next < 0 || dy_next >= nn || dx_next < 0 || dx_next >= mm) {
                dir = (dir + 1) % 4;
            }

            dy = dy + my[dir];
            dx = dx + mx[dir];
        } while (dx != 0 || dy != 0);

        matrix[y][x] = tmp;
    }
}

int main() {
    input(n >> m >> r);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < (min(m, n) + 1) / 2; i++) {
        int cnt = ((n - i * 2) + (m - i * 2)) * 2 - 4;
        if (cnt != 0) {
            rotate(i, i, r % cnt);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) {
                printf(" ");
            }
            printf("%d", matrix[i][j]);
        }
        puts("");
    }
    return 0;
}
