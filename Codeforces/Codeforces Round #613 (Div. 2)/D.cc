#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
 
using namespace std;
 
#define input(x) cin >> x
#define print(x) cout << x << endl
 
const int N = 30;
const int INF = 0x3fffffff;
 
typedef long long llint;
 
struct TreeNode {
    TreeNode() {
        memset(next, -1, sizeof(next));
    }
    int next[2];
};
 
int n;
vector<TreeNode> tree;
vector<int> ns;
 
void do_insert(int cur, int num, int pos) {
    if (pos == -1) {
        return;
    }
 
    int p = (num & (1 << pos))? 1: 0;
    if (tree[cur].next[p] == -1) {
        tree.push_back(TreeNode());
        tree[cur].next[p] = tree.size() - 1;
    }
 
    do_insert(tree[cur].next[p], num, pos - 1);
}
 
int do_query(int cur, int num, int pos, int tot) {
    if (pos == -1) {
        return tot;
    }
 
    int res = INF;
    const TreeNode& curNode = tree[cur];
 
    assert(curNode.next[0] != -1 || curNode.next[1] != -1);
    if (curNode.next[0] == -1 || curNode.next[1] == -1) {
        for (int i = 0; i < 2; i++) {
            if (curNode.next[i] == -1) {
                continue;
            }
            res = min(res, do_query(curNode.next[i], num | (i << pos), pos - 1, tot));
        }
    } else {
        for (int i = 0; i < 2; i++) {
            int j = i ^ 1;
            int nxt = tot | (1 << pos);
            res = min(res, do_query(curNode.next[i], num | (j << pos), pos - 1, nxt));
        }
    }
 
    return res;
}
 
int main() {
    input(n);
 
    ns.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }
 
    tree.reserve(123456);
    tree.push_back(TreeNode());
 
    for (int i = 0; i < n; i++) {
        do_insert(0, ns[i], N);
    }
 
    print(do_query(0, 0, N, 0));
 
    return 0;
}
