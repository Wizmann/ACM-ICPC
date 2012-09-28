//Result:2012-09-22 10:23:11	Accepted	3715	671MS	1104K	2221 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define N 512
#define M 40000
#define SIZE 10240

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
int a[SIZE],b[SIZE],c[SIZE];


int head[SIZE];
node g[M];
int ind;

char instack[SIZE];
stack<int> st;
int dfn[SIZE],scc[SIZE],num[SIZE],low[SIZE];
int sccnr,nr;

void init()
{
	ind=0;
	memset(head,-1,sizeof(head));
	memset(instack,0,sizeof(instack));
	memset(scc,0,sizeof(scc));
	memset(num,0,sizeof(num));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	st=stack<int>();
	nr=1;sccnr=0;
}

void tarjan(int pos)
{
	low[pos]=dfn[pos]=nr++;
	st.push(pos);
	instack[pos]=1;

	for(int i=head[pos];i!=-1;i=g[i].next)
	{
		int j=g[i].val;
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


bool zSat()
{
	for(int i=0;i<n*2;i++)
	{
		if(!dfn[i]) tarjan(i);
	}
	for(int i=0;i<n;i++)
	{
		if(scc[i]==scc[i+n])
		{
			return false;
		}
	}
	return true;
}
	


void addEdge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind++;
}


void makeG(int x)
{
	init();
	for(int i=0;i<x;i++)
	{
		int p=a[i],q=b[i];
		if(c[i]==0)
		{
			addEdge(p,q+n);
			addEdge(q,p+n);
		}
		else if(c[i]==1)
		{
			addEdge(p,q);
			addEdge(q,p);
			addEdge(p+n,q+n);
			addEdge(q+n,p+n);
		}
		else if(c[i]==2)
		{
			addEdge(p+n,q);
			addEdge(q+n,p);
		}
	}
}

int slove()
{
	int l=0,r=m;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		makeG(mid);
		if(zSat()) l=mid+1;
		else r=mid-1;
	}
	return r;
}

int main()
{
	int T;
	input(T);
	while(T--)
	{
		input(n>>m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",a+i,b+i,c+i);
		}
		print(slove());
	}
	return 0;
}
