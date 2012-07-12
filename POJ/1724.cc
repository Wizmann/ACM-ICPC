//Result:wizmann	1724	Accepted	6276K	94MS	C++	1849B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <deque>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<28
#define inf 1e30
#define eps 1e-9
#define pb push_back
#define SIZE 128

struct node
{
	int dest,dis,cost;
	
	node(){}
	node(int i_dest,int i_dis,int i_cost)
	{
		dest=i_dest;dis=i_dis;
		cost=i_cost;
	}
};

struct path
{
	int pos,dis,cost;
	
	path(){}
	path(int i_pos,int i_dis,int i_cost)
	{
		pos=i_pos;dis=i_dis;cost=i_cost;
	}
	
	friend bool operator < (const path& a,const path& b)
	{
		return a.dis>b.dis;
	}
};

vector<node> g[SIZE];

int coin,n,m;


int bfs()
{
	int hash[SIZE][10024];
	memset(hash,0x0f,sizeof(hash));
	
	priority_queue<path> q;
	q.push(path(1,0,0));
	int ans=INF;
	while(!q.empty())
	{
		path now=q.top();
		q.pop();
		int hier=now.pos;
		int money=now.cost;
		int dis=now.dis;
		if(money>coin) continue;
		
		if(hash[hier][money]<dis) continue;
		else hash[hier][money]=dis;
		
		if(dis>ans) continue;
		
		if(hier==n)
		{
			ans=dis;
			continue;
		}
		
		for(int i=0;i<(int)g[hier].size();i++)
		{
			int next=g[hier][i].dest;
			int cost=g[hier][i].cost;
			int dist=g[hier][i].dis;
			
			if(hash[next][cost+money]>dis+dist)
			{
				q.push(path(next,dis+dist,cost+money));
			}
		}
	}
	return ans;
}
	


int main()
{
	freopen("f.txt","r",stdin);
	int a,b,c,d;
	scanf("%d%d%d",&coin,&n,&m);
//	while(!=EOF)
	{
		for(int i=0;i<n;i++) g[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			g[a].pb(node(b,c,d));
			//g[b].pb(node(a,c,d));
		}
		print(bfs());
	}
	return 0;
}
		
