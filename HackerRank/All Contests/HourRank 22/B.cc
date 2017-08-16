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

const int SIZE = 123456;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;

struct Edge {
    int src, dest, cost;
};

int n, m;
llint max_edge;
llint min_tree;
vector<Edge> edges;
int father[SIZE];

int find_father(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find_father(father[x]);
}

void init() {
    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }
}

void kruskal1() {
    init();
    max_edge = INF;
    min_tree = 0;
    for (const auto& edge: edges) {
        int a = edge.src;
        int b = edge.dest;
        
        if (find_father(a) == find_father(b)) {
            continue;
        }

        max_edge = edge.cost;
        min_tree += edge.cost;

        father[find_father(b)] = find_father(a);
    }
}

int kruskal2() {
    init();
    int cnt = 0;
    for (const auto& edge: edges) {
        int a = edge.src;
        int b = edge.dest;
        
        if (find_father(a) == find_father(b)) {
            continue;
        }

        if (edge.cost >= max_edge) {
            break;
        }
        cnt++;

        father[find_father(b)] = find_father(a);
    }
    return cnt;
}

void solve() {
    kruskal1();
    kruskal2();
    
    int cnt = 0;

    for (const auto& edge: edges) {
        int a = edge.src;
        int b = edge.dest;
        if (find_father(a) != find_father(b)) {
            cnt++;
        }
    }
    print(min_tree - max_edge << ' ' << cnt);
}

int main() {    
    int a, b, c;
    input(n >> m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), 
        [](const Edge& e1, const Edge& e2) {
            return e1.cost < e2.cost;
        });

    solve();
    return 0;
}
