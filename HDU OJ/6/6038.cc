#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000000 + 7;

class DisjointSet {
public:
    DisjointSet(int n_) : n(n_), father(n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);

        father[fb] = fa;
    }

    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }
private:
    int n;
    vector<int> father;
};

int main() {
    freopen("a.txt", "r", stdin);

    int n, m;
    int case_ = 0;

    while (input(n >> m)) {
        vector<int> ns(n), ms(m);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d", &ms[i]);
        }

        DisjointSet dsa(n);
        DisjointSet dsb(m);

        for (int i = 0; i < n; i++) {
            dsa.make_union(i, ns[i]);
        }

        for (int i = 0; i < m; i++) {
            dsb.make_union(i, ms[i]);
        }

        map<int, int> mpa;
        map<int, int> mpb;

        for (int i = 0; i < n; i++) {
            int f = dsa.find_father(i);
            mpa[f]++;
        }

        for (int i = 0; i < m; i++) {
            int f = dsb.find_father(i);
            mpb[f]++;
        }

        map<int, int> cntb;
        for (map<int, int>::iterator iter = mpb.begin(); 
                iter != mpb.end();
                ++iter) {
            cntb[iter->second]++;
        }

        llint res = 1;
        for (map<int, int>::iterator iter = mpa.begin(); 
                iter != mpa.end();
                ++iter) {

            int u = iter->second;
            int tot = 0;

            for (map<int, int>::iterator jter = cntb.begin();
                    jter != cntb.end();
                    ++jter) {
                int v = jter->first;
                if (u % v == 0) {
                    tot += jter->first * jter->second;
                    tot %= MOD;
                }
            }
            res = (res * tot) % MOD;
        }
        printf("Case #%d: ", ++case_);
        print(res);
    }

    return 0;
}
