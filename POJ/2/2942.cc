//Result: wizmann	2942	Accepted	9740K	1250MS	G++	2162B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <iostream>

using namespace std;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define SIZE 1010

typedef struct edge
{
	int st,end;
	
	inline void setedge(int a,int b)
	{
		st=a;end=b;
	}
}edge;

int n,ask;
int cnc[SIZE][SIZE];//连通临接表
int g[SIZE][SIZE];
char visit[SIZE][SIZE],in[SIZE];//是否访问过，是否在圈里
int dfn[SIZE],root[SIZE];//时间戳
char color[SIZE];
int lv;//层数
char oddcir[SIZE];
stack<edge> st;

bool bio(int pos,int c)
{
	color[pos]=c;
	for(int i=1;i<=cnc[pos][0];i++)
	{
		int u=cnc[pos][i];
		if(in[u])
		{
			if(color[pos]==color[u]) return false;
			if(color[u]==-1&&!bio(u,1-c)) return false;
		}
	}
	return true;
}

void slove(int pos)
{
	memset(in,0,sizeof(in));
	edge t;
	do
	{
		t=st.top();
		st.pop();
		in[t.st]=in[t.end]=1;
	}while(t.st!=pos);
	memset(color,-1,sizeof(color));
	if(!bio(pos,0))
	{
		for(int i=1;i<=n;i++) oddcir[i] |= in[i];//可以存在于一个奇圈里
	}
}

//找双连通分量，在网上找了很多，都不是很明确。
//只好理解为能成环的图块，此题正是找这样的一个点集	
void tarjan(int pos)
{
	dfn[pos]=root[pos]=++lv;
	for(int i=1;i<=cnc[pos][0];i++)
	{
		int u=cnc[pos][i];
		if(visit[pos][u]) continue;//判重边
		visit[pos][u]=visit[u][pos]=1;
		edge t;
		t.setedge(pos,u);
		st.push(t);
		if(!dfn[u])//如果u点没有被访问过
		{
			tarjan(u);
			root[pos]=min(root[pos],root[u]);
			if(dfn[pos]<=root[u]) slove(pos);	
		}
		else root[pos]=min(root[pos],dfn[u]);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&n,&ask)!=EOF&&n&&ask)
	{
		memset(cnc,0,sizeof(cnc));
		memset(dfn,0,sizeof(dfn));
		memset(visit,0,sizeof(visit));
		memset(oddcir,0,sizeof(oddcir));
		memset(g,-1,sizeof(g));
		int a,b;
		lv=0;
		
		//建图
		for(int i=0;i<ask;i++)
		{
			scanf("%d%d",&a,&b);
			g[a][b]=g[b][a]=0;
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(g[i][j])
				{
					cnc[i][0]++;cnc[j][0]++;
					cnc[i][cnc[i][0]]=j;
					cnc[j][cnc[j][0]]=i;
				}
			}
		}
		//建图完成
		
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i);
		}
		
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(oddcir[i]) ans++;
		}
		printf("%lld\n",n-ans);
	}
	return 0;
}
