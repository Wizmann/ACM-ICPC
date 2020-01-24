#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int n_) {
        n = n_ + 1;
        tree = vector<int>(n + 1, 0);
    }
 
    void add(int pos, int value) {
        while (pos < n) {
            tree[pos] += value;
            pos += lowbit(pos);
        }
    }
 
    int sum(int pos) {
        int res = 0;
        while (pos) {
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
 
    int sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
 
private:
    int lowbit(int x) { return x & (-x); }
 
    int n;
    vector<int> tree;
};
 
int main() {
    int n, m;
    input(n >> m);
 
    BinaryIndexedTree bit(n + m + 123);
    vector<int> pos(n + 1, -1);
 
    vector<int> mini(n + 1);
    vector<int> maxi(n + 1);
 
    for (int i = 1; i <= n; i++) {
        pos[i] = m + i;
        mini[i] = maxi[i] = i;
        bit.add(m + i, 1);
    }
 
    int cur;
    for (int i = 0; i < m; i++) {
        scanf("%d", &cur);
        int p1 = pos[cur];
        bit.add(p1, -1);
        int p2 = (m - i);
        bit.add(p2, 1);
        mini[cur] = 1;
        maxi[cur] = max(maxi[cur], bit.sum(1, p1));
        pos[cur] = p2;
    }
 
    for (int i = 1; i <= n; i++) {
        int p = pos[i];
        maxi[i] = max(maxi[i], bit.sum(1, p));
    }
 
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", mini[i], maxi[i]);
    }
 
    return 0;
}
