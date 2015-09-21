#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int NODE = 20010;
const int EDGE = 100010;
const int QUERY = 5010;

struct Edge {
    int a, b;
    int cost;

    Edge(){}
    Edge(int ia, int ib, int icost):
            a(ia), b(ib), cost(icost) {}

    bool operator < (const Edge& e1) const {
        return cost < e1.cost;
    }
};

int n, m, q;
vector<Edge> edges;
vector<int> queries;
map<int, llint> qmap;
vector<pair<int, int> > father;

int find_father(int x) {
    if (father[x].first == x) {
        return x;
    }
    int u = find_father(father[x].first);
    father[u].second += father[x].second;
    father[x].first = u;
    father[x].second = 0;
    return u;
}

void add_union(int a, int b) {
    int u = find_father(a);
    int v = find_father(b);
    if (u == v) {
        return;
    }
    father[v].first = u;
    father[u].second += father[v].second;
    father[v].second = 0;
}

void solve() {
    int idx = 0;
    llint ans = 0;
    for (map<int, llint>::iterator iter = qmap.begin();
            iter != qmap.end();
            ++iter) {
        int q = iter->first;
        while (idx < m && edges[idx].cost <= q) {
            int aa = find_father(edges[idx].a);
            int bb = find_father(edges[idx].b);
            
            if (aa != bb) {
                ans += 2LL * father[aa].second * father[bb].second;
                add_union(aa, bb);
            }
            ++idx;
        }
        qmap[q] = ans;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    int a, b, c;
    input(T);
    
    edges.reserve(EDGE);
    queries.reserve(QUERY);
    father.reserve(NODE);
    
    while (T--) {
        scanf("%d%d%d", &n, &m, &q);
        
        edges.clear();
        queries.clear();
        qmap.clear();
        father.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            father[i] = pair<int, int>(i, 1);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back(Edge(a, b, c));
        }
        sort(edges.begin(), edges.end());

        for (int i = 0; i < q; i++) {
            scanf("%d", &a);
            queries.push_back(a);
            qmap[a] = -1;
        }

        solve();
        for (int i = 0; i < q; i++) {
            printf("%lld\n", qmap[queries[i]]);
        }
    }
    return 0;
}
