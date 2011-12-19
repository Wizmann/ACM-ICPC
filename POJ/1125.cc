#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 110
#define INF 1<<20

int g[N][N];

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	while(scanf("%d",&n),n)
	{
		memset(g,0,sizeof(g));
		int num,a,b;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num);
			for(int j=1;j<=num;j++)
			{
				scanf("%d%d",&a,&b);
				g[i][a]=b;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(g[i][j]==0) g[i][j]=INF;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(g[j][k]>g[j][i]+g[i][k]) g[j][k]=g[j][i]+g[i][k];	
				}
			}
		}
		
		int ans=1<<20;
		int person;
		for(int i=1;i<=n;i++)
		{
			int max=-1;
			for(int j=1;j<=n;j++)
			{
				if(i!=j&&g[i][j]>max) max=g[i][j];
			}
			//printf("%d\n",max);
			if(ans>max)
			{
				ans=max;
				person=i;
			}
		}
		
		if(ans>=1<<20) puts("disjoint");
		else printf("%d %d\n",person,ans);
	}
	return 0;
}
