//Result:Accepted	16096K	782MS	G++	 1134B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIZE 2005
#define LEN 7

int g[SIZE][SIZE];
char used[SIZE];
int dis[SIZE];
long long ans;
int n;
char type[SIZE][10];

inline void init()
{
	memset(g,0,sizeof(g));
	memset(used,0,sizeof(used));
	memset(dis,0,sizeof(dis));
	memset(type,0,sizeof(type));
	ans=0;
}

void dij()
{
	for(int i=0;i<n;i++) dis[i]=g[0][i];
	used[0]=1;// ~>_<~
	
	for(int i=0;i<n-1;i++)
	{
		int min=1<<20;
		int pos;
		
		for(int i=0;i<n;i++)
		{
			if(!used[i]&&dis[i]<min)
			{
				min=dis[i];
				pos=i;
			}
		}
		ans+=min;
		used[pos]=1;
		
		for(int i=0;i<n;i++)
		{
			if(g[pos][i]<dis[i]) dis[i]=g[pos][i];
		}
	}
}		

int main()
{
	freopen("b.txt","r",stdin);
	while(scanf("%d",&n),n)
	{
		init();
		for(int i=0;i<n;i++) scanf("%s",type[i]);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int t=0;
				for(int k=0;k<LEN;k++)
				{
					if(type[i][k]!=type[j][k]) t++;
				}
				if(i!=j) g[i][j]=g[j][i]=t;
				else g[i][j]=1<<20;
			}
		}
		
		dij();
		printf("The highest possible quality is 1/%lld.\n",ans);
	}
	return 0;
}
	
