//Result:2012-09-15 19:19:05	Accepted	3722	93MS	960K	1747 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 256
#define LEN 1024

const int INF=1<<28;

int n;
char str[SIZE][LEN];
int sz[SIZE];
int g[SIZE][SIZE];
int lx[SIZE],ly[SIZE];
int linky[SIZE];
bitset<SIZE> visx,visy;
int slack;

int getScore(int a,int b)
{
	int p=0,q=sz[b]-1;
	int res=0;
	while(p<sz[a] && q>=0 && str[a][p]==str[b][q])
	{
		p++;q--;res++;
	}
	return res;
}

bool dfs(int x)
{
	visx[x]=1;
	for(int y=0;y<n;y++)
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
		for(int j=0;j<n;j++)
		{
			lx[i]=max(lx[i],g[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			visx.reset();
			visy.reset();
			slack=INF;
			if(dfs(i)) break;
			for(int j=0;j<n;j++)
			{
				if(visx[j]) lx[j]-=slack;
			}
			for(int j=0;j<n;j++)
			{
				if(visy[j]) ly[j]+=slack;
			}
		}
	}
	int res=0;
	for(int i=0;i<n;i++)
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
	freopen("input.txt","r",stdin);
	while(input(n))
	{
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			scanf("%s",str[i]);
			sz[i]=strlen(str[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) if(i!=j)
			{
				g[i][j]=getScore(i,j);
			}
		}
		print(km());
	}
	return 0;
}

