#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int MOD = 1000000000 + 7;

template <typename T>
class Matrix : public vector<vector<T> > {
public:
    Matrix() {}
    Matrix(int n) : vector<vector<T> >(n) {}
};

template <typename T>
Matrix<T> newMatrix(int n, int m) {
    Matrix<T> mat(n);
    for (int i = 0; i < n; i++) {
        mat[i] = vector<T>(m, 0);
    }
    return mat;
}

template <typename T>
Matrix<T> matmul(
    const Matrix<T>& ma,
    const Matrix<T>& mb,
    int MOD
) {
    int n1 = ma.size();
    int m1 = ma[0].size();

    int n2 = mb.size();
    int m2 = mb[0].size();

    assert (m1 == n2);

    Matrix<T> res(n1);
    for (int i = 0; i < n1; i++) {
        res[i] = vector<T>(m2, 0);
    }

    for (int i = 0; i < n1; i++) {
        for (int k = 0; k < n2; k++) {
            if (ma[i][k] == 0) {
                continue;
            }
            for (int j = 0; j < m2; j++) {
                res[i][j] = (res[i][j] + 1LL * ma[i][k] * mb[k][j] % MOD) % MOD;
            }
        }
    }

    return res;
}

template <typename T>
Matrix<T> matpow(const Matrix<T>& ma, int p, int MOD) {
    int n = ma.size();
    int m = ma[0].size();

    assert(n == m);

    Matrix<T> a = ma;

    Matrix<T> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = vector<T>(n, 0);
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

llint fastpow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

const int N = 123;
vector<int> g[N];
vector<int> vertices;

int main() {
    int n, m, k;
    input(n, m, k);

    vertices.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vertices[i]);
    }

    auto m1 = newMatrix<llint>(n, n);

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        int u = g[i].size();
        for (auto nxt : g[i]) {
            m1[nxt][i] += (1LL * fastpow(m, MOD - 2)) % MOD * fastpow(2, MOD - 2) % MOD;
            m1[i][i] += (1LL * fastpow(m, MOD - 2)) % MOD * fastpow(2, MOD - 2) % MOD;
            m1[nxt][i] %= MOD;
        }
        m1[i][i] += (1LL * (m - u) * fastpow(m, MOD - 2)) % MOD;
        m1[i][i] %= MOD;
    }

    m1 = matpow(m1, k, MOD);

    Matrix<llint> m2 = newMatrix<llint>(n, 1);
    for (int i = 0; i < n; i++) {
        m2[i][0] = vertices[i];
    }

    Matrix<llint> m3 = matmul<llint>(m1, m2, MOD);
    for (int i = 0; i < n; i++) {
        assert(m3[i].size() == 1);
        printf("%lld\n", m3[i][0]);
    }

    return 0;
}

/*
^^^TEST^^^
3 1 1
3 1 5
1 2
-----
2
2
5
$$$TEST$$$

^^^TEST^^^
3 1 1
3 1 5
1 3
-----
4
1
4
$$$TEST$$$

^^^TEST^^^
3 2 1
3 1 5
1 3
1 3
-----
4
1
4
$$$TEST$$$

^^^TEST^^^
3 2 1
3 1 5
1 2
1 3
-----
3
500000005
500000008
$$$TEST$$$

^^^TEST^^^
3 2 2
12 48 36
1 2
1 3
----
750000036
36
250000031
$$$TEST$$$

^^^TEST^^^
4 5 1000
578 173 489 910
1 2
2 3
3 4
4 1
1 3
----
201113830
45921509
67803140
685163678
$$$TEST$$$

*/
