#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int g[110][110];
int p[110];
int price[110];
int n,m;
char used[110];
char r[110];

void dij()
{
	for(int i=1;i<=n;i++) price[i]=g[n+1][i];
	memset(used,0,sizeof(used));
	
	for(int i=1;i<=n;i++)
	{
		int pos=-1;
		int min=1<<20;
			
		for(int j=1;j<=n;j++)
		{
			if(r[j]&&!used[j]&&price[j]<min)
			{
				min=price[j];
				pos=j;
			}
		}
		if(pos==-1) return;
		else used[pos]=1;
		for(int j=1;j<=n;j++)
		{
			if(!used[j]&&r[j]&&price[j]>price[pos]+g[pos][j])
			{
				price[j]=price[pos]+g[pos][j];
			}
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	
	int t,b,dis;
	int ans=1<<20;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",price+i,p+i);
		scanf("%d",&t);
		g[n+1][i]=*(price+i);
		while(t--)
		{
			scanf("%d%d",&b,&dis);
			g[b][i]=dis;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(g[i][j]==0) g[i][j]=1<<20;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		int dmax=p[i],dmin=p[i]-m;
		memset(r,0,sizeof(r));
		for(int j=1;j<=n;j++)
		{
			if(abs(dmax-p[j])<=m&&abs(dmin-p[j])<=m) r[j]=1;
		}
		dij();
		if(price[1]<ans) ans=price[1];
		
		//printf("%d\n",price[1]);
	}
		
	printf("%d\n",ans);
	return 0;
}
