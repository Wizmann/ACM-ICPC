#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

class Solution {
public:
    Solution(int n_, int k_, llint p_, const vector<int>& ns_):
            n(n_), k(k_), p(p_), ns(ns_) {
        // pass
    }

    int solve() {
        vector<llint> mat(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
                mat[i] |= 1LL << j;
            }
        }

        mat = mat_pow(mat, p);

        int res = 0;
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                llint u = (mat[j] & (1LL << i))? 1: 0;
                s += ns[j] * u;
                s %= 2;
            }
            res += s % 2;
        }
        return res;
    }
private:
    vector<llint> mat_pow(vector<llint> mat, llint p) {
        vector<llint> res(n);
        for (int i = 0; i < n; i++) {
            res[i] |= 1LL << i;
        }

        while (p) {
            if (p & 1) {
                res = mat_mul(res, mat);
            }
            p >>= 1;
            mat = mat_mul(mat, mat);
        }
        return res;
    }

    vector<llint> mat_mul(const vector<llint>& m1, const vector<llint>& m2) {
        vector<llint> res(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                llint u = __builtin_popcountll(m1[i] & m2[j]);
                res[i] |= (u % 2) << j;
            }
        }
        return res;
    }
private:
    int n, k;
    llint p;
    vector<int> ns;
};


int main() {
    int T;
    input(T);
    while (T--) {
        int n, k;
        llint p;
        input(n >> k >> p);
        vector<int> ns(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        print(Solution(n, k, p, ns).solve());
    }
    return 0;
}
