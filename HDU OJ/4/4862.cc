#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int LINE = 11;
const int COL = 11;
const int NODE = LINE * COL * 2;
const int EDGE = NODE * NODE + 123;
const int INF = 0x3f3f3f3f;

struct edge
{
    int dest,flow,next,cost;
    bool crucial;
    edge(){}
    edge(int idest,int iflow,int icost,int inext,bool icrucial=false)
    {
        dest=idest;flow=iflow;
        cost=icost;next=inext;
        crucial=icrucial;
    }
};

edge g[EDGE];
int ind;
int head[NODE],pre[NODE];
int dis[NODE];
char visit[NODE];
char board[LINE][COL];

inline void _addEdge(int st,int end,int flow,int cost,bool crucial)
{
    g[ind]=edge(end,flow,cost,head[st],crucial);
    head[st]=ind++;
    while (ind > EDGE) {};
}

inline void addEdge(int st,int end,int flow,int cost,bool crucial=false)
{
    _addEdge(st,end,flow,cost,crucial);
    _addEdge(end,st,0,-cost,false);
}

void init()
{
    memset(head,-1,sizeof(head));
    ind=0;
}

int spfa(int source,int sink)
{
    queue<int> q;
    memset(dis,INF,sizeof(dis));
    memset(visit,0,sizeof(visit));
    pre[source]=-1;
    q.push(source);
    visit[source]=1;
    dis[source]=0;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        visit[now]=0;
        for(int i=head[now];i!=-1;i=g[i].next)
        {
            int next=g[i].dest;
            int cost=g[i].cost;
            int flow=g[i].flow;

            if(flow>0 && dis[next]>dis[now]+cost)
            {
                dis[next]=dis[now]+cost;
                if(!visit[next])
                {
                    q.push(next);
                    visit[next]=1;
                }
                pre[next]=i;
            }
        }
    }
    return dis[sink];
}

void MinCostMaxFlow(int source,int sink,int &maxflow,int &mincost)
{
    int flow;
    maxflow=0;
    mincost=0;

    while(1)
    {
        int cost=spfa(source,sink);
        if(cost>=INF) break;
        flow=INF;
        int now=sink;
        while(now!=source)
        {
            // printf("%d->", g[pre[now]].dest);
            flow=min(flow,g[pre[now]].flow);
            now=g[pre[now]^1].dest;
        }
        // puts("");
        maxflow+=flow;
        mincost+=flow*cost;
        // print(mincost << ' ' << maxflow);
        now=sink;
        while(now!=source)
        {
            g[pre[now]].flow-=flow;
            g[pre[now]^1].flow+=flow;
            now=g[pre[now]^1].dest;
        }
    }
}

void makeG(int n, int m, int k, int& source, int& sink)
{
    init();

    source = 0;
    int tmp = n * m * 2 + 2;
    sink = n * m * 2 + 3;

    addEdge(source, tmp, k, 0);
    addEdge(tmp, sink, k, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int nr = i * m + j;
            addEdge(tmp, nr * 2 + 1, 1, 0);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int nr = i * m + j;
            addEdge(nr * 2 + 2, sink, 1, 0);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int nr = i * m + j;
            addEdge(nr * 2 + 1, nr * 2 + 2, 1, -9999, true);
        }
    }

    for (int y0 = 0; y0 < n; y0++) {
        for (int x0 = 0; x0 < m; x0++) {
            for (int step = 1; step < max(n, m); step++) {
                if (y0 + step < n) {
                    int y1 = y0 + step;
                    int x1 = x0;

                    int a = board[y0][x0] - '0';
                    int b = board[y1][x1] - '0';
                    int cost = abs(y0 - y1) + abs(x0 - x1) - 1;

                    if (a == b) {
                        cost -= a;
                    }

                    int nr1 = y0 * m + x0;
                    int nr2 = y1 * m + x1;

                    addEdge(nr1 * 2 + 2, nr2 * 2 + 1, 1, cost);
                }

                if (x0 + step < m) {
                    int y1 = y0;
                    int x1 = x0 + step;

                    int a = board[y0][x0] - '0';
                    int b = board[y1][x1] - '0';
                    int cost = abs(y0 - y1) + abs(x0 - x1) - 1;

                    if (a == b) {
                        cost -= a;
                    }

                    int nr1 = y0 * m + x0;
                    int nr2 = y1 * m + x1;

                    addEdge(nr1 * 2 + 2, nr2 * 2 + 1, 1, cost);
                }
            }
        }
    }

}

int main() {
    int T;
    input(T);
    int case_ = 0;
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);

        while (n > LINE) {}
        while (m > COL) {}

        for (int i = 0; i < n; i++) {
            scanf("%s", board[i]);
        }

        int source, sink;
        makeG(n, m, k, source, sink);

        int maxflow, mincost;
        MinCostMaxFlow(source, sink, maxflow, mincost);

        bool flag = true;
        for (int i = 0; i < ind; i++) {
            if (!g[i].crucial) {
                continue;
            }
            if (g[i].flow != 0) {
                flag = false;
            }
        }

        printf("Case %d : ", ++case_);
        if (!flag) {
            puts("-1");
        } else {
            print(-mincost - n * m * 9999);
        }
    }
    return 0;
}
