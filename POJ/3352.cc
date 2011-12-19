#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

using std::stack;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define SIZE 1010

int n,ask;
int g[SIZE][SIZE];//临接表
int dfn[SIZE],low[SIZE];//时间戳
stack<int> st;
int bio[SIZE],in[SIZE];
int lv=0,sum;

inline void pb(int a,int b)
{
	g[a][0]++;g[b][0]++;
	g[a][g[a][0]]=b;
	g[b][g[b][0]]=a;
}

void tarjan(int v,int pre)
{
	dfn[v]=low[v]=++lv;
	st.push(v);
	for(int i=1;i<=g[v][0];i++)
	{
		int u=g[v][i];
		if(u==pre) continue;
		if(!dfn[u])
		{
			tarjan(u,v);
			low[v]=min(low[v],low[u]);
		}
		else low[v]=min(low[v],dfn[u]);
	}
	if(low[v]==dfn[v])
	{
		int t;
		++sum;
		do
		{
			t=st.top();
			st.pop();
			bio[t]=sum;
		}while(t!=v);
	}
}
	

int main()
{
	int a,b;
	scanf("%d%d",&n,&ask);
	while(ask--)
	{
		scanf("%d%d",&a,&b);
		pb(a,b);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i]) tarjan(i,-1);
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=g[i][0];j++)
		{
			int u=g[i][j];
			if(bio[i]!=bio[u])
			{
				in[bio[u]]++;
				in[bio[i]]++;
			}
		}
	}
	
	int ans=0;
	for(int i=1;i<=sum;i++)
	{
		if(in[i]==2) ans++;
	}
	
	printf("%d\n",(ans+1)/2);
	return 0;
}
		
