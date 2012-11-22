#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 2560
#define EDGE 25600
#define INF 0x3f3f3f3f

struct node
{
	int st,end,flow,next;
	node(){}
	node(int ist,int iend,int iflow,int inext)
	{
		st=ist;end=iend;flow=iflow;next=inext;
	}
};

node g[EDGE];
int head[NODE];
int ind;
int source,sink;

void addEdge(int s,int e,int f)
{
	g[ind]=node(s,e,f,head[s]);
	head[s]=ind++;

	g[ind]=node(e,s,0,head[e]);
	head[e]=ind++;
}

namespace dinic
{
	int level[NODE],cur_head[NODE],Que[NODE];
	int edge_stack[(NODE<<2)+(EDGE<<2)];
	int stack_top;

	int BFS()
	{
		int fr,tp,cur,next,e;
		memset(level,-1,sizeof(level));
		Que[0]=source;
		for(fr=0,tp=1;fr!=tp;fr=(fr+1)%NODE)
		{
			cur=Que[fr];
			for(e=head[cur];e!=-1;e=g[e].next)
			{
				next=g[e].end;
				if(g[e].flow && level[next]==-1)
				{
					Que[tp]=next;
					level[next]=level[cur]+1;
					tp=(tp+1)%NODE;
				}
			}
		}
		return level[sink]!=-1;
	}

	int DFS()
	{
		int index,min_limit,e;
		int res=0;
		memcpy(cur_head,head,sizeof(head));
		int cur=source;

		stack_top=0;
		while(stack_top>=0)
		{
			if(cur==sink)
			{
				min_limit=INF;
				for(int i=stack_top-1;i>=0;i--)
				{
					e=edge_stack[i];
					if(g[e].flow<=min_limit)
					{
						min_limit=edge[e].flow;
						index=i;
					}
				}
				res+=min_limit;

				for(int i=stack_top-1;i>=0;i--)
				{
					e=edge_stack[i];
					edge[e].flow-=min_limit;
					edge[e^1].flow+=min_limit;
				}
				stack_top=index;
				cur=edge[edge_stack[stack_top]].st;
			}
			for(e=cur_head[cur];e!=-1;e=g[e].next)
			{
				cur_head[cur]=e;
				int next=edge[e].end;
				if(edge[e].flow && level[next]==level[cur]+1)
				{
					edge_stack[stack_top++]=e;
					cur=next;
					break;
				}
			}
			if(e==-1)
			{
				stack_top--;
				level[cur]=-2;
				cur=edge[edge_stack[stack_top]].st;
			}
		}
		return res;
	}
}


void init()
{
	memset(head,-1,sizeof(head));
	ind=0;
}


int n,k;
int mp[54][54];

inline int getnr(int x,int y)
{
	return (n*y+x)*2;
}

int main()
{
	while(input(n>>k))
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int nr=getnr(j,i);
				addEdge(nr,nr+1,mp[i][j]);

				if(j+1<n) addEdge(nr,getnr(j+1,i)


