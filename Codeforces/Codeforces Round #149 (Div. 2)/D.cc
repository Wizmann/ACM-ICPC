//Result:Nov 23, 2012 5:50:07 PM	Wizmann	 D - Dispute	 GNU C++	Accepted	109 ms	4700 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010

struct node
{
	int v,next;
	node(){}
	node(int iv,int inext)
	{
		v=iv;next=inext;
	}
};

int n,m,tot;
int val[SIZE],res[SIZE],result[SIZE];
int head[SIZE];
node g[SIZE<<2];
int ind;

inline void _addEdge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind++;
}

inline void addEdge(int a,int b)
{
	_addEdge(a,b);
	_addEdge(b,a);
}

void addVal(int pos,int v)
{
	val[pos]+=v;
	for(int i=head[pos];i!=-1;i=g[i].next)
	{
		int next=g[i].v;
		val[next]+=v;
	}
}


void dfs(int x)
{
	for(int i=head[x];i!=-1;i=g[i].next)
	{
		int v=g[i].v;
		if(val[v]==res[v])
		{
			addVal(v,1);
			result[tot++]=v;
			dfs(v);
		}
	}
}

int slove()
{
	memset(val,0,sizeof(val));
	tot=0;
	for(int i=1;i<=n;i++)
	{
		if(val[i]==res[i])
		{
			addVal(i,1);
			dfs(i);
			result[tot++]=i;
		}
	}
	if(tot==0) return 0;
	else return tot;
}


int main()
{
	int a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ind=0;
		memset(head,-1,sizeof(head));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			addEdge(a,b);
		}
		for(int i=1;i<=n;i++) scanf("%d",res+i);
		int ans=slove();
		if(ans==-1) puts("-1");
		else
		{
			printf("%d\n",ans);
			sort(result,result+ans);
			for(int i=0;i<ans;i++)
			{
				printf("%d ",result[i]);
			}
			puts("");
		}
	}
	return 0;
}
