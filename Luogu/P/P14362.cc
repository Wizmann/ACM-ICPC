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

const int SIZE = 555; // 占个位，保持风格一致

struct Edge {
    int a, b;   // 端点编号（城市 / 乡镇）
    int cost;   // 边权：int 足够，累加用 llint
};

class DisjointSet {
public:
    DisjointSet() {}

    void init(int n_) {
        n = n_;
        father.assign(n, 0);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) {
            father[i] = i;
            sz[i] = 1;
        }
    }

    int find_father(int x) {
        if (father[x] == x) return x;
        return father[x] = find_father(father[x]);
    }

    bool make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        if (fa == fb) return false;
        if (sz[fa] < sz[fb]) swap(fa, fb);
        father[fb] = fa;
        sz[fa] += sz[fb];
        return true;
    }

private:
    int n;
    vector<int> father;
    vector<int> sz;
};

int main() {
    int n, m, k;
    if (scanf("%d%d%d", &n, &m, &k) != 3) return 0;

    // 原图所有道路（只在最开始用来跑城市间 MST）
    vector<Edge> city_edges;
    city_edges.reserve(m);

    for (int i = 0; i < m; i++) {
        int u, v;
        int w;
        scanf("%d%d%d", &u, &v, &w);
        u--; v--; // 转成 0-based
        Edge e;
        e.a = u;
        e.b = v;
        e.cost = w;
        city_edges.push_back(e);
    }

    vector<int> c(k); // 城市化改造费用
    // 先不读 a[j][i]，等城市 MST 求完再边读边建边

    // Step 1: 在不考虑乡镇的前提下，先求原有 n 个城市的 MST
    sort(city_edges.begin(), city_edges.end(),
         [](const Edge& e1, const Edge& e2) {
             return e1.cost < e2.cost;
         });

    DisjointSet ds0;
    ds0.init(n);

    vector<Edge> all_edges; // 之后用于所有状态的 Kruskal
    all_edges.reserve(n - 1 + k * n);

    int used = 0;
    for (int i = 0; i < (int)city_edges.size(); i++) {
        if (ds0.make_union(city_edges[i].a, city_edges[i].b)) {
            all_edges.push_back(city_edges[i]); // 只保留 MST 边
            used++;
            if (used == n - 1) break;
        }
    }
    // 题目保证原有城市连通，理论上 used 应为 n-1
    // assert(used == n - 1);

    // Step 2: 读入乡镇相关信息，把乡镇-城市边全部加入 all_edges
    for (int j = 0; j < k; j++) {
        scanf("%d", &c[j]);
        for (int i = 0; i < n; i++) {
            int w;
            scanf("%d", &w);
            Edge e;
            e.a = n + j; // 把第 j 个乡镇映射到点 n + j
            e.b = i;     // 城市 i
            e.cost = w;
            all_edges.push_back(e);
        }
    }

    // Step 3: 把「城市 MST 边 + 所有乡镇-城市边」整体排序一次
    sort(all_edges.begin(), all_edges.end(),
         [](const Edge& e1, const Edge& e2) {
             return e1.cost < e2.cost;
         });

    DisjointSet ds;
    int total_nodes = n + k; // 城市 0..n-1，乡镇 n..n+k-1

    llint ans = INFLL;

    int total_states = (k == 0 ? 1 : (1 << k));

    for (int mask = 0; mask < total_states; mask++) {
        // 计算当前状态下城市化改造费用
        llint base_cost = 0;
        for (int j = 0; j < k; j++) {
            if (mask & (1 << j)) {
                base_cost += (llint)c[j];
            }
        }

        // 初始化并查集
        ds.init(total_nodes);

        llint mst_cost = 0;

        // Kruskal：扫描预先排好序的所有边
        for (int i = 0; i < (int)all_edges.size(); i++) {
            int a = all_edges[i].a;
            int b = all_edges[i].b;

            // 若这条边来自某个乡镇且该乡镇未被选中，则跳过
            if (a >= n) {
                int town_idx = a - n; // 0-based 的乡镇编号
                if (!(mask & (1 << town_idx))) {
                    continue;
                }
            }

            if (ds.make_union(a, b)) {
                mst_cost += (llint)all_edges[i].cost;
            }
        }

        llint total_cost = base_cost + mst_cost;
        if (total_cost < ans) ans = total_cost;
    }

    printf("%lld\n", ans);

    return 0;
}


/*

^^^TEST^^^
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
-----
13
$$$TEST$$$

*/
