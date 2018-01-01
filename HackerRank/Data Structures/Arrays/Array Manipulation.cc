#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 12345678;

typedef long long llint;

struct BITree {
    BITree(int n_) : n(n_ + 1), tree(n_ + 1, 0) {
        // pass
    }
    
    void add(int pos, int value) {
        while (pos > 0) {
            tree[pos] += value;
            pos -= lowbit(pos);
        }
    }
    
    void addseg(int a, int b, int val) {
        add(a - 1, -val);
        add(b, val);
    }
    
    llint sum(int pos) {
        llint res = 0;
        while (pos < n) {
            res += tree[pos];
            pos += lowbit(pos);
        }
        return res;
    }
    
    int lowbit(int x) {
        return x & (-x);
    }
    
    int n;
    vector<llint> tree;
};

int main() {
    int n, m;
    input(n >> m);
    
    BITree tree(n);
    
    int a, b, c;
    for (int i = 0; i < m; i++) {
        input(a >> b >> c);
        tree.addseg(a, b, c);
    }
    
    llint res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, tree.sum(i));
    }
    print(res);
    
    return 0;
}
