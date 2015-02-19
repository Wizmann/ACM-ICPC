#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long int llint;

const int SIZE = 101;
const int MOD = 1000 * 1000 * 1000 + 7;

struct Matrix {
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }
    llint mat[SIZE][SIZE];
};

int n, x;
llint cnt[SIZE];
llint dp[SIZE + 1];

Matrix B, C;

void get_dp() {
    dp[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] += (cnt[j] * dp[i - j]) % MOD;
            dp[i] %= MOD;
        }
    }
}

Matrix matrix_mul(const Matrix& a, const Matrix& b) {
    Matrix res;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                res.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % MOD;
                res.mat[i][j] %= MOD;
            }
        }
    }
    return res;
}

Matrix matrix_pow(const Matrix& mat, int t) {
    if (t == 1) {
        return mat;
    }
    Matrix tmp;
    tmp = matrix_pow(mat, t / 2);
    tmp = matrix_mul(tmp, tmp);
    if (t & 1) {
        tmp = matrix_mul(tmp, mat);
    }
    return tmp;
}

llint get_ans() {
    llint ans = 0;
    for (int i = 0; i < SIZE; i++) {
        ans += dp[i + 1] * C.mat[i][SIZE - 1];
        ans %= MOD;
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    
    input(n >> x);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        cnt[d]++;
    }

    get_dp();
    
    if (x <= 100) {
        llint ans = 0;
        for (int i = 0; i <= x; i++) {
            ans += dp[i];
            ans %= MOD;
        }
        print(ans);
        exit(0);
    }

    llint sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += dp[i];
    }
    dp[SIZE] = sum % MOD;

    for (int i = 0; i < SIZE - 2; i++) {
        B.mat[i + 1][i] = 1;
    }
    for (int i = 0; i < SIZE - 1; i++) {
        B.mat[i][SIZE - 2] = B.mat[i][SIZE - 1] = cnt[100 - i];
    }
    B.mat[SIZE - 1][SIZE - 1] = 1;

    C = matrix_pow(B, x - 100);
    print(get_ans());

    return 0;
}
