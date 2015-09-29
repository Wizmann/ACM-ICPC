#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define input(x) cin >> x
#define print(x) cout << x << endl

struct Node {
    int cat;
    vector<int> neighbours;
};

int n, m;
int ans;
vector<Node> tree;
vector<bool> visit;

void dfs(int ptr) {
    visit[ptr] = true;
    if (tree[ptr].cat > m) {
        return;
    }

    bool is_leaf = true;

    for (auto neighbour: tree[ptr].neighbours) {
        if (visit[neighbour]) {
            continue;
        }
        if (tree[neighbour].cat != 0) {
            tree[neighbour].cat += tree[ptr].cat;
        }
        is_leaf = false;
        dfs(neighbour);
    }
    
    if (is_leaf) {
        ans++;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ans = 0;
    int a, b;
    input(n >> m);
    tree.resize(n + 1);
    visit.resize(n + 1);
    fill(visit.begin(), visit.end(), false);
    for (int i = 1; i <= n; i++) {
        input(tree[i].cat);
    }
    for (int i = 0; i < n - 1; i++) {
        input(a >> b);
        tree[a].neighbours.push_back(b);
        tree[b].neighbours.push_back(a);
    }

    dfs(1);
    print(ans);

    return 0;
}
