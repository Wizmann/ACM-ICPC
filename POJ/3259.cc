//Result: wizmann	3259	Accepted	228K	110MS	C++	 1096B	2011-05-01 12:00:17
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 6000
#define SUM 2*m+w

typedef struct path
{
	int st,end,weight;
	
	void setpath(int a,int b,int c)
	{
		st=a;
		end=b;
		weight=c;
	}
}path;

int n,m,w;//点数，路径数，虫洞数
path g[N];
int dis[N];

int bf(int sum)
{
	for(int i=1;i<=n;i++) dis[i]=1<<20;
	dis[1]=0;
	
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(dis[g[j].st]>dis[g[j].end]+g[j].weight) dis[g[j].st]=dis[g[j].end]+g[j].weight;
		}
	}
	
	for(int i=1;i<=sum;i++)
	{
		if(dis[g[i].st]>dis[g[i].end]+g[i].weight) return false;
	}
	return true;
}
	

int main()
{
	int t;
	int a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		int pos=1;
		memset(g,0,sizeof(g));
		memset(dis,0,sizeof(dis));
		scanf("%d%d%d",&n,&m,&w);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[pos++].setpath(a,b,c);
			g[pos++].setpath(b,a,c);
		}
		
		for(int i=0;i<w;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[pos++].setpath(a,b,-c);
		}
		
		if(bf(2*m+w)) puts("NO");
		else puts("YES");
	}
	return 0;
}
