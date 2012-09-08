//Result:2012-09-07 16:21:35	Accepted	3691	703MS	700K	1339 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 320
#define INF 1<<28

int mp[SIZE][SIZE],w[SIZE],c[SIZE];
int n,sx,tx;

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

int SW()
{
	int ans=INF;
	while(n>1)
	{
		int mc=mincut();
		ans=min(ans,mc);
		contract(sx,tx);
	}
	return ans;
}


int main()
{
	freopen("input.txt","r",stdin);
	int m,st;
	int a,b,c;
	while(input(n>>m>>st) && n+m+st)
	{
		memset(mp,0,sizeof(mp));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			mp[a-1][b-1]+=c;
			mp[b-1][a-1]+=c;
		}
		printf("%d\n",SW());
	}
	return 0;
}




