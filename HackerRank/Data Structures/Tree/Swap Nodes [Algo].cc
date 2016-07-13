#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Node {
    int left ,right;
    
    Node(): left(-1), right(-1) {}
};


void dfs(int cur, int depth, int k, vector<Node>& tree) {
    if (cur == -1) {
        return;
    }
    if (depth % k == 0) {
        swap(tree[cur].left, tree[cur].right);
    }
    dfs(tree[cur].left, depth + 1, k, tree);
    dfs(tree[cur].right, depth + 1, k, tree);
}

void inorder_traversal(int cur, vector<Node>& tree) {
    if (cur == -1) {
        return;
    }   
    inorder_traversal(tree[cur].left, tree);
    printf("%d ", cur + 1);
    inorder_traversal(tree[cur].right, tree);
}

int main() {
    int n;
    input(n);
    
    vector<Node> tree;
    tree.resize(n);
    
    for (int i = 0; i < n; i++) {
        int a, b;
        input(a >> b);
        
        if (a != -1) a--;
        if (b != -1) b--;
        
        tree[i].left = a;
        tree[i].right = b;
    }
    
    int T;
    input(T);
    while (T--) {
        int k;
        input(k);
        dfs(0, 1, k, tree);
        inorder_traversal(0, tree);
        puts("");
    }
    return 0;
}
