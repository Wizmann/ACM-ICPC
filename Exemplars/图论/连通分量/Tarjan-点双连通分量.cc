// Checked by: https://www.luogu.com.cn/problem/P3388

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
#include <climits>

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

const int NODE = 22345;
const int EDGE = 123456;

struct Node {
    int val;
    int next;
};

class Graph {
public:
    Graph() {}

    Graph(int node_cnt, int edge_cnt) : head(node_cnt, -1), links(edge_cnt) {
        // pass
    }

    class GraphIterator {
    public:
        GraphIterator(const Graph& g_, int a) : g(g_) {
            idx = g.head[a];
        }

        int getNext() {
            if (idx == -1) {
                return -1;
            }
            assert(idx >= 0);
            idx = g.links[idx].next;
        }

        int getCurrent() {
            if (idx == -1) {
                return -1;
            }
            assert(idx >= 0);
            return g.links[idx].val;
        }
    private:
        const Graph& g;
        int idx;
    };

    void addEdge(int a, int b) {
        links[idx] = {b, head[a]};
        head[a] = idx;
        idx++;
    }

    GraphIterator getIterator(int a) {
        return GraphIterator(*this, a);
    }

private:
    int idx = 0;
    vector<int> head;
    vector<Node> links;
};

int n, m;

int dfn[NODE], low[NODE];
int idx;
int cut[NODE];

Graph g;

void init() {
    idx = 0;
    memset(dfn, -1, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(cut, 0, sizeof(cut));
}

void tarjan(int cur, int pre) {
    int child = 0;
    low[cur] = dfn[cur] = ++idx;

    for (auto iter = g.getIterator(cur); iter.getCurrent() != -1; iter.getNext()) {
        int nxt = iter.getCurrent();
        if (nxt == pre) {
            continue;
        }

        if (dfn[nxt] == -1) {
            tarjan(nxt, cur);
            low[cur] = min(low[cur], low[nxt]);

            if (low[nxt] >= dfn[cur] && cur != pre) {
                cut[cur] = true;
            }
            if (cur == pre) {
                child++;
            }
        } else {
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }

    if (child >= 2 && cur == pre) {
        cut[cur] = true;
    }
}

int main() {
    input(n, m);
    init();

    g = Graph(NODE, EDGE * 2);

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g.addEdge(a, b);
        g.addEdge(b, a);
    }

    for (int i = 1; i <= n; i++) {
        if (dfn[i] == -1) {
            tarjan(i, i);
        }
    }

    vector<int> cuts;
    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            cuts.push_back(i);
        }
    }
    print(cuts.size());

    for (auto num : cuts) {
        printf("%d ", num);
    }
    puts("");

    return 0;
}

/*
^^^TEST^^^
6 7
1 2
1 3
1 4
2 5
3 5
4 5
5 6
-----
1
5
$$$TEST$$$
*/

