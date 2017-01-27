/*
Gold Mines
Time Limit:30000MS     Memory Limit:0KB     64bit IO Format:%lld & %llu

Description

One day, N rogues find a treasure map in accident, so they decide to go along with each other to hunt the treasure in an isolate island. This island can be considered as an undirected graph with V vertexes, each of which is a land.
The edge between two vertexes means there is a road connecting to the correspond lands. After a great effort, these rogues finally find 2 * N lands which contain gold mines. They must divide the lands equally, so each rogue should get two mines. And several additional lands should be assigned to each rogue in order that he can reach one gold mine from the other one by merely passing the lands belonging to him. Being too selfish to share a land with each other, they have quarreled about how to divide the lands for many days.
Being the guardian of this island, you must try your best to protect it. If you manage to make a plan to meet their requirement, the lands which are not assigned to any rogues can be protected. You know there is a price for each land, so you must maximize the sum of price of the lands not assigned.

Input
Input consists of many test cases. The first line is an integer T which is the amount of cases. 
The first line of each case are two integer numbers V and E with 1V500 and 0EV * (V - 1)/2, where V is the amount of lands and E is the amount of roads. 
Next E lines each contains two numbers vi and vj which denotes there is a road between lands vi and vj. 
The next integer is N with 1N4, the amount of rouges. 
Then 2 * N integers follow which denote the 2 * N lands containing gold mines. The last V positive integers are price of all lands. Lands are numbered from 0 to V - 1.

Output
For each test case, print a line containing a single integer which is the maximum price not assigned when the rouges' requirement is met. Print `-1' if no feasible assignment exists.

Sample Input
2 
9 5 
0 1 
2 3 
4 5 
6 7 
7 8 
4 0 1 2 3 4 5 6 7
1 1 1 1 1 1 1 1 1
9 0 
4 0 1 2 3 4 5 6 7
1 1 1 1 1 1 1 1 1

Sample Output
1 
-1
*/


//Result:4766   Gold Mines  Accepted    C++ 4.056   2012-10-13 04:57:14
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
#define NODE 1024
#define EDGE 500000
#define INF 0x3f3f3f3f

struct edge
{
    int dest,flow,next,cost;
    edge(){}
    edge(int idest,int iflow,int icost,int inext)
    {
        dest=idest;flow=iflow;
        cost=icost;next=inext;
    }
};

edge g[EDGE];
int ind;
int head[NODE],pre[NODE];
int dis[NODE];
char visit[NODE];
int n,m;


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

void MinCostMaxFlow(int source,int sink,int &maxflow,int &mincost)
{
    int flow;
    maxflow=0;mincost=0;
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
}

pair<int,int> cnc[NODE*NODE];
int land[NODE],price[NODE];

int check(int x,int K)
{
    int sum=0;
    for(int i=0;i<2*K;i++) sum+=x&(1<<i)?1:0;
    return sum==K;
}

void makeG(int x,int K,int source,int sink)
{
    init();
    for(int i=0;i<m;i++)
    {
        int a=cnc[i].first;
        int b=cnc[i].second;
        addEdge(a*2+1,b*2,INF,0);
        addEdge(b*2+1,a*2,INF,0);
    }
    for(int i=0;i<n;i++)
    {
        addEdge(i*2,i*2+1,1,price[i]);
    }
    for(int i=0;i<K*2;i++)
    {
        if(x&(1<<i)) addEdge(source,land[i]*2,1,0);
        else addEdge(land[i]*2+1,sink,1,0);
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    int T,a,b,K;
    input(T);
    while(T--)
    {
        input(n>>m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            cnc[i]=make_pair(a,b);
        }
        scanf("%d",&K);
        int all4one=0;
        for(int i=0;i<2*K;i++)
        {
            scanf("%d",land+i);
            all4one|=(1<<i);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",price+i);
        }
        int ans=INF;
        int maxflow,mincost;
        int source=2*n+2,sink=2*n+3;
        char ok[1<<8];
        memset(ok,0,sizeof(ok));
        for(int i=0;i<(1<<(2*K));i++)
        {
            if(!ok[i] && !check(i,K)) continue;
            ok[i]=ok[i^all4one]=1;
            makeG(i,K,source,sink);
            MinCostMaxFlow(source,sink,maxflow,mincost);
            if(maxflow==K) ans=min(ans,mincost);
        }
        if(ans>=INF) puts("-1");
        else
        {
            ans=-ans;
            for(int i=0;i<n;i++) ans+=price[i];
            printf("%d\n",ans);
        }
    }
    return 0;
}

