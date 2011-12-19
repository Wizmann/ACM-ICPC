#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define SOURCE 0
#define SINK n+m+1
#define SIZE 100
#define INF INT_MAX

int shop[SIZE][SIZE];
int storge[SIZE][SIZE];
int flow[SIZE][SIZE];
int cost[SIZE<<1][SIZE<<1][SIZE];
int dis[SIZE<<1];
int pre[SIZE<<1];
int good[SIZE];
int m,n,k;
int minc;

void init(int nr)
{
	memset(flow,0,sizeof(flow));
	for(int i=1;i<=n;i++)
	{
		flow[SOURCE][i]=shop[i][nr];
		
		for(int j=n+1;j<SINK;j++)
		{
			flow[i][j]=shop[i][nr];
			flow[j][SINK]=storge[j-n][nr];
		}
	}
}

bool bf(int nr)
{
	memset(pre,-1,sizeof(pre));
	for(int i=SOURCE;i<=SINK;i++) dis[i]=INF;  
    dis[SOURCE]=0; 
    bool flag=true;  
    while(flag)  
    {  
        flag=false;  
        for(int i=SOURCE;i<=SINK;i++)  
        {  
            if(dis[i]==INF) continue;  
            for(int j=SOURCE;j<=SINK;j++)  
            {  
                if(flow[i][j]>0&&cost[i][j][nr]!=INF&&dis[i]+cost[i][j][nr]<dis[j])  
                {  
                    dis[j]=dis[i]+cost[i][j][nr];  
                    pre[j] = i;  
                    flag= true;  
                }  
            }  
        }  
    }  
    return dis[SINK]!=INF;  
}  

bool McMf(int nr)
{
	init(nr);
	int tot=0,maxflow=0;
	
	while(bf(nr))
	{
		int now=SINK,minflow=INF;
		while(now!=SOURCE)
		{
			int p=pre[now];
			minflow=min(minflow,flow[p][now]);
			now=p;
		}
		maxflow+=minflow;
		
		now=SINK;
		while(now!=SOURCE)
		{
			int p=pre[now];
			flow[p][now]-=minflow;
			flow[now][p]+=minflow;
			cost[now][p][nr]=-cost[p][now][nr];
			tot+=minflow*cost[p][now][nr];
			now=p;
		}
	}
	minc+=tot;
	return maxflow==good[nr];
}
		
int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d%d",&n,&m,&k)&&(m+n+k)!=0)
	{
		memset(good,0,sizeof(good));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				scanf("%d",&shop[i][j]);
				good[j]+=shop[i][j];
			}
		}
		
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=k;j++) scanf("%d",&storge[i][j]);
		}
		
		for(int i=1;i<=k;i++)
		{
			for(int j=SOURCE;j<=SINK;j++)
			{
				for(int t=SOURCE;t<=SINK;t++)
				{
					if(j==SOURCE&&t!=SOURCE&&t!=SINK) cost[j][t][i]=0;
					else if(j!=SOURCE && j!=SINK&& t==SINK) cost[j][t][i]=0;
					else cost[j][t][i]=INF;
					
					if(j>SOURCE&&j<=n&&t>=n+1&&t<SINK) scanf("%d",&cost[j][t][i]);
				}
			}
		}
		
		int ans=0;
		bool flag=true;
		for(int i=1;i<=k;i++)
		{
			minc=0;
			if(McMf(i)) ans+=minc;
			else
			{
				flag=false;
				break;
			}
		}
		if(flag) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
				
