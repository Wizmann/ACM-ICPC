// 26064072 2018-08-25 00:20:33 Accepted    4280    7020MS  17844K  2842 B  G++ Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

#define INF 0x3f3f3f3f

const int NODE = 100007;
const int EDGE = 100007;

struct Edge
{
    int v, flow, next;
} e[EDGE << 1];
 
int n, m;
int head[NODE], edge_num, layer[NODE];
 
void addedge(int u, int v, int w)
{
    e[edge_num].v = v;
    e[edge_num].flow = w;
    e[edge_num].next = head[u];
    head[u] = edge_num++;
}
 
bool bfs(int start, int End)
{
    queue<int> Q;
    Q.push(start);
    memset(layer, 0, sizeof(layer));
    layer[start] = 1;
    while (Q.size())
    {
        int u = Q.front();
        Q.pop();
 
        if (u == End)
            return true;
 
        for (int j = head[u]; j != -1; j = e[j].next)
        {
            int v = e[j].v;
 
            if (layer[v] == false && e[j].flow)
            {
                layer[v] = layer[u] + 1;
                Q.push(v);
            }
        }
    }
 
    return false;
}
int dfs(int u, int MaxFlow, int End)
{
    if (u == End)
        return MaxFlow;
 
    int uflow = 0;
 
    for (int j = head[u]; j != -1; j = e[j].next)
    {
        int v = e[j].v;
 
        if (layer[v] - 1 == layer[u] && e[j].flow)
        {
            int flow = min(MaxFlow - uflow, e[j].flow);
            flow = dfs(v, flow, End);
 
            e[j].flow -= flow;
            e[j ^ 1].flow += flow;
 
            uflow += flow;
 
            if (uflow == MaxFlow)
                break;
        }
    }
    if (uflow == 0)
        layer[u] = 0;
    return uflow;
}
int dinic(int start, int End, int N)
{
    int MaxFlow = 0;
 
    while (bfs(start, End))
        MaxFlow += dfs(start, INF, End);
    return MaxFlow;
}

pair<int, int> points[NODE];

void init() {
    memset(head, -1, sizeof(head));
    edge_num = 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    int a, b, c;
    scanf("%d", &T);
    while (T--) {
        init();

        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            points[i] = pair<int, int>(a, b);
        }

        int lm = 0;
        int rm = 0;

        for (int i = 0; i < n; i++) {
            if (points[i].first < points[lm].first) {
                lm = i;
            }
            if (points[i].first > points[rm].first) {
                rm = i;
            }
        }

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            a--;
            b--;
            addedge(a, b, c);
            addedge(b, a, c);
        }
        printf("%d\n", dinic(rm, lm, 1));
    }
    return 0;
}
