#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>

#define SIZE 10010
#define pb push_back
#define min(a,b) (a<b?a:b)

using namespace std;

int n,ask;
vector<int> g[SIZE];
int cnt[SIZE];//出度
char instack[SIZE];//是否在栈中
int low[SIZE];//所有节点的最小标号
int nr=1;//时间编号
stack<int> st;
int dfn[SIZE];//时间戳
int scc[SIZE];//标明每一个点属于哪个SCC中
int num[SIZE];//每一个SCC中包含多少元素
int sccnr=0;

void init()
{
	for(int i=0;i<=n;i++) g[i].clear();
	memset(cnt,0,sizeof(cnt));
	memset(instack,0,sizeof(instack));
	memset(low,0,sizeof(low));
	nr=1;
	while(!st.empty()) st.pop();
	memset(dfn,0,sizeof(dfn));
	memset(scc,0,sizeof(scc));
	memset(num,0,sizeof(num));
	sccnr=0;
}

void tarjan(int pos)
{
	int min;
	min=low[pos]=dfn[pos]=nr++;
	st.push(pos);
	instack[pos]=1;
	for(int i=0;i<(int)g[pos].size();i++)
	{
		int j=g[pos][i];
		if(!dfn[j])
		{
			tarjan(j);
			low[pos]=min(low[pos],low[j]);
		}
		else if(instack[j]) low[pos]=min(low[pos],dfn[j]);
	}
	
	if(dfn[pos]==low[pos])
	{
		sccnr++;
		while(1)
		{
			int t=st.top();
			instack[t]=0;
			st.pop();
			scc[t]=sccnr;
			num[sccnr]++;
			if(t==pos) break;
		}
	}			
}
	
	
int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(scanf("%d%d",&n,&ask)!=EOF)
	{
		init();
		while(ask--)
		{
			scanf("%d%d",&a,&b);
			g[a].pb(b);
		}
		
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i);
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<(int)g[i].size();j++)
			{
				int v=g[i][j];
				if(scc[i]!=scc[v]) cnt[scc[i]]=1;
			}
		}
		int outnum=0;
		int ans=0;
		for(int i=1;i<=sccnr;i++)
		{
			if(!cnt[i])
			{
				outnum++;
				ans=i;
			}
		}
		if(outnum==1) printf("%d\n",num[ans]);
		else puts("0");
	}
	return 0;
}
			
		
