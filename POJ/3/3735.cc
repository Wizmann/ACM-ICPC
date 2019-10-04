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

vector<vector<llint> > matmul(
    const vector<vector<llint> >& ma,
    const vector<vector<llint> >& mb
) {
    int n1 = ma.size();
    int m1 = ma[0].size();

    int n2 = mb.size();
    int m2 = mb[0].size();

    assert (m1 == n2);

    vector<vector<llint> > res(n1);
    for (int i = 0; i < n1; i++) {
        res[i] = vector<llint>(m2, 0);
    }

    for (int k = 0; k < n2; k++) {
        for (int i = 0; i < n1; i++) {
            if (ma[i][k] == 0) {
                continue;
            }
            for (int j = 0; j < m2; j++) {
                res[i][j] = (res[i][j] + ma[i][k] * mb[k][j]);
            }
        }
    }

    return res;
}

vector<vector<llint> > matpow(const vector<vector<llint> >& ma, int p) {
    int n = ma.size();
    int m = ma[0].size();

    assert (n == m);

    vector<vector<llint> > a = ma;

    vector<vector<llint> > res(n);
    for (int i = 0; i < n; i++) {
        res[i] = vector<llint>(n, 0);
        res[i][i] = 1;
    }

    while (p) {
        if (p & 1) {
            res = matmul(res, a);
        }
        a = matmul(a, a);
        p >>= 1;
    }
    return res;
}


int main() {
    int n, m, k;
    while (scanf("%d%d%d", &n, &k, &m) != EOF && n + m + k) {
        vector<vector<llint> > mat1(n + 1);
        for (int i = 0; i < n; i++) {
            mat1[i].push_back(0);
        }
        mat1[n].push_back(1);

        vector<vector<llint> > mat2(n + 1);
        for (int i = 0; i <= n; i++) {
            mat2[i] = vector<llint>(n + 1, 0);
            for (int j = 0; j <= n; j++) {
                mat2[i][j] = (i == j);
            }
        }

        char cmd[10];
        int a, b;
        vector<vector<llint> > mat3(n + 1);
        for (int i = 0; i <= n; i++) {
            mat3[i] = vector<llint>(n + 1, 0);
            for (int j = 0; j <= n; j++) {
                mat3[i][j] = (i == j);
            }
        }
        for (int act = 0; act < m; act++) {
            scanf("%s", cmd);
            if (cmd[0] == 'g') {
                scanf("%d", &a);
                mat3[a - 1][n] += 1;
            } else if (cmd[0] == 'e') {
                scanf("%d", &a);
                mat3[a - 1] = vector<llint>(n + 1, 0);
            } else if (cmd[0] == 's') {
                scanf("%d%d", &a, &b);
                swap(mat3[a - 1], mat3[b - 1]);
            }
        }

        mat3 = matpow(mat3, k);
        mat1 = matmul(mat3, mat1);

        assert(mat1.size() == n + 1);
        assert(mat1[0].size() == 1);

        for (int i = 0; i < n; i++) {
            if (i) {
                putchar(' ');
            }
            printf("%lld", mat1 [i][0]);
        }
        puts("");
    }

    return 0;
}
