/*
Roads
Time Limit: 1000MS		Memory Limit: 65536KB

Description
The kingdom of Farland has N cities connected by M roads. Some roads are paved with stones, others are just country roads. Since paving the road is quite expensive, the roads to be paved were chosen in such a way that for any two cities there is exactly one way to get from one city to another passing only the stoned roads. 

The kingdom has a very strong bureaucracy so each road has its own ordinal number ranging from 1 to M: the stoned roads have numbers from 1 to N-1 and other roads have numbers from N to M. Each road requires some money for support, i-th road requires ci coins per year to keep it intact. Recently the king has decided to save some money and keep financing only some roads. Since he wants his people to be able to get from any city to any other, he decided to keep supporting some roads in such a way, that there is still a path between any two cities. 

It might seem to you that keeping the stoned roads would be the good idea, however the king did not think so. Since he did not like to travel, he did not know the difference between traveling by a stoned road and travelling by a muddy road. Thus he ordered you to bring him the costs of maintaining the roads so that he could order his wizard to choose the roads to keep in such a way that the total cost of maintaining them would be minimal. 

Being the minister of communications of Farland, you want to help your people to keep the stoned roads. To do this you want to fake the costs of maintaining the roads in your report to the king. That is, you want to provide for each road the fake cost of its maintaining di in such a way, that stoned roads form the set of roads the king would keep. However, to lower the chance of being caught, you want the value of sum(i = 1..M, |ci-di|) to be as small as possible. 

You know that the king's wizard is not a complete fool, so if there is the way to choose the minimal set of roads to be the set of the stoned roads, he would do it, so ties are allowed. 
Input
The first line of the input file contains N and M (2 ≤ N ≤ 60, N-1 ≤ M ≤ 400). Next M lines contain three integer numbers ai, bi and ci each — the numbers of the cities the road connects (1 ≤ ai ≤ N, 1 ≤ bi ≤ N, ai ≠ bi) and the cost of maintaining it (1 ≤ ci ≤ 10 000). 
Output
Output M lines — for each road output di that should be reported to be its maintainance cost so that he king would choose first N-1 roads to be the roads to keep and the specified sum is minimal possible. 
Sample Input

Input
4 5 
4 1 7 
2 1 5 
3 4 4 
4 2 5 
1 3 1 

Output
4 
5 
4 
5 
4 
*/

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
