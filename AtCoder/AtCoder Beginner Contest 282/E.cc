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

const int SIZE = 555;

struct Edge {
    int a, b;
    llint cost;
};

vector<Edge> edges;

class DisjointSet {
public:
    DisjointSet() {}
    DisjointSet(int n_) : n(n_), father(n), size(n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
            size[i] = 1;
        }
    }

    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);

        if (fa == fb) {
            return;
        }

        father[fb] = fa;
        size[fa] += size[fb];
    }

    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }

    int get_size(int a) {
        int f = find_father(a);
        return size[f];
    }
private:
    int n;
    vector<int> father;
    vector<int> size;
};

llint fastpow(llint a, llint b, llint MOD) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

llint kruskal(int n) {
    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
        return e1.cost > e2.cost;
    });

    DisjointSet ds(n);
    llint res = 0;
    for (const auto& e : edges) {
        int a = e.a;
        int b = e.b;
        llint cost = e.cost;

        if (ds.find_father(a) != ds.find_father(b)) {
            res += cost;
            ds.make_union(a, b);
        }
    }
    return res;
}

int main() {
    int n, m;
    input(n, m);

    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            llint cost = (fastpow(ns[i], ns[j], m) +
                          fastpow(ns[j], ns[i], m)) % m;
            edges.push_back({i, j, cost});
        }
    }

    llint res = kruskal(n);
    print(res);

    return 0;
}

/*

^^^TEST^^^
4 10
4 2 3 2
-----
20
$$$TEST$$$

^^^TEST^^^
20 100
29 31 68 20 83 66 23 84 69 96 41 61 83 37 52 71 18 55 40 8
-----
1733
$$$TEST$$$

*/
