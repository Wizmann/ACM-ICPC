//Result:Wizmann	2182	Accepted	GNU C++	1.70k	0 ms	1280 KB	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 54
#define EDGE 2560

struct edge
{
	int val,next;
	edge(){}
	edge(int ival,int inext)
	{
		val=ival;
		next=inext;
	}
};

int head[NODE],ind;
edge g[EDGE];
int in[NODE];
int n,m,sz;
int ans[NODE];
char visit[NODE];

void init()
{
	memset(head,-1,sizeof(head));
	ind=0;
	memset(in,0,sizeof(in));
}

inline void addEdge(int a,int b)
{
	g[ind]=edge(b,head[a]);
	head[a]=ind++;
}

bool top_sort()
{
	sz=0;
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		ans[sz++]=now;
		for(int i=head[now];i!=-1;i=g[i].next)
		{
			int next=g[i].val;
			if(!(--in[next])) q.push(next);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(in[i]) return false;
	}
	
	return true;
}

int dfs(int now,int step=1)
{
	ans[sz++]=now;
	if(visit[now]) return visit[now];
	else
	{
		visit[now]=step;
		for(int i=head[now];i!=-1;i=g[i].next)
		{
			int next=g[i].val;
			int tmp=dfs(next,step+1);
			if(tmp) return tmp;
		}
		visit[now]=0;
	}
	sz--;
	return 0;
}


int main()
{
	int a,b;
	init();
	input(n>>m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		addEdge(a,b);
		in[b]++;
	}
	if(top_sort())
	{
		puts("YES");
		for(int i=0;i<sz;i++)
		{
			if(i) printf(",");
			printf("%d",ans[i]);
		}
	}
	else
	{
		puts("NO");
		for(int i=1;i<=n;i++) if(in[i])
		{
			sz=0;
			memset(visit,0,sizeof(visit));
			int tmp=dfs(i);
			if(tmp)
			{
				for(int i=tmp-1;i<sz;i++)
				{
					if(i!=tmp-1) printf(",");
					printf("%d",ans[i]);
				}
				break;
			}
		}
	}
	puts("");
	return 0;
}
