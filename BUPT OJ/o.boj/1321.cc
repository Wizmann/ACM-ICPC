#include <cstdio>
#include <cstring>

#define N 1010
#define INF 1<<14

int n;

int path[N][N];
int dis[N];
bool flag[N];

void dijkstra()
{
	memset(flag,false,sizeof(flag));
	for(int i=1;i<=n;i++) dis[i]=path[i][n];
	
	flag[n]=true;
	dis[n]=0;
	
	for(int i=0;i<n-1;i++)
	{
		int min=INF;
		int die=n;
		
		for(int j=1;j<=n;j++)
		{
			if(!flag[j]&&dis[j]<min)
			{
				min=dis[j];
				die=j;
			}
		}
		flag[die]=true;
		
		for(int j=1;j<=n;j++)
		{
			if(!flag[j] && path[die][j]<INF && dis[j]>dis[die]+path[die][j])
			{
				dis[j]=dis[die]+path[die][j];
			}
		}
	}
}			
		


int main()
{
	
	freopen("input.txt","r",stdin);
	
	int t;
	scanf("%d%d",&t,&n);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) path[i][j]=INF;
	}
	
	for(int i=1;i<=n;i++) path[i][i]=0;
		
	int a,b,l;
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&l);
		if(path[a][b]>l)
		{
			path[a][b]=l;
			path[b][a]=l;
		}
	}
	
	dijkstra();
	printf("%d\n",dis[1]);
	
	return 0;
}
	
	
	
	
		
