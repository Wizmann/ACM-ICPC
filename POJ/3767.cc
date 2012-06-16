//Result:wizmann	3767	Accepted	1564K	266MS	G++	1997B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 40000
#define N 10010
#define START 1
#define DEST 2
#define INF 1<<25

struct node
{
	int to,dis,next;
	node(){}
	node(int i_to,int i_dis,int i_next)
	{
		to=i_to;
		dis=i_dis;
		next=i_next;
	}
};

int n,m;
bitset<N> leader;
int ind;
int head[N];
node g[SIZE];

void addEdge(int from,int to,int dis)
{
	if(leader[from]==leader[to])
	{
		g[ind]=node(to,dis,head[from]);
		head[from]=ind++;
		g[ind]=node(from,dis,head[to]);
		head[to]=ind++;
	}
	else
	{
		if(leader[from])
		{
			g[ind]=node(to,dis,head[from]);
			head[from]=ind++;
		}
		else
		{
			g[ind]=node(from,dis,head[to]);
			head[to]=ind++;
		}
	}
}
		
int SPFA()
{
	int dis[N];
	queue<int> q;
	bitset<SIZE> visit;
	while(!q.empty()) q.pop();
	visit.reset();
	for(int i=0;i<N;i++) dis[i]=INF;
	q.push(START);
	dis[START]=0;
	
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		int t=head[now];
		while(t!=-1)
		{
			int dest=g[t].to;
			if(dis[now]<INF && dis[now]+g[t].dis<dis[dest])
			{
				dis[dest]=dis[now]+g[t].dis;
				if(!visit[dest])
				{
					q.push(dest);
					visit[dest]=1;
				}
			}
			t=g[t].next;
		}
	}
	return dis[DEST];
}


int main()
{
	freopen("input.txt","r",stdin);
	vector<node> tmp;
	int a,b,c;
	while(input(n) && n)
	{
		ind=0;
		memset(head,-1,sizeof(head));
		memset(g,-1,sizeof(g));
		input(m);
		leader.reset();
		for(int i=0;i<m;i++)
		{
			input(a>>b>>c);
			tmp.push_back(node(a,b,c));
		}
		for(int i=1;i<=n;i++)
		{
			input(a);
			if(a==1) leader[i]=1;
		}
		int sz=tmp.size();
		
		for(int i=0;i<sz;i++)
		{
			addEdge(tmp[i].to,tmp[i].dis,tmp[i].next);
		}
		tmp.clear();
		int ans=SPFA();
		printf("%d\n",ans>=INF?-1:ans);
	}
	return 0;
}
		
			
	
