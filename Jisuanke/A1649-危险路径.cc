#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;
typedef unsigned long long ullint;

struct Edge {
    int a, b, c;
};

struct Node {
    int l, r, w, lc, rc;
};

class DisjointSet {
public:
    DisjointSet(int n_): n(n_), father(n + 1), set_size(n + 1, 0) {
        for (int i = 1; i < n; i++) {
            father[i] = i;
            set_size[i] = 1;
        }
    }

    int size(int u) {
        int f = find_father(u);
        return set_size[f];
    }

    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }

        return father[x] = find_father(father[x]);
    }

    int make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);

        father[fa] = fb;
        set_size[fb] += set_size[fa];

        return fb;
    }

    bool same_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        return fa == fb;
    }
private:
    int n;
    vector<int> father;
    vector<int> set_size;
};

vector<Edge> edges;
vector<Node> nodes;
vector<vector<Edge> > g;
map<int, int> mp;
int n, m;

ullint dfs(int cur, ullint sum) {
    if (nodes[cur].l == -1) {
        // print(cur << ' ' << sum);
        return 1ULL * cur * sum;
    }
    ullint a = dfs(nodes[cur].l, 1ULL * nodes[cur].rc * nodes[cur].w + sum);
    ullint b = dfs(nodes[cur].r, 1ULL * nodes[cur].lc * nodes[cur].w + sum);
    return a ^ b;
}

int main() {
    int T;
    input(T);
    for (int case_ = 1; case_ <= T; case_++) {
        input(n >> m);
        g = vector<vector<Edge> >(n);
        edges = vector<Edge>();
        mp.clear();
        nodes.clear();

        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back({a, b, c});
        }
        sort(edges.begin(), edges.end(), 
                [](const Edge& e1, const Edge& e2) {
                    return e1.c < e2.c;
                });

        auto ds = DisjointSet(n + 1);
        ullint ans = 0;

        nodes.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            nodes[i] = { -1, -1, 0 };
            mp[i] = i;
        }

        for (auto& e: edges) {
            if (ds.same_union(e.a, e.b)) {
                continue;
            }
            
            e.a = ds.find_father(e.a);
            e.b = ds.find_father(e.b);

            int sa = ds.size(e.a);
            int sb = ds.size(e.b);

            ans += 1LL * e.c * sa * sb;
            
            int f = ds.make_union(e.a, e.b);

            nodes.push_back({ mp[e.a], mp[e.b], e.c , sa, sb});
            mp[f] = nodes.size() - 1;
        }

        printf("Case #%d: ", case_);
        print(dfs(nodes.size() - 1, 0));
    }
    return 0;
}
