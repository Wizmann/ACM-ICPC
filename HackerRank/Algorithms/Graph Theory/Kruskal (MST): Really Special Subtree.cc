#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Edge {
    int src, dest, cost;
};

vector<Edge> edges;

class DisjointSet {
public:
    DisjointSet(int n_): n(n_), father(n_ + 1) {
        for (int i = 0; i <= n; i++) {
            father[i] = i;
        }
    }
    
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }
    
    void make_union(int a, int b) {
        father[find_father(a)] = find_father(b);
    }
    
    bool same_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        
        return fa == fb;
    }
private:
    int n;
    vector<int> father;
};

int n, m;

int main() {
    int a, b, c;
    input(n >> m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({a, b, c});
        edges.push_back({b, a, c});
    }
    
    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
        return e1.cost < e2.cost;
    });
    
    DisjointSet ds(n);
    
    int ans = 0;
    for (const auto& edge: edges) {
        if (ds.same_union(edge.src, edge.dest)) {
            continue;
        }
        
        ds.make_union(edge.src, edge.dest);
        //print(edge.src << ' ' << edge.dest << ' ' << edge.cost);
        ans += edge.cost;
    }
    print(ans);
    
    return 0;
}
