#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

struct Range {
    int l, r;

    Range(int l_, int r_): l(l_), r(r_) {
        // pass
    }

    bool operator < (const Range& other) {
        if (l != other.l) {
            return l < other.l;
        }
        return r > other.r;
    }
};

class Solution {
public:
    Solution(int n_): n(n_) {
        // pass
    }

    void add_pair(int a, int b) {
        ps.push_back(Range(a, b));
    }

    vector<int> solve() {
        sort(ps.begin(), ps.end());

        vector<int> res(n, 0);
        set<int> st;

        for (int i = 1; i <= n; i++) {
            st.insert(i);
        }

        int l = 0;
        int r = -1;
        for (int i = 0; i < ps.size(); i++) {
            if (ps[i].r <= r) {
                continue;
            }

            for (int j = l; j < ps[i].l; j++) {
                if (res[j] != 0) {
                    st.insert(res[j]);
                }
            }

            l = ps[i].l;
            r = max(l, r + 1);

            assert(l < n && r < n);

            for (int j = r; j <= ps[i].r; j++) {
                res[j] = *st.begin();
                st.erase(st.begin());
            }

            r = ps[i].r;
        }

        for (int i = 0; i < n; i++) {
            if (res[i] == 0) {
                res[i] = 1;
            }
        }

        return res;
    }
private:
    int n;
    vector<Range> ps;
};

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);

    while (T--) {
        int n, m;
        input(n >> m);
        Solution S(n);

        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            S.add_pair(a - 1, b - 1);
        }

        vector<int> ns = S.solve();
        for (int i = 0; i < n; i++) {
            if (i) {
                printf(" ");
            }
            printf("%d", ns[i]);
        }
        puts("");
    }

    return 0;
}
