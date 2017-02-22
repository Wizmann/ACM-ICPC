//Result:wizmann    3463    Accepted    1084K   94MS    G++ 2292B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define SIZE 1001
#define INF 1<<20

typedef struct edge
{
    int v,w,next;
    inline void setedge(int a,int b,int c){v=a;w=b;next=c;}
}edge;

int n,m;//The number of cities, the number of roads
int num;//The number of the edge
int preb[SIZE];//preb[u] -> The last edge who is begin from u
int s,t;//The begin point und the end point
char visit[SIZE][2];
edge g[SIZE<<5];
int cnt[SIZE][2],dis[SIZE][2];
//The shortest path and the 2th shortest path

void dijkstra()
{
    int u=-1,flag=-1;

    memset(visit,0,sizeof(visit));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<=n;i++) dis[i][0]=dis[i][1]=INF;

    cnt[s][0]=1;
    dis[s][0]=0;
    //For the point "START",there is one shortest path -> 0

    for(int i=1;i<2*n;i++)
    {
        int minn=INF;
        for(int j=1;j<=n;j++)
        {
            if(!visit[j][0] && dis[j][0]<minn)
            {
                u=j;flag=0;minn=dis[j][0];
            }
            else if(!visit[j][1] && dis[j][1]<minn)
            {
                u=j;flag=1;minn=dis[j][1];
            }
        }
        //找出距离所有点中的最短路径（包括最短和次短）

        if(minn>=INF) break;
        //如果不能找到如上的点，则查找结束
        visit[u][flag]=1;//标记已查找
        for(int j=preb[u];j!=-1;j=g[j].next)
        {
            //遍历u的子节点
            int w=g[j].w;
            int v=g[j].v;
            
            //先测试最短路，如果最短路可更新，则更新最短路
            //否则更新次短路
            if(dis[v][0]>minn+w)
            {
                dis[v][1]=dis[v][0];
                cnt[v][1]=cnt[v][0];
                dis[v][0]=minn+w;
                cnt[v][0]=cnt[u][flag];
            }
            else if(dis[v][0]==minn+w) cnt[v][0]+=cnt[u][flag];
            //DP思想，此节点的最（次）短路数目等于上一节点的最（次）短路数目
            else if(dis[v][1]>minn+w)
            {
                dis[v][1]=minn+w;
                cnt[v][1]=cnt[u][flag];
            }
            else if(dis[v][1]==minn+w) cnt[v][1]+=cnt[u][flag];
        }
    }
    //printf("T:%d %d\n",cnt[t][0],cnt[t][1]);
    if(dis[t][1]==dis[t][0]+1) cnt[t][0]+=cnt[t][1];
    printf("%d\n",cnt[t][0]);
}


int main()
{
    freopen("input.txt","r",stdin);
    int cas;
    int a,b,c;
    scanf("%d",&cas);
    while(cas--)
    {
        num=0;
        memset(g,0,sizeof(g));
        scanf("%d%d",&n,&m);
        memset(preb,-1,sizeof(preb));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            
            g[num].setedge(b,c,preb[a]);
            preb[a]=num++;
        }
        scanf("%d%d",&s,&t);
        dijkstra();
    }
    return 0;
}

