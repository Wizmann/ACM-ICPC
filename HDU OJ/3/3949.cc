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

class LinearBasis {
public:
    LinearBasis(int n_, int m_): n(n_), m(m_) {
        mat.resize(n);
        for (int i = 0; i < n; i++) {
            mat[i] = vector<int>(m, 0);
        }
    }

    vector<vector<int> >& GetMatrix() {
        return mat;
    }

    llint solve() {
        int cnt = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = cnt; j < n; j++) {
                if (mat[j][i]) {
                    swap_line(cnt, j);
                    do_gauss(cnt, i);
                    cnt++;
                    break;
                }
            }
        }
        llint ans = 0;
        for (int i = 0; i < n; i++) {
            llint u = 0;
            for (int j = 0; j < m; j++) {
                u = (u << 1) | mat[i][j];
            }
            ans ^= u;
        }
        return ans;
    }

    void do_gauss(int l, int x) {
        for (int i = 0; i < n; i++) {
            if (i == l) {
                continue;
            }
            if (mat[i][x]) {
                xor_line(i, l);
            }
        }
    }

    void xor_line(int a, int b) {
        for (int i = 0; i < m; i++) {
            mat[a][i] ^= mat[b][i];
        }
    }

    void swap_line(int a, int b) {
        for (int i = 0; i < m; i++) {
            swap(mat[a][i], mat[b][i]);
        }
    }

private:
    int n, m;
    vector<vector<int> > mat;
};

const int BITS = 63;

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        int n;
        input(n);

        vector<llint> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%llu", &ns[i]);
        }

        LinearBasis lb(n, BITS);

        auto& mat = lb.GetMatrix();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < BITS; j++) {
                if (ns[i] & (1LL << j)) {
                    mat[i][j] = 1;
                }
            }
        }
        lb.solve();

        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < BITS; j++) {
                printf("%d", mat[i][j]);
            }
            puts("");
        }
        */

        bool hasZero = false;
        vector<llint> ms;
        for (int i = 0; i < n; i++) {
            llint u = 0;
            for (int j = 0; j < BITS; j++) {
                u |= (1LL * mat[i][j]) << j;
            }
            if (u) {
                ms.push_back(u);
            } else {
                hasZero = true;
            }
        }

        int m = ms.size();
        sort(ms.begin(), ms.end());

        /*
        for (auto num : ms) {
            print(num);
        }
        */

        printf("Case #%d:\n", case_ + 1);

        int q;
        input(q);
        while (q--) {
            llint query;
            scanf("%lld", &query);

            if (hasZero && query == 1) {
                puts("0");
            } else {
                if (hasZero) {
                    query--;
                }
                if (query >= (1LL << m)) {
                    puts("-1");
                    continue;
                }
                llint res = 0;
                for (int i = 0; i < BITS; i++) {
                    if (query & (1LL << i)) {
                        res ^= ms[i];
                    }
                }
                printf("%llu\n", res);
            }
        }
    }

    return 0;
}



/*

^^^TEST^^^
2
2
1 2
4
1 2 3 4
3
1 2 3
5
1 2 3 4 5
-----
Case #1:
1
2
3
-1
Case #2:
0
1
2
3
-1
$$$TEST$$$

*/
