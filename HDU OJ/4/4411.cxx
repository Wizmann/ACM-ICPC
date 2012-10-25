/*

**诱导**，最小费用最大流

把必须通过的点拆为两个，中间加上一个已经的最小值，则流一定会通过这个点

Arrest
Time Limit: 1000MS 		Memory Limit: 32768KB

Description
There are (N+1) cities on TAT island. City 0 is where police headquarter located. The economy of other cities numbered from 1 to N ruined these years because they are all controlled by mafia. The police plan to catch all the mafia gangs in these N cities all over the year, and they want to succeed in a single mission. They figure out that every city except city 0 lives a mafia gang, and these gangs have a simple urgent message network: if the gang in city i (i>1) is captured, it will send an urgent message to the gang in city i-1 and the gang in city i -1 will get the message immediately.
The mission must be carried out very carefully. Once a gang received an urgent message, the mission will be claimed failed.
You are given the map of TAT island which is an undirected graph. The node on the graph represents a city, and the weighted edge represents a road between two cities(the weight means the length). Police headquarter has sent k squads to arrest all the mafia gangs in the rest N cities. When a squad passes a city, it can choose to arrest the gang in the city or to do nothing. These squads should return to city 0 after the arrest mission.
You should ensure the mission to be successful, and then minimize the total length of these squads traveled.
 

Input
There are multiple test cases.
Each test case begins with a line with three integers N, M and k, here M is the number of roads among N+1 cities. Then, there are M lines. Each of these lines contains three integers X, Y, Len, which represents a Len kilometer road between city X and city Y. Those cities including city 0 are connected.
The input is ended by “0 0 0”.
Restrictions: 1 ≤ N ≤ 100, 1 ≤ M ≤ 4000, 1 ≤ k ≤ 25, 0 ≤ Len ≤ 1000
 

Output
For each test case,output a single line with a single integer that represents the minimum total length of these squads traveled.
 

Sample Input

3 4 2 
0 1 3 
0 2 4 
1 3 2 
2 3 2 
0 0 0

Sample Output

14

*/

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
            addEdge(2*i,2*i+1,1,-GAP);//把必须通过的点拆为两个，中间加上一个已经的最小值，则流一定会通过这个点
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
