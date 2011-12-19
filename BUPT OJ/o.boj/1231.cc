#include <stdio.h>
#include <string.h>

#define N 1050
#define INF 1<<14

char flag[N];
int g[N][N];
int dis[N];
int n;

void dij(int pos);

int main()
{
	
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d%d",&n,&t);
	
	//Init
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) g[i][j]=INF;
		g[i][i]=0;
	}
	
	int a,b,l;
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&l);
		if(g[a][b]>l)
		{
			g[a][b]=l;
			g[b][a]=l;
		}
	}
	
	int des,to;
	scanf("%d%d",&des,&to);
	
	dij(to);
	printf("%d\n",dis[des]);
	return 0;
}

void dij(int pos)
{
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;i++) dis[i]=g[i][pos];
	
	flag[pos]=1;
	dis[pos]=0;
	
	for(int i=1;i<=n-1;i++)
	{
		int das=pos;
		int min=INF;
		for(int j=1;j<=n;j++)
		{
			if(!flag[j]&&dis[j]<min)
			{
				das=j;
				min=dis[j];
			}
		}
		
		flag[das]=1;
		for(int j=1;j<=n;j++)
		{
			if(!flag[j]&& g[das][j]<INF && dis[j]>dis[das]+g[das][j])
			{
				dis[j]=dis[das]+g[das][j];
			}
		}
	}
	
}