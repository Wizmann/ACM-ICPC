/*
从一个有向图形成一个强连通图所需要增加的边数为： 缩点后的图中入度为0的点数与出度为0的点数的较大值
*/

//Result: Wizmann	1236	Accepted	228K	0MS	C++	1551B

/*
 * tarjan算法学习后练手的题目
 * 先跑一遍tarjan算法,再缩点(即把一个连通分量看成一个点)
 * 入度为0的点的个数即为第一个答案(原因:可以用拓扑排序的思想来理解)
 * 入度和出度为0的个数的较大值为第二个答案(理解:因为总的图不是强连通分量
 * 所以缩点之后可以堪称一棵树,树的叶子和根结点都必须和其他的点相连才能
 * 构成一个连通图)
 * 如果强连通分量的个数为1的话,要注意第二个答案是0,单独考虑
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iostream>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define SIZE 110

using namespace std;
int n;
int g[SIZE][SIZE];
int dfn[SIZE];
char instack[SIZE];
int low[SIZE];
int nr=1;
int sccnr=0;
int scc[SIZE];
int out[SIZE];
int in[SIZE];
stack<int> st;

void tarjan(int pos)
{
	int min;
	min=low[pos]=dfn[pos]=nr++;
	st.push(pos);
	instack[pos]=1;
	for(int i=1;i<=g[pos][0];i++)
	{
		int j=g[pos][i];
		if(!dfn[j])
		{
			tarjan(j);
			low[pos]=min(low[pos],low[j]);
		}
		else if(instack[j])
		{
			low[pos]=min(low[pos],dfn[j]);
		}
	}

	if(dfn[pos]==low[pos])
	{
		sccnr++;
		while(1)
		{
			int t=st.top();
			st.pop();
			instack[t]=0;
			scc[t]=sccnr;
			if(t==pos) break;
		}
	}
}

inline void pb(int a,int b)
{
	g[a][0]++;
	g[a][g[a][0]]=b;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		while(scanf("%d",&a)&&a!=0) pb(i,a);
	}

	for(int i=1;i<=n;i++)
	{
		if(!dfn[i]) tarjan(i);
	}

	for(int i=1;i<=n;i++)
	{
		out[scc[i]]+=g[i][0];
		for(int j=1;j<=g[i][0];j++)
		{
			int k=g[i][j];
			if(scc[i]!=scc[k]) in[scc[k]]++;//缩点，在一个SCC里面的不能算在内
		}
	}

	int inzero=0,outzero=0;
	for(int i=1;i<=sccnr;i++)
	{
		if(!in[i]) inzero++;
		if(!out[i]) outzero++;
	}

	if(sccnr==1) printf("1\n0\n");
	else
	{
		printf("%d\n",inzero);
		printf("%d\n",max(inzero,outzero));
	}
	return 0;
}

