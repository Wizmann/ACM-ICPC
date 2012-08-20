//Result:wizmann	2553	Accepted	1348K	172MS	G++	1880B
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
#define SIZE 5010
#define pb push_back

vector<int> g[SIZE];
int n,m;
int dfn[SIZE],scc[SIZE],out[SIZE],in[SIZE],low[SIZE];
stack<int> st;
bitset<SIZE> instack;
int nr,sccnr;

void init()
{
	memset(dfn,0,sizeof(dfn));
	memset(scc,0,sizeof(scc));
	memset(out,0,sizeof(out));
	memset(in,0,sizeof(in));
	memset(low,0,sizeof(low));
	for(int i=0;i<SIZE;i++) g[i].clear();
	instack.reset();
	while(!st.empty()) st.pop();
	nr=1;
	sccnr=0;
}

void tarjan(int pos)
{
	int mval;
	mval=low[pos]=dfn[pos]=nr++;
	st.push(pos);
	instack[pos]=1;
	for(int i=0;i<(int)g[pos].size();i++)
	{
		int next=g[pos][i];
		if(!dfn[next])
		{
			tarjan(next);
			low[pos]=min(low[pos],low[next]);
		}
		else if(instack[next])
		{
			low[pos]=min(low[pos],dfn[next]);
		}
	}

	if(dfn[pos]==low[pos])
	{
		sccnr++;
		while(1)
		{
			int t=st.top();
			st.pop();
			instack[t]=0;
			scc[t]=sccnr;
			if(t==pos) break;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(scanf("%d%d",&n,&m)==2 && n+m)
	{
		init();
		for(int i=0;i<m;i++)
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
				int k=g[i][j];
				if(scc[i]!=scc[k])
				{
					in[scc[k]]++;
					out[scc[i]]++;
				}
			}
		}
		//print("ANS>>");
		vector<int> ans;
		for(int i=1;i<=n;i++)
		{
			if(scc[i] && !out[scc[i]]) ans.pb(i);
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<(int)ans.size();i++)
		{
			if(i) printf(" ");
			printf("%d",ans[i]);
		}
		puts("");
	}
	return 0;
}

