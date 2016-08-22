// 题意： 给定一个单向流量网络，允许你在网络中的某些路径增加一共K个单位的流量。问增加之后的流量为多少。
// 输入： n -> 节点个数, K -> 允许增加的流量值， [A] 流量矩阵
// 输出： 增加之后的网络流量

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int NODE = 1024;
const int EDGE = 180000;
const int INF  = 0x3f3f3f3f;

struct edge
{
    int dest, flow, cost, next;
    edge(){}
    edge(int idest, int iflow, int icost, int inext): \
            dest(idest), 
            flow(iflow), 
            cost(icost), 
            next(inext){}
};

edge g[EDGE];
int ind;
int head[NODE],pre[NODE];
int dis[NODE];
char visit[NODE];
int n, K;


inline void _addEdge(int st,int end,int flow,int cost)
{
    g[ind]=edge(end,flow,cost,head[st]);
    head[st]=ind++;
}

inline void addEdge(int st,int end,int flow,int cost)
{
    _addEdge(st,end,flow,cost);
    _addEdge(end,st,0,-cost);
}

void init()
{
    memset(head,-1,sizeof(head));
    ind=0;
}

int spfa(int source,int sink)
{
    queue<int> q;
    memset(dis,0x3f,sizeof(dis));
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

void MinCostMaxFlow(int source, int sink, int &maxflow, int &mincost)
{
    int flow;
    maxflow = 0; mincost = 0;
    while(1)
    {
        int cost = spfa(source, sink);
        if(cost >= INF) break;
        flow = INF;
        int now = sink;
        while(now != source)
        {
            flow = min(flow, g[pre[now]].flow);
            now = g[pre[now] ^ 1].dest;
        }
        
        if (mincost + flow * cost > K) {
            maxflow += (K - mincost) / cost;
            break;
        }
        maxflow += flow;
        mincost += flow * cost;
        now     =  sink;
        while(now != source)
        {
            g[pre[now]].flow     -= flow;
            g[pre[now] ^ 1].flow += flow;
            now = g[pre[now] ^ 1].dest;
        }
    }
}

int main()
{
    freopen("input.txt","r", stdin);
    int a;
    input(n >> K);
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            input(a);
            if (a) {
                addEdge(i, j, a, 0);
                addEdge(i, j, K, 1);
            }
        }
    }
    int flow, cost;
    MinCostMaxFlow(1, n, flow, cost);
    print(flow);
    return 0;
}
