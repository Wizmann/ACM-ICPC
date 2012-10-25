/*
Bob’s Race

Time Limit: 5000/2000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)

Problem Description
Bob wants to hold a race to encourage people to do sports. He has got trouble in choosing the route. There are N houses and N - 1 roads in his village. Each road connects two houses, and all houses are connected together. To make the race more interesting, he requires that every participant must start from a different house and run AS FAR AS POSSIBLE without passing a road more than once. The distance difference between the one who runs the longest distance and the one who runs the shortest distance is called “race difference” by Bob. Bob does not want the “race difference”to be more than Q. The houses are numbered from 1 to N. Bob wants that the No. of all starting house must be consecutive. He is now asking you for help. He wants to know the maximum number of starting houses he can choose, by other words, the maximum number of people who can take part in his race.
 

Input
There are several test cases.
The first line of each test case contains two integers N and M. N is the number of houses, M is the number of queries.
The following N-1 lines, each contains three integers, x, y and z, indicating that there is a road of length z connecting house x and house y.
The following M lines are the queries. Each line contains an integer Q, asking that at most how many people can take part in Bob’s race according to the above mentioned rules and under the condition that the“race difference”is no more than Q. 

The input ends with N = 0 and M = 0.

(N<=50000 M<=500 1<=x,y<=N 0<=z<=5000 Q<=10000000)
 

Output
For each test case, you should output the answer in a line for each query.
 

Sample Input
5 5
1 2 3
2 3 4
4 5 3
3 4 2
1
2
3
4
5
0 0
 

Sample Output
1
3
3
3
5
*/

/*
给出一个N个点的带权树(N <= 50000)。每个点到任意叶子节点的最长距离记为Di。询问M < 300 次，对每次询问，找到长度最大的区间[l,r]，使得Di(l<=i<=r)的最大值和最小值的差不超过Q。
*/


//Result:2012-10-05 18:41:24	Accepted	4123	1093MS	9812K	2733 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define N 50010
#define M 100010

struct CEdge
{
	int u,v,cost,next;
	int maxdis;

	CEdge(){}
	CEdge(int iu,int iv,int icost,int inext)
	{
		u=iu;v=iv;cost=icost;next=inext;
		maxdis=-1;
	}
};

CEdge edge[M];
int dis[N];
int ind;
int head[N];
int n,m;

namespace RMQ
{
	enum{RMQSIZE=17};
	int mini[N][RMQSIZE],maxi[N][RMQSIZE];
	int pow2[RMQSIZE];
	int tolog2[1<<RMQSIZE];
	
	int log2(int x)
	{
		return upper_bound(pow2,pow2+RMQSIZE,x)-pow2-1;
	}
	inline void init_pow()
	{
		for(int i=0;i<RMQSIZE;i++) pow2[i]=1<<i;
		for(int i=0;i<(1<<RMQSIZE);i++)
		{
			tolog2[i]=log2(i);
		}
	}
	inline void init()
	{
		memset(mini,0,sizeof(mini));
	}

	void initRMQ()
	{
		int m=tolog2[n];
		for(int i=1;i<=m;i++)
		{
			for(int j=n;j>=1;j--)
			{
				maxi[j][i]=maxi[j][i-1];
				mini[j][i]=mini[j][i-1];

				if(j+(1<<(i-1))<=n)
				{
					mini[j][i]=min(mini[j][i],mini[j+(1<<(i-1))][i-1]);
					maxi[j][i]=max(maxi[j][i],maxi[j+(1<<(i-1))][i-1]);
				}
			}
		}
	}
	inline int query_max(int l,int r)
	{
		int m=tolog2[r-l+1];
		return max(maxi[l][m],maxi[r-(1<<m)+1][m]);
	}
	inline int query_min(int l,int r)
	{
		int m=tolog2[r-l+1];
		return min(mini[l][m],mini[r-(1<<m)+1][m]);
	}
}

inline void init()
{
	memset(dis,0,sizeof(dis));
	memset(head,-1,sizeof(head));
	ind=0;
}

inline void addEdge(int a,int b,int cost)
{
	edge[ind]=CEdge(a,b,cost,head[a]);
	head[a]=ind++;
}

int dfs(int x)
{
	if(edge[x].maxdis!=-1) return edge[x].maxdis;

	int u=edge[x].u;
	int v=edge[x].v;

	edge[x].maxdis=edge[x].cost;

	for(int i=head[v];i!=-1;i=edge[i].next)
	{
		if(edge[i].v==u) continue;
		edge[x].maxdis=max(edge[x].maxdis,edge[x].cost+dfs(i));
	}
	return edge[x].maxdis;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c,query;
	RMQ::init_pow();
	while(input(n>>m) && n+m)
	{
		init();
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		for(int i=0;i<ind;i++)//求树上最长路
		{
			if(edge[i].maxdis==-1) dfs(i);
		}
		for(int i=0;i<ind;i++)
		{
			dis[edge[i].u]=max(dis[edge[i].u],edge[i].maxdis);
		}
		RMQ::init();
		for(int i=1;i<=n;i++)
		{
			RMQ::mini[i][0]=RMQ::maxi[i][0]=dis[i];
		}
		RMQ::initRMQ();
		while(m--)
		{
			int ans=0;
			scanf("%d",&query);
			int l=1,r=1;
			while(r<=n)
			{
				if(RMQ::query_max(l,r)-RMQ::query_min(l,r)<=query)
				{
					ans=max(ans,r-l+1);
					r++;
				}
				else l++;
				
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
