#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

class BiTree {
public:
    BiTree(int n_): n(n_ + 1), tree(n + 1, 0) {}
    
    void add(int pos, int val) {
        while (pos < n) {
            tree[pos] += val;
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
    int lowbit(int x) {
        return x & (-x);
    }
private:
    int n;
    vector<int> tree;
};

int main() {
    int n;
    input(n);

    vector<pair<int, int> > ns;
    ns.reserve(n);
    
    int x;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        ns.push_back({x, i});
    }
    sort(ns.begin(), ns.end());

    BiTree bit(n);
    int maxi = 0;
    for (int i = n - 1; i >= 0; i--) {
        int rank = i + 1;
        int pos = ns[i].second;

        int cnt = bit.sum(1, pos) + (pos < rank ? bit.sum(pos, rank): 0) + 1;
        maxi = max(maxi, cnt);
        bit.add(pos, 1);
    }
    print(maxi);

    return 0;
}

/*

^^^TEST^^^
5
1
5
3
8
2
-----
4
$$$TEST$$$

*/
