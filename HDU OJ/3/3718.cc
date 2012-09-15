//Result:2012-09-14 21:00:39	Accepted	3718	46MS	344K	1865 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10200
#define GROUP 32
#define INF 1<<28

int model[SIZE];
int hash[GROUP];
int g[GROUP][GROUP];
int linky[GROUP],lx[GROUP],ly[GROUP];
int slack;
bitset<GROUP> visx,visy;
int m,n,q;

bool dfs(int x)
{
	visx[x]=1;
	for(int y=1;y<=n;y++)
	{
		if(visy[y]) continue;
		int t=lx[x]+ly[y]-g[x][y];
		if(!t)
		{
			visy[y] = 1;
			if(linky[y]==-1 || dfs(linky[y]))
			{
				linky[y] = x;
				return 1;
			}
		}
		else if(t<slack)  slack=t;
	}
	return 0;
}

int km()
{
	memset(linky,-1,sizeof(linky));
	memset(lx,0,sizeof(lx));
	memset(ly,0,sizeof(ly));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			lx[i]=max(lx[i],g[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		while(1)
		{
			visx.reset();
			visy.reset();
			slack=INF;
			if(dfs(i)) break;
			for(int j=1;j<=n;j++)
			{
				if(visx[j]) lx[j]-=slack;
			}
			for(int j=1;j<=n;j++)
			{
				if(visy[j]) ly[j]+=slack;
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
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
	int T;
	input(T);
	char cmd[5];
	while(T--)
	{
		int sz=1;
		input(m>>n>>q);
		memset(hash,0,sizeof(hash));
		for(int i=0;i<m;i++)
		{
			scanf("%s",cmd);
			if(hash[*cmd-'A']==0) hash[*cmd-'A']=sz++;
			model[i]=hash[*cmd-'A'];
		}
		while(q--)
		{
			sz=1;
			memset(hash,0,sizeof(hash));
			memset(g,0,sizeof(g));
			for(int i=0;i<m;i++)
			{
				scanf("%s",cmd);
				if(hash[*cmd-'A']==0) hash[*cmd-'A']=sz++;
				g[model[i]][hash[*cmd-'A']]++;
			}
			printf("%.4lf\n",(double)km()/m);
		}
	}
	return 0;
}



