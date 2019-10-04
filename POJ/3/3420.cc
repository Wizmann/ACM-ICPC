#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

vector<vector<int> > matmul(
    const vector<vector<int> >& ma,
    const vector<vector<int> >& mb,
    int MOD
) {
    int n1 = ma.size();
    int m1 = ma[0].size();

    int n2 = mb.size();
    int m2 = mb[0].size();

    assert (m1 == n2);

    vector<vector<int> > res(n1);
    for (int i = 0; i < n1; i++) {
        res[i] = vector<int>(m2, 0);
    }

    for (int i = 0; i < n1; i++) {
        for (int k = 0; k < n2; k++) {
            if (ma[i][k] == 0) {
                continue;
            }
            for (int j = 0; j < m1; j++) {
                res[i][j] = (res[i][j] + ma[i][k] * mb[k][j]) % MOD;
            }
        }
    }

    return res;
}

vector<vector<int> > matpow(const vector<vector<int> >& ma, int p, int MOD) {
    int n = ma.size();
    int m = ma[0].size();

    assert (n == m);

    vector<vector<int> > a = ma;

    vector<vector<int> > res(n);
    for (int i = 0; i < n; i++) {
        res[i] = vector<int>(n, 0);
        res[i][i] = 1;
    }

    while (p) {
        if (p & 1) {
            res = matmul(res, a, MOD);
        }
        a = matmul(a, a, MOD);
        p >>= 1;
    }
    return res;
}

typedef vector<vector<int> > Matrix;

Matrix newMatrix(int n, int m) {
    vector<vector<int> > mat(n);
    for (int i = 0; i < n; i++) {
        mat[i] = vector<int>(m, 0);
    }
    return mat;
}

const int N = 4;
const int M = 1 << 4;

void dfs(int cur, int nxt, vector<int>& status) {
    if (cur == M - 1) {
        assert (nxt < M);
        status[nxt]++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (cur & (1 << i)) {
            continue;
        }

        dfs(cur | (1 << i), nxt | (1 << i), status);

        if (i + 1 < N && !(cur & (1 << (i + 1)))) {
            dfs(cur | (1 << i) | (1 << (i + 1)), nxt, status);
        }

        break;
    }
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF && n + m) {
        Matrix m2 = newMatrix(M, M);
        for (int i = 0; i < (1 << N); i++) {
            vector<int> tmp(M);
            dfs(i, 0, tmp);
            for (int j = 0; j < M; j++) {
                m2[j][i] = tmp[j];
            }
        }

        /*
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                printf("%d ", m2[i][j]);
            }
            puts("");
        }
        */

        m2 = matpow(m2, n, m);

        /*
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                printf("%d ", m2[i][j]);
            }
            puts("");
        }
        */

        printf("%d\n", m2[0][0]);
    }
    return 0;
}
