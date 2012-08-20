#include <cstdio>
#include <cstring>
#include <cstdlib>

#define INF 1<<20

int g[505][505];
char used[505];
int dis[505];
long long ans=0;
int n;

void prim()
{
	for(int i=0;i<n;i++) dis[i]=g[0][i];
	used[0]=1;
	for(int i=0;i<n-1;i++)
	{
		int min=INF;
		int pos=0;
		for(int j=0;j<n;j++)
		{
			if(!used[j]&&dis[j]<min)
			{
				min=dis[j];
				pos=j;
			}
		}
		
		ans+=min;
		used[pos]=1;
		for(int j=0;j<n;j++)
		{
			if(dis[j]>g[j][pos]) dis[j]=g[j][pos];
		}
	}
}
		
		
int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		memset(g,0,sizeof(g));
		memset(dis,0,sizeof(dis));
		memset(used,0,sizeof(used));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&g[i][j]);
				if(!g[i][j]) g[i][j]=INF;
			}
		}
	
		prim();
		printf("%lld\n",ans);
	}
	return 0;
}
