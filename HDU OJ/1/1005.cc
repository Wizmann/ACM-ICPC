#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 2;

struct Matrix {
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }

    int mat[N][N];

    const static Matrix IdentityMatrix() {
        Matrix m;
        for (int i = 0; i < N; i++) {
            m.mat[i][i] = 1;
        }
        return m;
    }
};

Matrix matrix_mul(const Matrix& a, const Matrix& b, int mod) {
    Matrix m;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                m.mat[i][j] += (1LL * a.mat[i][k] * b.mat[k][j]) % mod;
                m.mat[i][j] %= mod;
            }
        }
    }

    return m;
}

Matrix matrix_power(Matrix a, int p, int mod) {
    Matrix m = Matrix::IdentityMatrix();
    while (p) {
        if (p & 1) {
            m = matrix_mul(m, a, mod);
        }
        a = matrix_mul(a, a, mod);
        p >>= 1;
    }
    return m;
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) != EOF && a + b + c) {
        if (c <= 2) {
            puts("1");
            continue;
        }
        Matrix m;
        m.mat[0][0] = a; m.mat[0][1] = 1;
        m.mat[1][0] = b; m.mat[1][1] = 0;

        m = matrix_power(m, c - 2, 7);
        printf("%d\n", int(m.mat[0][0] + m.mat[1][0]) % 7);
    }
    return 0;
}
