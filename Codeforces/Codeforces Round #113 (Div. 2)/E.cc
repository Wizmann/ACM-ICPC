#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int N = 4;

template <typename T>
class Matrix : public vector<vector<T> > {
public:
    Matrix() {}
    Matrix(T n) : vector<vector<T> >(n) {}
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
    int mod
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
            for (int j = 0; j < m1; j++) {
                res[i][j] = (res[i][j] + 1LL * ma[i][k] * mb[k][j] % mod) % mod;
            }
        }
    }

    return res;
}

template <typename T>
Matrix<T> matpow(const Matrix<T>& ma, int p, int mod) {
    int n = ma.size();
    int m = ma[0].size();

    assert (n == m);

    Matrix<T> a = ma;

    Matrix<T> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = vector<T>(n, 0);
        res[i][i] = 1;
    }

    while (p) {
        if (p & 1) {
            res = matmul(res, a, mod);
        }
        a = matmul(a, a, mod);
        p >>= 1;
    }
    return res;
}


int main() {
    int n;
    input(n);

    Matrix<llint> m2 = newMatrix<llint>(4, 4);
    m2[0] = {0, 1, 1, 1};
    m2[1] = {1, 0, 1, 1};
    m2[2] = {1, 1, 0, 1};
    m2[3] = {1, 1, 1, 0};

    m2 = matpow(m2, n, MOD);

    Matrix<llint> m1 = newMatrix<llint>(1, 4);
    m1[0] = {0, 0, 0, 1};

    auto res = matmul(m1, m2, MOD);
    print(res[0][3]);
    return 0;
}


/*

^^^TEST^^^
2
-----
3
$$$TEST$$$

^^^TEST^^^
4
-----
21
$$$TEST$$$

*/
