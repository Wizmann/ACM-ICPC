#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 54;
const llint MOD = 1000000000 + 7;

struct Matrix {
    vector<vector<llint> > _mat;

    Matrix(int n, int m) {
        _mat.resize(n);
        for (auto& submat: _mat) {
            submat.resize(m);
            fill(submat.begin(), submat.end(), 0);
        }
    }

    friend Matrix operator * (const Matrix& mat0, const Matrix& mat1) {
        int n0 = mat0._mat.size();
        int m0 = mat0._mat[0].size();
        int n1 = mat1._mat.size();
        int m1 = mat1._mat[0].size();

        Matrix m(n0, m1);

        assert(m0 == n1);

        for (int i = 0; i < n0; i++) {
            for (int j = 0; j < m1; j++) {
                for (int k = 0; k < m0; k++) {
                    m._mat[i][j] += mat0._mat[i][k] * mat1._mat[k][j];
                    m._mat[i][j] %= MOD;
                }
            }
        }
        return m;
    }

    friend Matrix operator ^ (Matrix mat, llint u) {
        int n = mat._mat.size();
        int m = mat._mat[0].size();

        assert (n == m);

        Matrix res(n, m);
        for (int i = 0; i < n; i++) {
            res._mat[i][i] = 1;
        }

        while (u) {
            if (u & 1) {
                res = res * mat;
            }
            mat = mat * mat;
            u >>= 1;
        }
        return res;
    }
};

llint fast_pow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

llint my_frac(llint a, llint b) {
    llint u = fast_pow(b, MOD - 2);
    a = (a % MOD + MOD) % MOD;
    u = (u * a) % MOD;
    return u;    
}

llint n, k;
vector<llint> F;
vector<llint> C;

int main() {
    freopen("input.txt", "r", stdin);
    llint a;
    input(n >> k);
    Matrix A(1, n);
    Matrix B(n, n);

    for (int i = 0; i < n; i++) {
        input(a);
        F.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        input(a);
        C.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        A._mat[0][i] = F[i];
    }

    for (int i = 0; i < n - 1; i++) {
        B._mat[i + 1][i] = 1;
    }

    B._mat[0][n - 1] = my_frac(1, C[n - 1]);
    for (int i = 1; i < n; i++) {
        B._mat[i][n - 1] = my_frac(-C[i - 1], C[n - 1]);
    }
    
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld ", B._mat[i][j]);
        }
        puts("");
    }
    puts("");
    */
    

    Matrix CC = B ^ (k - n + 1);
    Matrix DD = A * CC;
    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%lld", DD._mat[0][i] % MOD);
    }
    puts("");
    return 0;
}
