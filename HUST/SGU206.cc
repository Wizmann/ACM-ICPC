//Result:Wizmann	SGU 206	Accepted	1603 KB	31 ms	Visual Studio 8 C++	2386 B

/*问题简述：
 * 给定N个城市和M条道路，其中前N-1条道路是大路，其它都是小路，并保证大路可构成N个城市的生成树。
 * 第i条路费用为ci，要求你谎报费用（设第i条路上报的费用为di），使得对费用数组d来说，N-1条大路恰为最小生成树，并且sum|ci-di|尽可能小。
 */

/* 模型转化
 * 在一个N个点M条边的图中，保证前N-1条边可以构成一棵生成树。
 * 现在你可以修改每条边的边权，要求用最少的修改使得前N-1条边成为最小生成树。
 * (N<=60,M<=400)
 */

/* 设有石子的路为Ci，设泥路为Cj
 * 则我们要使Ci-Xi<=Cj+Xj
 * 这样才能使得到的最小生成树为有石子的路
 *
 * 这样我们得到Ci-Cj<=Xi+Xj
 * Ci-Cj是二分图的边权，而Xi+Xj则是二分图的顶标，我们可以通过二分图匹配来解决这个问题
 */

/*
 * 输入:
 * n,m ==> n个节点，m条边
 * a,b,c ==> m条边的起点终点，双向边，c为边权
 * 编号(1..n-1)的边为大路，编号(n...m)的为小路
 * 
 * 输出：
 * 伪造后的边权
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define N 64
#define M 420
#define INF 1<<28

struct CEdge
{
	int st,end,val;
	CEdge(){}
	CEdge(int ist,int iend,int ival)
	{
		st=ist;end=iend;val=ival;
	}
};

int n,m;
CEdge edge[M];
int mp[N][N];
int lsz,rsz;
int len[M];

/* -------------KM-------------*/
int g[M][M];
char visx[M],visy[M];
int linky[M];
int lx[M],ly[M];
int slack;

bool dfs(int x)
{
	visx[x]=1;
	for(int y=1;y<=rsz;y++)
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
	for(int i=1;i<=lsz;i++)
	{
		for(int j=1;j<=rsz;j++)
		{
			lx[i]=max(lx[i],g[i][j]);
		}
	}
	for(int i=1;i<=lsz;i++)
	{
		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			slack=INF;
			if(dfs(i)) break;
			for(int j=1;j<=lsz;j++)
			{
				if(visx[j]) lx[j]-=slack;
			}
			for(int j=1;j<=rsz;j++)
			{
				if(visy[j]) ly[j]+=slack;
			}
		}
	}
	int res=0;
	for(int i=1;i<=rsz;i++)
	{
		if(linky[i]!=-1)
		{
			res+=lx[linky[i]]+ly[i];
		}
	}
	return res;
}

/* -----------------KM------------------- */

bool dfs(int now,int st,int pre,int id)
{
	if(now==st) return true;
	for(int i=1;i<=n;i++)
	{
		if(i!=pre && mp[now][i])
		{
			if(dfs(i,st,now,id))
			{
				g[mp[now][i]][id-n+1]=edge[mp[now][i]].val-edge[id].val;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	while(input(n>>m))
	{
		memset(g,0,sizeof(g));
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			edge[i]=CEdge(a,b,c);
			if(i<n) mp[a][b]=mp[b][a]=i;
			len[i]=c;
		}
		for(int i=n;i<=m;i++)
		{
			dfs(edge[i].st,edge[i].end,-1,i);
		}
		lsz=n;rsz=max(n,m-n+1);
		km();

		int ptr=1;
		for(int i=1;i<n;i++)
		{
			len[ptr++]-=lx[i];
		}
		for(int i=1;i<=m-n+1;i++)
		{
			len[ptr++]+=ly[i];
		}

		for(int i=1;i<=m;i++)
		{
			printf("%d\n",len[i]);
		}
	}
	return 0;
}
