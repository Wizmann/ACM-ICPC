//Result:wizmann	2762	Accepted	2004K	375MS	C++	2187B	2012-09-19 22:35:44
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1280

vector<int> g[SIZE];
char instack[SIZE];
int low[SIZE];
int nr,sccnr;
stack<int> st;
int dfn[SIZE];
int scc[SIZE];
int num[SIZE];

void init()
{
	for(int i=0;i<SIZE;i++) g[i].clear();
	memset(instack,0,sizeof(instack));
	memset(low,0,sizeof(low));
	nr=1;sccnr=0;
	while(!st.empty()) st.pop();
	memset(dfn,0,sizeof(dfn));
	memset(scc,0,sizeof(scc));
	memset(num,0,sizeof(num));
}

void tarjan(int pos)
{
	low[pos]=dfn[pos]=nr++;
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
		else if(instack[j])
		{
			low[pos]=min(low[pos],dfn[j]);
		}
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

int n,m;
char mp[SIZE][SIZE];

bool topsort()
{
	char visit[SIZE]={0};
	int in[SIZE]={0};
	for(int i=1;i<=sccnr;i++)
	{
		for(int j=1;j<=sccnr;j++)
		{
			if(mp[i][j]) in[j]++;
		}
	}
	int sum=0;
	while(1)
	{
		int ptr=-1,zz=0;
		for(int i=1;i<=sccnr;i++) if(!visit[i])
		{
			if(in[i]==0)
			{
				ptr=i;
				zz++;
			}
		}
		if(ptr==-1 || zz!=1) break;
		else
		{
			visit[ptr]=1;
			sum++;

			for(int i=1;i<=sccnr;i++)
			{
				if(mp[ptr][i]) in[i]--;
			}
		}
	}
	return sum==sccnr;
}



int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b;
	input(T);
	while(T--)
	{
		memset(mp,0,sizeof(mp));
		init();
		input(n>>m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			if(a==b) continue;
			g[a].push_back(b);
		}
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<(int)g[i].size();j++)
			{
				if(scc[i]!=scc[g[i][j]]) mp[scc[i]][scc[g[i][j]]]=1;
			}
		}
		if(sccnr==1 || topsort()) puts("Yes");
		else puts("No");
	}
	return 0;
}


