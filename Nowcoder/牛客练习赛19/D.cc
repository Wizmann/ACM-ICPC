#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
 
using namespace std;
 
#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 1500
#define EDGE 500000
#define INF 0x3f3f3f3f
 
struct node
{
    int st,end,flow,next;
    node(){}
    node(int ist,int iend,int iflow,int inext)
    {
        st=ist;end=iend;flow=iflow;next=inext;
    }
};
 
node edge[EDGE];
int head[NODE];
int ind;
int source,sink;
 
void addEdge(int s,int e,int f)
{
    edge[ind]=node(s,e,f,head[s]);
    head[s] = ind ++;
     
    edge[ind]=node(e,s,0,head[e]);
    head[e] = ind ++;
}
 
namespace dinic
{
    int level[NODE],curhead[NODE],Que[NODE];
    int estack[4*NODE+4*EDGE],estop;
     
    int BFS()
    {
        memset(level,-1,sizeof(level));
        Que[0]=source;
        level[source]=0;
        for(int fr=0,tail=1;fr!=tail;fr=(fr+1)%NODE)
        {
            int cur=Que[fr];
            for(int e=head[cur];e!=-1;e=edge[e].next)
            {
                int next=edge[e].end;
                if(edge[e].flow && level[next] == -1)
                {
                    Que[tail]=next;
                    level[next]=level[cur]+1;
                    tail=(tail+1)%NODE;
                }
            }
        }
        return level[sink]!=-1;
    }
     
    int DFS()
    {
        int indptr,minf,e;
        int res=0;
        int cur=source;                                                  
        estop=0;
        memcpy(curhead,head,sizeof(head)); 
        while(estop>=0)
        {           
            if(cur==sink)
            {                                     
                minf=INF;
                for(int i=estop-1;i>=0;i--)
                {
                    e=estack[i];
                    if(edge[e].flow<=minf)
                    {
                        minf=edge[e].flow;
                        indptr=i;
                    }
                }
                res+=minf;                                  
 
                for(int i=estop-1;i>=0;i--)
                {              
                    e=estack[i];
                    edge[e].flow-=minf;
                    edge[e^1].flow+=minf;
                }
                estop=indptr;                                   
                cur=edge[estack[estop]].st;         
            }
            for(e=curhead[cur];e!=-1;e=edge[e].next)
            { 
                curhead[cur]=e;
                int next=edge[e].end;
                if(edge[e].flow && level[next]==level[cur]+1)
                {
                    estack[estop++]=e;
                    cur=next;
                    break;
                }
            }
            if(e==-1)
            {                                          
                estop--;
                level[cur]=-2;                                   
                cur=edge[estack[estop]].st;              
            }
        }
        return res;
    }
}
 
void init()
{
    ind=0;
    memset(head,-1,sizeof(head));
}
 
int makeG(int n, int m, int source, int sink)
{
    int sum = 0;
 
    for (int i = 0; i < n; i++) {
        int price;
        scanf("%d", &price);
        sum += price;
        addEdge(m + i + 1, sink, price);
    }
 
    for (int i = 0; i < m; i++) {
        int price;
        scanf("%d", &price);
        addEdge(source, i + 1, price);
    }
 
    for (int i = 0; i < m; i++) {
        int cnt;
        scanf("%d", &cnt);
 
        int u;
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &u);
            addEdge(i + 1, m + u, INF);
        }
    }
    return sum;
}
 
 
int main()
{
    int T;
    input(T);
    while(T--)
    {
        int n, m;
        input(n >> m);
 
        source = 0, sink = n + m + 1;
 
        init();
        int sum = makeG(n, m, source, sink);
 
        int res = 0;
        while(dinic::BFS()) res+=dinic::DFS();
        printf("%d\n",sum - res);
    }
    return 0;
}