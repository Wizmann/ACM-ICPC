#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

#pragma comment(linker, "/STACK:102400000,102400000")

const int SIZE = 44444;

struct TreeNode {
    int parent;
    int dis;
    
    TreeNode() {}
    TreeNode(int iparent, int idis): parent(iparent), dis(idis) {}
};

struct Edge {
    int dest;
    int dis;
    
    Edge() {}
    Edge(int idest, int idis): dest(idest), dis(idis) {}
};

int n, q;
vector<Edge> g[SIZE];
vector<TreeNode> tree;
char visit[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        g[i].clear();
    }
    tree.resize(n + 1);
    memset(visit, 0, sizeof(visit));
}

void dfs(int parent, int cur, int dis) {
    tree[cur] = TreeNode(parent, dis);
    visit[cur] = 1;
    for (int i = 0; i < (int)g[cur].size(); i++) {
        Edge& e = g[cur][i];
        if (visit[e.dest]) {
            continue;
        }
        dfs(cur, e.dest, e.dis);
    }
}

int lca(int a, int b) {
    map<int, int> parents;
    
    int dis = 0;
    while (a != -1) {
        parents[a] = dis;
        dis += tree[a].dis;
        a = tree[a].parent;
    }
    
    int res = 0;
    while (b != -1) {
        if (parents.find(b) != parents.end()) {
            res += parents[b];
            break;
        }
        res += tree[b].dis;
        b = tree[b].parent;
    }
    return res;
}

int main() {
    int T;
    input(T);
    int a, b, c;
    while (T--) {
        input(n >> q);
        init();
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back(Edge(b, c));
            g[b].push_back(Edge(a, c));
        }
        dfs(-1, 1, -1);
        while (q--) {
            scanf("%d%d", &a, &b);
            printf("%d\n", lca(a, b));
        }
    }
    return 0;    
}
