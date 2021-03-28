#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int M = 555;

class DisjointSet {
public:
    DisjointSet(int n_) : n(n_), father(n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);

        father[fb] = fa;
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
    int src;
    int dest;
    int cost;
};

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        int n;
        input(n);

        vector<vector<int>> board(n);
        vector<vector<int>> cost(n);
        for (int i = 0; i < n; i++) {
            board[i].resize(n);
            for (int j = 0; j < n; j++) {
                scanf("%d", &board[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            cost[i].resize(n);
            for (int j = 0; j < n; j++) {
                scanf("%d", &cost[i][j]);
            }
        }

        vector<Edge> edges;
        DisjointSet ds(M * 2);

        llint tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) {
                    edges.push_back({i, j + M, cost[i][j]});
                    tot += cost[i][j];
                }
            }
        }

        sort(edges.begin(), edges.end(),
                [](const Edge& e1, const Edge& e2) { return e1.cost > e2.cost; });

        vector<int> rs(n);
        vector<int> cs(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &rs[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &cs[i]);
        }

        llint cur = 0;
        for (const auto& e : edges) {
            if (ds.find_father(e.src) == ds.find_father(e.dest)) {
                continue;
            }
            ds.make_union(e.src, e.dest);
            cur += e.cost;
        }


        printf("Case #%d: %lld\n", case_ + 1, tot - cur);

    }

    return 0;
}



/*

^^^TEST^^^
3
3
1 -1 0
0 1 0
1 1 1
0 1 0
0 0 0
0 0 0
1 1 1
0 0 1
2
-1 -1
-1 -1
1 10
100 1000
1 0
0 1
3
-1 -1 -1
-1 -1 -1
0 0 0
1 1 3
5 1 4
0 0 0
0 0 0
0 0 0
-----
Case #1: 0
Case #2: 1
Case #3: 2
$$$TEST$$$

*/

