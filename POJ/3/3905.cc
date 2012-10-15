//Result:wizmann	3905	Accepted	16516K	1985MS	G++	2170B	2012-10-08 16:19:01
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 2048
#define EDGE 4096000

struct node
{
	int val,next;
	node(){}
	node(int ival,int inext)
	{
		val=ival;
		next=inext;
	}
};

int n,m;
int head[SIZE];
node g[EDGE];
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

inline void addEdge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind++;
}

bool zSat()
{
	for(int i=0;i<n*2;i++)
	{
		if(!dfn[i]) tarjan(i);
	}
	for(int i=0;i<n;i++)
	{
		if(scc[i]==scc[i+n]) return false;
	}
	return true;
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
			if(a>0 && b>0)  // a or b => (a+n,b),(b+n,a)
			{
				a=abs(a);
				b=abs(b);
				--a;--b;

				addEdge(a+n,b);
				addEdge(b+n,a);
			}
			else if(a<0 && b<0) // not a or not b =>(a,b+n),(b,a+n)
			{
				a=abs(a);
				b=abs(b);
				--a;--b;

				addEdge(a,b+n);
				addEdge(b,a+n);
			}
			else if(a>0 && b<0) // a or not b =>(a+n,b+n),(b,a)
			{
				a=abs(a);
				b=abs(b);
				--a;--b;

				addEdge(a+n,b+n);
				addEdge(b,a);
			}
			else if(a<0 && b>0) // not a or b =>(a,b),(b+n,a+n)
			{
				a=abs(a);
				b=abs(b);
				--a;--b;

				addEdge(a,b);
				addEdge(b+n,a+n);
			}
		}
		if(zSat()) puts("1");
		else puts("0");
	}
	return 0;
}


