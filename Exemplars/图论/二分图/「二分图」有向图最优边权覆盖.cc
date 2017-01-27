/*
K-path cover
Time Limit: 10000MS		Memory Limit: Unknown

Description
Problem

K-path cover of a directed graph is a set of exactly k of its edges chosen in such way that every two of them have different start vertices and every two of them have different end vertices. Assuming that for each vertex we know its cost we can define cost of the edge as a sum of costs of its start and end. We can also define cost of a k-path cover as a sum of costs of its edges. Your task is to find cheapest k-path cover for given directed graph with known costs of the vertices.

Input

First line of input contains number of test cases c (1<=c<=20). Each test case begins with k, number of vertices n and number of edges m (1<=k<=100, 1<=n<=10000, 0<=m<=1000000). Next n lines contain costs of the vertices, each of them is an integer from [-100000,100000]. Then m lines describing edges follow, each of them containing exactly two numbers representing its start and end vertices. Vertices are numbered from 1 to n.

Output

For each test case output cost of the cheapest k-path cover. When given graph has no k-path cover output NONE.

Example

Input:
1
4 6 9
5
4
6
10
2
3
1 2
1 4
2 4
3 2
4 3
5 4
6 3
5 6
6 5

Output:
33
*/

/*
【题目大意】
有n个点，m条有向边，这m条有向边的权值w=cost[x]+cost[y]，求k条边满足：
1、这k条边之间没有共起点和共终点的
2、这k条边的权和最小
【算法分析】
容易建图：
将n个点每个点拆成(i,i')
然后对于有向边(x,y)，连边(x,y')，该边权为cost[x]+cost[y]
于是相当于对这个二分图，求k次最小费用流的增广。
然后由于m太大，我们需要更快的算法。
对于观察每次增广，实际上就是匈牙利算法中的找交错轨，
并且新增的权总为增广路中的cost[起点]+cost[终点]
然后我们可以利用这个性质，将cost排序，然后有：当终点一样的情况下，让前面的先匹配比较好。
所以一个点只用进去一次就可以了。
最后就是每次枚举从某一点出发找增广路，找出本次增广增加的费用最小的。
然后去实现这个增广即可。
【其它】
时间复杂度O(k*(n+m))
*/

/* Result
 * 2012-09-30 16:43:20
 * Moody Wizmann	K-path cover
 * accepted	1.19 	3.2M	C++ 4.3.2
 */
 
 
/* 给出你N个点，以及这N个点连成的M条有向边。
 * 边权是边上的两个点的点权的和
 * 让你找出k条边，使没有两条边的起点与终点相同，并使其边权最小
 * 
 * 
 * 
 * (1<=k<=100, 1<=n<=10000, 0<=m<=1000000)
 */
 

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 12800
#define INF 0x3f3f3f3f

struct node
{
	int nr,val;
	node(){}
	node(int inr,int ival)
	{
		nr=inr;val=ival;
	}
	friend bool operator < (const node& a,const node& b)
	{
		return a.val<b.val;
	}
};

vector<int> g[SIZE];
node sc[SIZE];
int n,m,kk;
int anti[SIZE];
char visit[SIZE];
int pre[SIZE];
int lx[SIZE],ly[SIZE];

int slove()
{
	int tk=0;//Toni Kroos
	int from,to,mincost;
	memset(lx,-1,sizeof(lx));
	memset(ly,-1,sizeof(ly));
	while(tk<kk)
	{
		queue<int> q;
		memset(visit,0,sizeof(visit));
		mincost=INF;
		to=-1;
		
		for(int i=0;i<n;i++)
		{
			if(lx[i]==-1)
			{
				q.push(i);
				while(!q.empty())
				{
					int now=q.front();
					q.pop();
					for(int j=0;j<(int)g[now].size();j++)
					{
						int next=g[now][j];
						if(!visit[next])
						{
							visit[next]=1;
							pre[next]=now;
							if(ly[next]==-1)
							{
								if(sc[i].val+sc[next].val<mincost)
								{
									mincost=sc[i].val+sc[next].val;
									to=next;
									from=i;
								}
							}
							else q.push(ly[next]);
						}
					}
				}
			}
		}
		if(to!=-1)
		{
			tk++;
			while(1)
			{
				int v=to;
				int u=pre[to];
				to=lx[u];
				ly[v]=u;lx[u]=v;
				if(u==from) break;
			}
		}
		else break;
	}
	if(tk<kk) return -1;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(lx[i]!=-1) sum+=sc[i].val+sc[lx[i]].val;
	}
	return sum;
}


int main()
{
	int T,a,b;
	input(T);
	while(T--)
	{
		for(int i=0;i<SIZE;i++) g[i].clear();
		input(kk>>n>>m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			sc[i]=node(i+1,a);
		}
		sort(sc,sc+n);
		for(int i=0;i<n;i++)
		{
			anti[sc[i].nr]=i;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			g[anti[a]].push_back(anti[b]);
		}
		int ans=slove();
		if(ans==-1) puts("NONE");
		else print(ans);
	}
	return 0;
}
