//Result:wizmann	3686	Accepted	896K	79MS	C++	1656B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 54
#define INF 1<<28

int g[SIZE][SIZE*SIZE];
int fac[SIZE][SIZE];
int n,m;
char visx[SIZE],visy[SIZE*SIZE];
int linky[SIZE*SIZE];
int lx[SIZE],ly[SIZE*SIZE];
int slack;

void makeG()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				g[i][j*n+k]=-(fac[i][j]*(k+1));
			}
		}
	}
}

bool dfs(int x)
{
	visx[x]=1;
	for(int y=0;y<m*n;y++)
	{
		if(visy[y]) continue;
		int t=lx[x]+ly[y]-g[x][y];
		if(!t)
		{
			visy[y]=1;
			if(linky[y]==-1 || dfs(linky[y]))
			{
				linky[y]=x;
				return 1;
			}
		}
		else if(t<slack) slack=t;
	}
	return 0;
}

int km()
{
	memset(linky,-1,sizeof(linky));
	memset(lx,0,sizeof(lx));
	memset(ly,0,sizeof(ly));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m*n;j++)
		{
			lx[i]=max(lx[i],g[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			slack=INF;
			if(dfs(i)) break;
			for(int j=0;j<n;j++)
			{
				if(visx[j]) lx[j]-=slack;
			}
			for(int j=0;j<n*m;j++)
			{
				if(visy[j]) ly[j]+=slack;
			}
		}
	}
	int res=0;
	for(int i=0;i<n*m;i++)
	{
		if(linky[i]!=-1)
		{
			res+=lx[linky[i]]+ly[i];
		}
	}
	return res;
}


int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		input(n>>m);
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&fac[i][j]);
			}
		}
		makeG();
		int ans=-km();
		printf("%.6f\n",(double)ans/n);
	}
	return 0;
}
