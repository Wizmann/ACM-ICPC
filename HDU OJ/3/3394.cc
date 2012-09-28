//Result:2012-09-21 19:51:35	Accepted	3394	484MS	2764K	1846 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10240
#define EDGE 102400

int n,m;
vector<int> g[SIZE];
int in[SIZE];//是否访问过，是否在圈里
int dfn[SIZE],low[SIZE];//时间戳
int idx;//层数
stack<int> st;
int res1,res2;
int block[SIZE],vis[SIZE];

void init()
{
	for(int i=0;i<SIZE;i++) g[i].clear();
	memset(dfn,-1,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(in,0,sizeof(in));
	st=stack<int>();
	idx=0;
	res1=res2=0;
}


void count()
{	
	int a=block[0] ;
	int b=0 ;
	for(int i=1 ;i<=block[0];i++)
	{
        int u=block[i] ;
        for(int j=0;j<(int)g[u].size();j++)
        {
            int v=g[u][j];
			if(vis[v]) b++;
        }
    }
    b/=2 ;
    if( a > b ) res1 += b ;
    if(a < b) res2 += b ;
}

void tarjan(int x, int pre)
{
	low[x]=dfn[x]=++idx ;
    st.push(x);
	for(int i=0;i<(int)g[x].size();i++)
	{
        int u=g[x][i];
		if(u==pre) continue;
		if(dfn[u]==-1)
		{
			tarjan(u,x);
			if(low[u]<low[x]) low[x]=low[u];
			if(low[u]>=dfn[x])
			{
				block[0]=0;
				memset(vis,0,sizeof(vis));
                int v;
				do
				{
					v=st.top();
					st.pop();
					vis[v]=1;
					block[++block[0]]=v;
				}while(u!=v);
				block[++block[0]]=x;
				vis[x]=1;
				count();
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
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for(int i=0;i<n;i++)
		{
			if(dfn[i]==-1) tarjan(i,-1);
		}
		printf("%d %d\n",res1,res2);
	}
	return 0;
}


