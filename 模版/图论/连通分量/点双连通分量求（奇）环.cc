//Result:wizmann	2942	Accepted	1372K	1079MS	C++	2422B	2012-09-21 21:13:07
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define EDGE 1024000

struct node
{
	int val,next;
	node(){}
	node(int ival,int inext)
	{
		val=ival;next=inext;
	}
};

int n,m;
int head[SIZE];
int in[SIZE];
int dfn[SIZE],low[SIZE];
int idx,ind;
stack<int> st;
char visit[SIZE];
int block[SIZE];
node g[EDGE<<1];
char color[SIZE];
char oddcir[SIZE];
char cnc[SIZE][SIZE];

void init()
{
	memset(head,-1,sizeof(head));
	memset(dfn,-1,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(in,0,sizeof(in));
	st=stack<int>();
	idx=ind=0;
	memset(oddcir,0,sizeof(oddcir));
	memset(cnc,0,sizeof(cnc));
}

void addEdge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind++;
}
	

bool bio(int x,int c)
{
	color[x]=c;
	for(int i=head[x];i!=-1;i=g[i].next)
	{
		int u=g[i].val;
		if(in[u])
		{
			if(color[u]==color[x]) return false;
			if(color[u]==-1 && !bio(u,1-c)) return false;
		}
	}
	return true;
}

void check_odd_circle(int pos)
{
	memset(color,-1,sizeof(color));
	memset(in,0,sizeof(in));
	for(int i=1;i<=block[0];i++) in[block[i]]=1;
	if(!bio(pos,0))
	{
		for(int i=1;i<=block[0];i++)
		{
			oddcir[block[i]]=1;
		}
	}
}

void tarjan(int x,int pre)
{
	low[x]=dfn[x]=++idx;
	st.push(x);
	for(int i=head[x];i!=-1;i=g[i].next)
	{
		int u=g[i].val;
		if(u==pre) continue;
		if(dfn[u]==-1)
		{
			tarjan(u,x);
			if(low[u]<low[x]) low[x]=low[u];
			if(low[u]>=dfn[x])
			{
				block[0]=0;
				memset(visit,0,sizeof(visit));
				int v;
				do
				{
					v=st.top();
					st.pop();
					visit[v]=1;
					block[++block[0]]=v;
				}while(u!=v);
				block[++block[0]]=x;
				visit[x]=1;
				check_odd_circle(x);
			}
		}
		else low[x]=min(low[x],dfn[u]);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(input(n>>m) && n+m)
	{
		init();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			cnc[a][b]=cnc[b][a]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) if(i!=j)
			{
				if(cnc[i][j]==0) addEdge(i,j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(dfn[i]==-1) tarjan(i,-1);
		}
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(oddcir[i]) ans++;
		}
		print(n-ans);
	}
	return 0;
}

