//Result: May 5, 2014 3:25:55 PM    Wizmann  C - Checkposts  GNU C++0x  Accepted    124 ms  8304 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int NODENUM = 100010;
const int EDGENUM = 300010;

struct Edge {
    int dest;
    int next;

    Edge(){}
    Edge(int idest, int inext): dest(idest), next(inext) {}
};

template<typename CItem, int nodenum, int itemnum>
struct AdjList {
    int header[nodenum + 5];
    CItem item[itemnum + 5];
    int idx;

    void init()
    {
        memset(header, -1, sizeof(header));
        idx = 0;
    }

    void addedge(int node, const CItem& i_item)
    {
        int next = header[node];
        item[idx] = i_item;
        header[node] = idx;
        item[idx].next = next;
        ++idx;
    }
};


AdjList<Edge, NODENUM, EDGENUM> g;

stack<int> st;
char inst[NODENUM];

int n, m, ts;
int dfn[NODENUM], low[NODENUM];
int scc[NODENUM], num[NODENUM], sccnr;
int cost[NODENUM];
int ans[NODENUM], counter[NODENUM];

void tarjan_init()
{
    st = stack<int>();
    memset(inst, 0, sizeof(inst));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(scc, 0, sizeof(scc));
    memset(num, 0, sizeof(num));
    sccnr = 0;
    ts = 0;
}

void tarjan(int pos)
{
    dfn[pos] = low[pos] = ++ts;
    st.push(pos);
    inst[pos] = 1;

    for (int i = g.header[pos]; i != -1; i = g.item[i].next) {
        int next = g.item[i].dest;
        if (!dfn[next]) {
            tarjan(next);
        } 
        if (!inst[next]) {
            continue;
        }
        low[pos] = min(low[pos], low[next]);
    }

    if (dfn[pos] == low[pos]) {
        while (1) {
            int t = st.top();
            inst[t] = 0;
            st.pop();
            scc[t] = sccnr;
            num[sccnr]++;
            if (t == pos) {
                break;
            }
        }
        sccnr++;
    }
}

void do_tarjan()
{
    for (int i = 0; i < n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
}

void solve()
{
    memset(ans, 0x3f, sizeof(ans));
    memset(counter, 0, sizeof(counter));
    for (int i = 0; i < n; i++) {
        int& a = ans[scc[i]];
        int& c = counter[scc[i]];
        if (cost[i] == a) {
            c++;
        } else if (cost[i] < a) {
            c = 1;
            a = min(a, cost[i]);
        }
    }

    long long res = 0;
    for (int i = 0; i < sccnr; i++) {
        res += ans[i];
    }

    long long tp = 1;
    for (int i = 0; i < sccnr; i++) {
        tp *= counter[i];
        tp %= 1000000007;
    }

    print(res << ' ' << tp);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    g.init();
    tarjan_init();
    input(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", cost + i);
    }
    input(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        --a; --b;
        g.addedge(a, Edge(b, -1));
    }
    do_tarjan();
    solve();
    return 0;
}
