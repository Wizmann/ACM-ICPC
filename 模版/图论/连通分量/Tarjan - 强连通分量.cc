/*
1. 从一个有向图形成一个强连通图所需要增加的边数为： 缩点后的图中入度为0的点数与出度为0的点数的较大值
2. 验证在有向图中是否存在两点A、B，使AB一定能连通（A->B或B->A）。
   先将图中的强连通分量缩为一点，重新建图，然后Topsort。如果Topsort的**序列唯一**，则必符合性质。
3. 一个点双连通分量可以形成一个环的结构
   通过Tarjan算法可以得到双连通分量
   若连通分量中(边数)>(点数)，则环内有环
   若(点数)>(边数)，则不能成环
   若(点数)==(边数)，则成一个标准的环
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

char instack[SIZE];//是否在栈中
int low[SIZE];//所有节点的最小标号
int nr=1;//时间编号
stack<int> st;
int dfn[SIZE];//时间戳
int scc[SIZE];//标明每一个点属于哪个SCC中
int num[SIZE];//每一个SCC中包含多少元素
int sccnr=0;//强连通分量编号

int ind=0;//临接链表指针

//时间复杂度O(n+m)

inline void add_edge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind;
	ind++;
}

void init(bool all=true)
{
	if(all)//是否清空原图
	{
		memset(head,-1,sizeof(head));
		memset(g,0,sizeof(g));
		ind=0;
	}
	instack.reset();
	memset(dfn,0,sizeof(dfn));
	memset(scc,0,sizeof(scc));
	memset(num,0,sizeof(num));
	memset(low,0,sizeof(low));
	while(!st.empty()) st.pop();
	nr=1;sccnr=0;
}

void tarjan(int pos)
{
	low[pos]=dfn[pos]=nr++;
	st.push(pos);
	instack[pos]=1;

	for(int i=head[pos];i!=-1;i=g[i].next)
	{
		int j=g[i].v;
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
			instack[t]=0;
			st.pop();
			scc[t]=sccnr;
			num[sccnr]++;
			if(t==pos) break;
		}
	}
}

int main()
{
	/* ... */
	/* ... */
	
	init();
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		add_edge(a,b);
	}//建图

	//执行Tarjan算法
	for(int i=0;i<n;i++)
	{
		if(!dfn[i]) tarjan(i);
	}
	
	//scc[i]表示编号为i的点属于哪个scc
	//num[i]表示编号为i的scc有几个点，scc的编号从1开始
	
	/* ... */
	/* ... */
	
	return 0;
}
