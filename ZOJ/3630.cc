//Result:2012-07-30 16:57:06	 Accepted	3630	C++	510	616	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10000
#define INF 1<<25

struct node
{
	int v;
	int next;
	node(){}
	node(int iv,int inext)
	{
		v=iv;next=inext;
	}
};

int head[SIZE];
node g[SIZE];
int ind;
int n,m;

int low[SIZE],dfn[SIZE];
int scc[SIZE],num[SIZE];
vector<int> tmpG[SIZE];
int sccnr=0;
stack<int> st;
bitset<SIZE> instack;
int nr;
int inG[SIZE];

inline void add_edge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind;
	ind++;
}

void init(bool all=true)
{
	if(all)
	{
		memset(head,-1,sizeof(head));
		memset(g,0,sizeof(g));
		ind=0;
	}
	instack.reset();
	memset(dfn,0,sizeof(dfn));
	memset(scc,0,sizeof(scc));
	memset(num,0,sizeof(num));
	memset(low,0,sizeof(low));
	while(!st.empty()) st.pop();
	nr=1;sccnr=0;
	
}

void tarjan(int pos)
{
	low[pos]=dfn[pos]=nr++;
	st.push(pos);
	instack[pos]=1;

	for(int i=head[pos];i!=-1;i=g[i].next)
	{
		int j=g[i].v;
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

int slove(int sec,int ptr)
{
	int tmp=0;
	memset(inG,-1,sizeof(inG));
	for(int i=0;i<SIZE;i++) tmpG[i].clear();
	for(int i=0;i<n;i++)
	{
		if(scc[i]==ptr) inG[i]=tmp++;
	}
	for(int i=0;i<n;i++)
	{
		if(scc[i]==ptr)
		{
			int now=inG[i];
			for(int j=head[i];j!=-1;j=g[j].next)
			{
				int next=g[j].v;
				if(inG[next]>=0)
				{
					next=inG[next];
					tmpG[now].push_back(next);
				}
			}
		}
	}
	init();
	n=tmp;
	for(int i=0;i<tmp;i++)
	{
		for(int j=0;j<(int)tmpG[i].size();j++)
		{
			add_edge(i,tmpG[i][j]);
		}
	}
	int ans=INF;
	for(int i=0;i<tmp;i++)
	{
		init(false);
		int t=head[i];
		head[i]=-1;
		for(int j=0;j<tmp;j++)
		{
			if(!dfn[j]) tarjan(j);
		}
		int maxi=-1;
		for(int j=0;j<tmp;j++)
		{
			maxi=max(maxi,num[j]);
		}
		ans=min(ans,max(maxi,sec));
		head[i]=t;
	}
	return ans>1?ans:0;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(input(n>>m))
	{
		init();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			add_edge(a,b);
		}

		for(int i=0;i<n;i++)
		{
			if(!dfn[i]) tarjan(i);
		}
		
		priority_queue<int> pq;
		int max_scc=-1,ptr=-1;
		for(int i=1;i<=sccnr;i++)
		{
			pq.push(num[i]);
			if(num[i]>max_scc)
			{
				max_scc=num[i];
				ptr=i;
			}
		}
		//print(">>"<<' '<<max_scc);
		pq.pop();
		int sec=0;
		if(!pq.empty()) sec=pq.top();
		print(slove(sec,ptr));
	}
	return 0;
}
