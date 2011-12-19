//Result:wizmann	1724	Accepted	1304K	63MS	C++	1417B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#include <bitset>
#include <stack>
#include <vector>

#define pq priority_queue
#define pb push_back

using namespace std;

typedef struct road
{
	int dest,cost,dis;
	
	void setroad()
	{
		scanf("%d%d%d",&dest,&dis,&cost);
	}
}road;

typedef struct node
{
	bitset<110> visit;
	int now,cost,dis;
	
	node()
	{
		visit.reset();
		now=cost=dis=0;
	}
	
	void setnode(int v,int a,int b,int c)
	{
		visit[v]=1;
		now=a;cost+=b;dis+=c;
	}
	
	friend bool operator < (const node a,const node b)
	{
		return a.dis>b.dis;
	}
}node;

int money,n,ask;
road g[110][110];
int num[110];

void pb(int a,road r)
{
	num[a]++;
	g[a][num[a]]=r;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a;
	scanf("%d%d%d",&money,&n,&ask);
	while(ask--)
	{
		scanf("%d",&a);
		road r;
		r.setroad();
		pb(a,r);
	}	
	pq<node> q;
	node t;
	t.setnode(1,1,0,0);
	q.push(t);
	int ans=1<<20;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		int now=t.now;
		if(t.dis>ans) continue;
		if(now==n) ans=min(ans,t.dis);
		for(int i=1;i<=num[now];i++)
		{
			road tmp=g[now][i];
			if(!t.visit[tmp.dest]&&t.cost+tmp.cost<=money)
			{
				node neu=t;
				neu.setnode(tmp.dest,tmp.dest,tmp.cost,tmp.dis);
				q.push(neu);
			}
		}
	}
	if(ans>=1<<20) puts("-1");
	else printf("%d\n",ans);
	return 0;
}
	
