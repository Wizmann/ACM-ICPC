//Result:wizmann	2723	Accepted	1428K	219MS	G++	2046B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 4096
#define KEY (n*2)
#define zSAT (n*4)
#define pb push_back

struct edge
{
	int st,end;

	edge(int i_st,int i_end)
	{
		st=i_st;end=i_end;
	}
};

int n,m;
int key[SIZE][2];
int door[SIZE][2];
vector<int> g[SIZE];
int cnt,lv;
int dfn[SIZE],low[SIZE];
stack<int> st;
int color[SIZE],in[SIZE];

void makeG(int x)
{
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(color,0,sizeof(color));
	memset(in,0,sizeof(in));
	while(!st.empty()) st.pop();

	for(int i=0;i<zSAT;i++) g[i].clear();
	for(int i=0;i<n;i++)
	{
		g[key[i][0]].pb(key[i][1]+KEY);
		g[key[i][1]].pb(key[i][0]+KEY);
	}
	for(int i=0;i<x;i++)
	{
		g[door[i][1]+KEY].pb(door[i][0]);
		g[door[i][0]+KEY].pb(door[i][1]);
	}
}

void slove(int pos)
{
	while(1)
	{
		int t=st.top();
		st.pop();
		in[t]=0;
		color[t]=cnt;
		if(t==pos) break;
	}
	cnt++;
}

void tarjan(int pos)
{
	low[pos]=dfn[pos]=++lv;
	st.push(pos);
	in[pos]=1;
	for(int i=0;i<(int)g[pos].size();i++)
	{
		int u=g[pos][i];
		if(!dfn[u])
		{
			tarjan(u);
			low[pos]=min(low[pos],low[u]);
		}
		else if(in[u])
		{
			low[pos]=min(low[pos],dfn[u]);
		}
	}

	if(dfn[pos]==low[pos]) slove(pos);
}

bool judge()
{
	for(int i=0;i<KEY;i++)
	{
		if(color[i]==color[i+KEY]) return false;
	}
	return true;
}

int main()
{
	while(input(n>>m) && n+m)
	{
		memset(key,0,sizeof(key));
		memset(door,0,sizeof(door));
		for(int i=0;i<n;i++)
		{
			input(key[i][0]>>key[i][1]);
		}
		for(int i=0;i<m;i++)
		{
			input(door[i][0]>>door[i][1]);
		}

		int l=0,r=m;
		while(l<=r)
		{
			cnt=1;lv=0;
			int mid=(l+r)>>1;
			makeG(mid);
			for(int i=0;i<zSAT;i++)
			{
				if(!dfn[i]) tarjan(i);
			}
			if(judge()) l=mid+1;
			else r=mid-1;
		}
		print(l-1);
	}
	return 0;
}
