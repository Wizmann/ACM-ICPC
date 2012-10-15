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
		for(int i=0;i<ind;i++)
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
