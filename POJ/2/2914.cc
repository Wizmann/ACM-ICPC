//Result:wizmann	2914	Accepted	1716K	4610MS	G++	1257B	2012-09-07 16:32:51
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 512
#define INF 1<<30

int mp[SIZE][SIZE];
int n;
int w[SIZE],c[SIZE];
int sx,tx;

void contract(int x,int y)
{
	for(int i=0;i<n;i++)
	{
		if (i!=x)
		{
			mp[x][i]+=mp[y][i];
			mp[i][x]+=mp[i][y];
		}
	}
	for(int i=y+1;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			mp[i-1][j]=mp[i][j];
			mp[j][i-1]=mp[j][i];
		}
	}
	n--;
}

int mincut()
{
	memset(c,0,sizeof(c));
	c[0]=1;
	for(int i=0;i<n;i++) w[i]=mp[0][i];
	for(int i=1;i+1<n;i++)
	{
		int t=-1,k=-1;
		for(int j=0;j<n;j++)
		{
			if(c[j]==0&&w[j]>k)
			{
				t=j;
				k=w[t];
			}
		}
		sx=t;
		c[sx]=1;
		for(int j=0;j<n;j++) w[j]+=mp[t][j];
	}
	for(int i=0;i<n;i++)
	{
		if(c[i]==0)
		{
			tx=i;
			return w[tx];
		}
	}
	return -1;
}

int main()
{
	freopen("input.txt","r",stdin);
	int i,j,k,m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		memset(mp,0,sizeof(mp));
		while (m--)
		{
			scanf("%d%d%d",&i,&j,&k);
			mp[i][j]+=k;
			mp[j][i]+=k;
		}
		int mint=INF;
		while(n>1)
		{
			k=mincut();
			if (k<mint) mint=k;
			contract(sx,tx);
		}
		printf("%d\n",mint);
	}
	return 0;
}
