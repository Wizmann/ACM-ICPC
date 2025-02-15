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

const int SIZE = 212345;

class DisjointSet {
public:
    DisjointSet(int n_): n(n_) {
        father.resize(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }
    
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        } else {
            return father[x] = find_father(father[x]);
        }
    }
    
    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        
        father[fa] = fb;
    }
    
    bool is_same_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        
        return fa == fb;
    }
private:
    int n;
    vector<int> father;
};

vector<int> g[SIZE];

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        int n, m1, m2;
        scanf("%d%d%d", &n, &m1, &m2);

        for (int i = 0; i < n + 1; i++) {
            g[i].clear();
        }

        int a, b;
        for (int i = 0; i < m1; i++) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        DisjointSet ds2(n + 1);
        for (int i = 0; i < m2; i++) {
            scanf("%d%d", &a, &b);
            ds2.make_union(a, b);
        }

        map<int, vector<int> > mp;
        for (int i = 1; i <= n; i++) {
            int f = ds2.find_father(i);
            mp[f].push_back(i);
        }

        int cnt = 0;
        DisjointSet ds1(n + 1);
        for (int i = 1; i <= n; i++) {
            if (g[i].empty()) {
                continue;
            }
            int cur = i;
            for (auto nxt : g[i]) {
                if (ds2.find_father(cur) != ds2.find_father(nxt)) {
                    cnt++;
                    continue;
                }
                ds1.make_union(cur, nxt);
            }
        }

        cnt /= 2;

        for (const auto& p : mp) {
            int cur = p.first;
            for (auto nxt : p.second) {
                if (ds1.find_father(cur) != ds1.find_father(nxt)) {
                    cnt++;
                    ds1.make_union(cur, nxt);
                }
            }
        }

        print(cnt);
    }

    return 0;
}

/*

^^^TEST^^^
5
3 2 1
1 2
2 3
1 3
2 1 1
1 2
1 2
3 2 0
3 2
1 2
1 0 0
3 3 1
1 2
1 3
2 3
1 2
-----
3
0
2
0
2
$$$TEST$$$

*/
