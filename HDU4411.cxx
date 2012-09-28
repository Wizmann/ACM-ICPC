//Result:2012-09-24 15:38:33	Accepted	4411	78MS	752K	3422 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 256
#define EDGE 20000
#define SIZE 128


const int INF=1<<28;
const int GAP=1<<23;

struct edge
{
    int dest,flow,next;
    int cost;
    edge(){}
    edge(int idest,int iflow,int icost,int inext)
    {
        dest=idest;
        flow=iflow;
        cost=icost;
        next=inext;
    }
};

edge g[EDGE];
int ind,n,m,team;
int head[NODE];
int pre[NODE];

void _addEdge(int u,int v,int flow,int cost)
{
    g[ind]=edge(v,flow,cost,head[u]);
    head[u]=ind++;
}

void addEdge(int u,int v,int flow,int cost)
{
    _addEdge(u,v,flow,cost);
    _addEdge(v,u,0,-cost);
}

void init()
{
    memset(head,-1,sizeof(head));
    ind=0;
}

int spfa(int source,int sink)
{
    queue<int> q;
    int dis[NODE];
    char visit[NODE]={0};
    fill(dis,dis+NODE,INF);
    dis[source]=0;
    q.push(source);
    pre[source]=-1;
    visit[source]=1;
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

int MinCostMaxFlow(int source,int sink)
{
    int flow;
    int maxflow=0;
    int mincost=0;

    while(1)
    {
        int cost=spfa(source,sink);
        if(cost>=INF) break;
        flow=INF;
        int now=sink;
        while(now!=source)
        {
            flow=min(flow,g[pre[now]].flow);
            now=g[pre[now]^1].dest;
        }
        maxflow+=flow;
        mincost+=flow*cost;
        now=sink;
        while(now!=source)
        {
            g[pre[now]].flow-=flow;
            g[pre[now]^1].flow+=flow;
            now=g[pre[now]^1].dest;
        }
    }
    return mincost;
}

int main()
{
    int a,b,c;
    int g[SIZE][SIZE];
    while(input(n>>m>>team) && n+m+team)
    {
        init();
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++) g[i][j]=INF;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            g[a][b]=g[b][a]=min(g[a][b],c);
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
                }
            }
        }
        addEdge(0,1,team,0);
        addEdge(1,2*n+2,team,0);
        for(int i=1;i<=n;i++)
        {
            addEdge(1,2*i,1,g[i][0]);
            addEdge(2*i,2*i+1,1,-GAP);
            addEdge(i*2+1,2*n+2,1,g[i][0]);
            for(int j=i+1;j<=n;j++)
            {
                addEdge(i*2+1,j*2,1,g[i][j]);
            }
        }
        print(MinCostMaxFlow(0,2*n+2)+n*GAP);
    }
    return 0;
}
