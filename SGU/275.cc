#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 64;
const int N = 100;

int n, m;
int mat[N][SIZE];

void xor_line(int a, int b) {
    for (int i = 0; i < SIZE; i++) {
        mat[a][i] ^= mat[b][i];
    }
}

void swap_line(int a, int b) {
    for (int i = 0; i < SIZE; i++) {
        swap(mat[a][i], mat[b][i]);
    }
}

void do_gauss(int l, int x) {
    for (int i = 0; i < n; i++) {
        if (i == l) {
            continue;
        }
        if (mat[i][x]) {
            xor_line(i, l);
        }
    }
}

uint64_t solve() {
    int cnt = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = cnt; j < n; j++) {
            if (mat[j][i]) {
                swap_line(cnt, j);
                do_gauss(cnt, i);
                cnt++;
                break;
            }
        }
    }
    uint64_t ans = 0;
    for (int i = 0; i < SIZE; i++) {
        uint64_t u = 0;
        for (int j = 0; j < SIZE; j++) {
            u = (u << 1) | mat[i][j];
        }
        ans ^= u;
    }
    return ans;
}

int main() {
    while (input(n)) {
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < n; i++) {
            uint64_t u = 0;
            input(u);
            for (int j = 0; j < SIZE; j++) {
                if (u & (1ULL << j)) {
                    mat[i][SIZE - j - 1] = 1;
                }
            }
        }
        print(solve());
    }
    return 0;
}

