//Result:wizmann	1275	Accepted	748K	0MS	G++	2308B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define HOUR 24
#define INF 1<<30

struct node
{
	int dest,cost;
	node(){}
	node(int i_dest,int i_cost)
	{
		dest=i_dest;
		cost=i_cost;
	}
};

int work[HOUR+5];//在t时刻新增了多少工作
int man[HOUR+5];//在t时刻新增了多少可用的劳动力
int n;

vector<node> g[HOUR+5];

inline int gethour(int now)
{
	return (now-1+HOUR)%HOUR+1;//24小时是一个循环
}

void makeG(int res)
{
	//建图
	for(int i=0;i<=HOUR;i++) g[i].clear();
	for(int i=1;i<=HOUR;i++)
	{
		//不等式：0<= s[i]-s[i-1] <= man[i]
		//s[i]指在i时刻已经雇佣的人
		//在某个时刻，人数一定不少于前一个时刻，但是又不能多于可用的劳力数
		g[i].push_back(node(i-1,man[i]));
		g[i-1].push_back(node(i,0));
		

		//在i时刻，一定会比i-8时刻多work[i]（或以上）个劳动力
		if(i>=9)
		{
			g[gethour(i-8)].push_back(node(i,-work[i]));
		}
		else
		{
			//对于循环回来的小时，要特殊处理一下
			g[gethour(i-8)].push_back(node(i,res-work[i]));
		}
	}
	//特殊的一个点，s[0]是什么都没有的，所以s[24]-s[0]<=res
	g[0].push_back(node(HOUR,-res));
}

int spfa(int mid)
{
	makeG(mid);
	
	queue<int> q;
	bitset<HOUR+5> visit;
	int dis[HOUR+5];
	fill(dis,dis+HOUR+5,INF);
	int inque[HOUR+5];

	memset(inque,0,sizeof(inque));
	q.push(0);
	visit[0]=1;
	dis[0]=0;

	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;

		for(int i=0;i<(int)g[now].size();i++)
		{
			int next=g[now][i].dest;
			int cost=g[now][i].cost;

			if(dis[now]+cost<dis[next])
			{
				dis[next]=dis[now]+cost;
				if(!visit[next])
				{
					visit[next]=1;
					inque[next]++;
					if(inque[next]>HOUR+2) return -INF;
					q.push(next);
				}
			}
		}
	}
	return dis[HOUR];
}

int main()
{
	//思路：差分约束(SPFA)+二分猜测答案
	//难度在于建图
	int T,a;
	input(T);
	while(T--)
	{
		memset(man,0,sizeof(man));
		for(int i=1;i<=HOUR;i++) scanf("%d",work+i);
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			man[a+1]++;
		}
		int left=0,right=n+1;
			
		while(left<=right)
		{
			int mid=(left+right)>>1;
			int ans=spfa(mid);
			if(ans>-INF) right=mid-1;
			else left=mid+1;
		}
		if(left<=n) print(left);
		else print("No Solution");
	}

	return 0;
}

