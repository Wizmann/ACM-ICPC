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

class Matrix : public vector<vector<double> > {
public:
    Matrix() {}
    Matrix(int n) : vector<vector<double> >(n) {}
};

Matrix newMatrix(int n, int m) {
    Matrix mat(n);
    for (int i = 0; i < n; i++) {
        mat[i] = vector<double>(m, 0);
    }
    return mat;
}

const int N = 21;
const int NN = 21 * 21;

vector<double> matrixSolve(Matrix& mat) {
    int n = mat.size();
    int m = mat[0].size();
    assert(m == n + 1);
    assert(n == NN);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (mat[j][i] == 0) {
                continue;
            }
            double u = mat[j][i] / mat[i][i];
            for (int k = 0; k < m; k++) {
                mat[j][k] -= mat[i][k] * u;
            }
        }
    }

    vector<double> res(n, 0);
    for (int i = 0; i < n; i++) {
        res[i] = mat[i][m - 1] / mat[i][i];
    }
    return res;
}

int main() {
    double u;
    while (input(u)) {
        Matrix mat = newMatrix(NN, NN + 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int idx1 = i * N + j;

                // invalid
                if (i > j) {
                    mat[idx1][idx1] = 1;
                    mat[idx1][NN] = INF;
                    continue;
                }

                if (max(i, j) == 20) {
                    mat[idx1][idx1] = 1;
                    mat[idx1][NN] = 0;
                    continue;
                }

                assert(i <= j);

                mat[idx1][idx1] += 1;
                mat[idx1][NN] = 1;

                {
                    int a1 = min(20, i + 1);
                    int b1 = j;

                    if (a1 > b1) {
                        swap(a1, b1);
                    }
                    assert(a1 <= b1);
                    assert(0 <= a1 && a1 <= 20 && 0 <= b1 && b1 <= 20);
                    int idx2 = a1 * N + b1;
                    mat[idx1][idx2] += -u;
                }
                {
                    int a2 = max(0, i - 2);
                    int b2 = j;

                    assert(0 <= a2 && a2 <= 20 && 0 <= b2 && b2 <= 20);
                    assert(a2 <= b2);
                    int idx3 = a2 * N + b2;
                    mat[idx1][idx3] += -(1 - u);
                }
            }
        }

        auto res = matrixSolve(mat);
        printf("%.6lf\n", res[0]);
    }
    return 0;
}

/*
^^^^TEST^^^
1.000000
0.814700
0.9
-------
39.000000
82.181160
54.489796
$$$TEST$$$
*/

