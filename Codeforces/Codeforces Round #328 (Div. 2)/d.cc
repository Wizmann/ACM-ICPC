#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456 + 233;
const int INF = 0x3f3f3f3f;

vector<int> g[SIZE];
vector<int> attack;
vector<int> gg[SIZE];
vector<int> cnt;
int n, m;
int edges;

void dfs(int pos, int parent) {
    cnt[pos] += attack[pos];

    for (auto next: g[pos]) {
        if (next == parent) {
            continue;
        }
        dfs(next, pos);
        cnt[pos] += cnt[next];
        
        if (cnt[next]) {
            gg[pos].push_back(next);
            gg[next].push_back(pos);
            edges++;
        }
    }
}

int bfs(int st, int& max_depth) {
    struct Node {
        int pos;
        int pre;
        int depth;
    };
    
    queue<Node> q;
    q.push({st, 0, 0});
    int res = INF;
    
    while (!q.empty()) {
        auto node = q.front();
        // print(node.pos << ' ' << node.pre << ' ' << node.depth);
        
        q.pop();
        
        if (node.depth > max_depth || 
                (node.depth == max_depth && node.pos < res)) {
            max_depth = node.depth;
            res = node.pos;
        }
        
        for (auto next: gg[node.pos]) {
            if (next == node.pre) {
                continue;
            }
            q.push({next, node.pos, node.depth + 1});
        }
    }
    return res;
}

void solve(int root) {
    dfs(root, 0);
    int max_depth = 0;
    int a = bfs(root, max_depth);
    int b = bfs(a, max_depth);
    
    print(min(a, b));
    print(edges * 2 - max_depth);
}

int main() {
    freopen("d.txt", "r", stdin);
    int a, b;
    input(n >> m);
    attack.resize(n + 1, 0);
    cnt.resize(n + 1, 0);
    
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int root = -1;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        attack[a] = 1;
        root = a;
    }

    solve(root);
    return 0;
}


