//Result:2012-08-24 17:30:43	Accepted	4396	703MS	4376K	1901 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 5120
#define EDGE 210000

const int INF=0x3f3f3f3f;

int k,n;
int len[SIZE];

struct node
{
	int dest,cost,next;
	node(){}
	node(int idest,int icost,int inext)
	{
		dest=idest;cost=icost;next=inext;
	}
};

struct john
{
	int now,wood;
	john(){}
	john(int inow,int iwood)
	{
		now=inow;wood=iwood;
	}
};

node g[EDGE];
int head[SIZE];
int ind;

inline void addEdge(int a,int b,int c)
{
	g[ind]=node(b,c,head[a]);
	head[a]=ind++;
}
	

int slove(int st,int end,int need)
{
	queue<john> pq;
	int dp[SIZE][55];
	char visit[SIZE][55];
	memset(dp,0x3f,sizeof(dp));
	memset(visit,0,sizeof(visit));
	pq.push(john(st,0));
	dp[st][0]=0;
	while(!pq.empty())
	{
		john jnow=pq.front();
		pq.pop();
		int now=jnow.now;
		int wood=jnow.wood;
		visit[now][wood]=0;

		for(int i=head[now];i!=-1;i=g[i].next)
		{
			int next=g[i].dest;
			int cost=g[i].cost;

			int next_wood=wood+1;
			if(next_wood>=need) next_wood=need;
			if(dp[next][next_wood]>dp[now][wood]+cost)
			{
				dp[next][next_wood]=dp[now][wood]+cost;
				if(!visit[next][next_wood])
				{
					visit[next][next_wood]=1;
					pq.push(john(next,next_wood));
				}
			}
		}
	}
	int ans=INF;
	for(int i=50;i>=need;i--)
	{
		ans=min(ans,dp[end][i]);
	}
	return ans;
}

int main()
{
	freopen("data.in","r",stdin);
	int st,end,wood;
	int a,b,c;
	while(input(n>>k))
	{
		ind=0;
		memset(head,-1,sizeof(head));
		for(int i=0;i<k;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		scanf("%d%d%d",&st,&end,&wood);
		if(wood%10!=0) wood+=10;
		int ans=slove(st,end,wood/10);
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
		
