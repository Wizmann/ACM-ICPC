#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class DisjointSet {
public:
    DisjointSet(int n_) : n(n_ + 213), father(n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        father[fa] = fb;
        return fb;
    }

    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }
private:
    int n;
    vector<int> father;
};

struct Edge {
    int a, b;
};

int n;
vector<Edge> edges;

int main() {
    input(n);

    DisjointSet ds(n * 2 + 123);
    set<int> ps;
    map<int, int> mp;
    int idx = 0;

    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        if (mp.count(a) == 0) {
            mp[a] = idx++;
        }
        if (mp.count(b) == 0) {
            mp[b] = idx++;
        }
        a = mp[a];
        b = mp[b];

        if (ds.find_father(a) != ds.find_father(b)) {
            ds.make_union(a, b);
        } else {
            edges.push_back({a, b});
        }
    }

    map<int, int> g;
    for (int i = 0; i < idx; i++) {
        int f = ds.find_father(i);
        g[f] += 1;
    }

    set<int> visited;

    for (const auto& edge : edges) {
        int fa = ds.find_father(edge.a);
        int fb = ds.find_father(edge.b);
        if (visited.count(fa) == 0 && fa == fb) {
            g[fa]++;
            visited.insert(fa);
        }
    }

    int res = 0;
    for (const auto& kv : g) {
        // print(kv.first << ' ' << kv.second);
        res += kv.second - 1;
    }
    print(res);

    return 0;
}

/*
^^^TEST^^^
1
123456789 123456789
----
1
$$$TEST$$$

^^^TEST^^^
4
1 2
1 3
4 2
2 3
-----
4
$$$TEST$$$

^^^TEST^^^
2
111 111
111 111
-----
1
$$$TEST$$$

^^^TEST^^^
12
5 2
5 6
1 2
9 7
2 7
5 5
4 2
6 7
2 2
7 8
9 7
1 8
-----
8
$$$TEST$$$

*/

