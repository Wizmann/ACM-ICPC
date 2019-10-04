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

const int MOD = 10007;

/*
   [1, 0, 0, 0]
   [r0b0 r0b1 r1b0 r1b1]   [ 2, 1, 1, 0 
                             1, 2, 0, 1
                             1, 0, 2, 1
                             0, 1, 1, 2 ]




r0b0 = r0b1 + r1b0 + 2 * r0b0
r0b1 = r0b0 + r1b1 + 2 * r0b1
r1b0 = r0b0 + r1b1 + 2 * r1b0
r1b1 = r0b1 + r1b0 + 2 * r1b1

*/

vector<vector<int> > matmul(
    const vector<vector<int> >& ma,
    const vector<vector<int> >& mb
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
        for (int j = 0; j < m1; j++) {
            for (int k = 0; k < n2; k++) {
                res[i][j] = (res[i][j] + ma[i][k] * mb[k][j]) % MOD;
            }
        }
    }

    return res;
}

vector<vector<int> > matpow(const vector<vector<int> >& ma, int p) {
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
            res = matmul(res, a);
        }
        a = matmul(a, a);
        p >>= 1;
    }
    return res;
}


int main() {
    int T;
    input(T);

    while (T--) {
        int n;
        scanf("%d", &n);

        vector<vector<int> > mat1;
        {
            int arr[] = { 1, 0, 0, 0 }; 
            int n = sizeof(arr) / sizeof(arr[0]); 
  
            vector<int> vect(arr, arr + n); 
            mat1.push_back(vect);
        }

        vector<vector<int> > mat2(4);
        for (int i = 0; i < 4; i++) {
            mat2[i] = vector<int>(4, 0);
            for (int j = 0; j < 4; j++) {
                mat2[i][j] = 1;
                if (i == j) {
                    mat2[i][j] = 2;
                } else if (j == 3 - i) {
                    mat2[i][j] = 0;
                }
            }
        }

        mat2 = matpow(mat2, n);
        mat1 = matmul(mat1, mat2);

        printf("%d\n", mat1[0][0]);
    }

    return 0;
}
