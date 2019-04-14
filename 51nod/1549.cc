#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

double eps = 1e-8;

int zero(double f) {
    if (f < -eps) {
        return -1;
    } else if (f > eps) {
        return 1;
    } else {
        return 0;
    }
}

const int SIZE = 96;
const int N = 3;

const int NN = (SIZE + 1) * N;

double mat[NN + 10][NN + 10];

int get_id(int star, int win) {
    assert(win >= 0 && win <= 2);
    assert(star >= 0 && star <= SIZE);
    return win * (SIZE + 1) + star;
}

void swap_line(int a, int b) {
    if (a == b) {
        return;
    }
    for (int i = 0; i <= NN + 1; i++) {
        swap(mat[a][i], mat[b][i]);
    }
}

void gauss() {
    for (int i = 0; i <= NN; i++) {
        for (int j = i; j <= NN; j++) {
            if (zero(mat[j][i])!= 0) {
                swap_line(i, j);
                break;
            }
        }

        double u = mat[i][i];
        if (zero(u) == 0) {
            continue;
        }
        for (int j = 0; j <= NN + 1; j++) {
            mat[i][j] /= u;
        }

        for (int j = 0; j <= NN; j++) {
            if (i == j) {
                continue;
            }
            double f = mat[j][i] / mat[i][i];
            for (int k = i; k <= NN + 1; k++) {
                mat[j][k] -= mat[i][k] * f;
            }
        }
    }
}

int main() {
    int n;
    double p;
    input(n >> p);
    memset(mat, 0, sizeof(mat));

    n = 96 - n;

    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j < 3; j++) {
            int cur = get_id(i, j);
            mat[cur][cur] = -1;
            mat[cur][NN + 1] = -1;

            mat[cur][get_id(i + 1 + (j == 2), min(2, j + 1))] += p;
            mat[cur][get_id(i, 0)] += (1 - p);
        }
    }

    for (int i = 11; i <= 70; i++) {
        for (int j = 0; j < 3; j++) {
            int cur = get_id(i, j);
            mat[cur][cur] = -1;
            mat[cur][NN + 1] = -1;

            mat[cur][get_id(i + 1 + (j == 2), min(2, j + 1))] += p;
            mat[cur][get_id(i - 1, 0)] += (1 - p);
        }
    }

    for (int i = 71; i < 96; i++) {
        for (int j = 0; j < 3; j++) {
            int cur = get_id(i, j);
            mat[cur][cur] = -1;
            mat[cur][NN + 1] = -1;

            mat[cur][get_id(i + 1, min(2, j + 1))] += p;
            mat[cur][get_id(i - 1, 0)] += (1 - p);
        }
    }

    for (int i = 0; i < 3; i++) {
        int cur = get_id(SIZE, i);
        mat[cur][cur] = -1;
    }

    gauss();

    printf("%.6lf\n", mat[get_id(n, 0)][NN + 1]);

    return 0;
}

