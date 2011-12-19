//现在要求出从S到T有多少条最短路线，要求每个点只能通过一次（S和T）除外(即任意两条最短路径之间不存在除s，t外的公共点)
//最小费用最大流
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define START 0
#define END n+1
#define SOURCE n+2
#define SINK n+3
#define INF 0x3ffffff
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SIZE 255

int cost[SIZE][SIZE];
int flow[SIZE][SIZE];
int dis[SIZE],pre[SIZE];
int n,sp;

int bellman_ford()
{
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<=SINK;i++) dis[i]=INF;
	dis[SOURCE]=0;
	bool flag=true;
	while(flag)
	{
		flag=false;
		for(int i=0;i<=SINK;i++)
		{
			if(dis[i]>=INF) continue;
			else 
			{
				for(int j=0;j<=SINK;j++)
				{
					if(flow[i][j]&&dis[i]+cost[i][j]<dis[j])
					{
						dis[j]=dis[i]+cost[i][j];
						pre[j]=i;
						flag=true;
					}
				}
			}
		}
	}
	return dis[SINK];
}


int mcmf()
{
	int now,c=0,minflow=INF;
	while(1)
	{
		int len=bellman_ford();
		if(sp==-1||sp==len){c++;sp=len;}
		else break;
		
		if(len>=INF) break;
		now=SINK;
		while(now!=SOURCE)
		{
			int p=pre[now];
			minflow=min(minflow,flow[p][now]);
			now=p;
		}
		now=SINK;
		while(now!=SOURCE)
		{
			int p=pre[now];
			flow[p][now]-=minflow;
			flow[now][p]+=minflow;
			cost[now][p]=-cost[p][now];
			now=p;
		}
	}
	return c;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	while(scanf("%d",&n),n)
	{
		sp=-1;
		memset(flow,0,sizeof(flow));
		for(int i=0;i<=SINK;i++)
		{
			for(int j=0;j<=SINK;j++) cost[i][j]=INF;
		}

		int t;
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(cost[a][b]) cost[a][b]=min(cost[a][b],c);
			else cost[a][b]=c;
			cost[b][a]=-cost[a][b];
			flow[a][b]=1;
		}
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d%d",&a,&b);
			if(cost[START][a]) cost[START][a]=min(cost[START][a],b);
			else cost[START][a]=b;
			flow[START][a]=1;
		}
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d%d",&a,&b);
			if(cost[a][END]) cost[a][END]=min(cost[a][END],b);
			else cost[a][END]=b;
			flow[a][END]=1;
		}
		cost[SOURCE][START]=0;
		flow[SOURCE][START]=INF;
		cost[END][SINK]=0;
		flow[END][SINK]=INF;

		
		printf("%d\n",mcmf());
	}
	return 0;
}

