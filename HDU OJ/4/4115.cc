//Result:2012-10-08 14:14:20	Accepted	4115	31MS	740K	2754B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20480

struct node
{
	int val,next;
	node(){}
	node(int ival,int inext)
	{
		val=ival;next=inext;
	}
};

int head[SIZE];
node g[SIZE<<2];
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

int n,m;
int type[SIZE][2];

void addEdge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind++;
}

void setSame(int a,int b)
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(type[a][i]==type[b][j])
			{
				int nrA=a+n*i;
				int nrB=b+n*j;
				addEdge(nrA,nrB);
				addEdge(nrB,nrA);
			}
		}
	}
	if(type[a][0]!=type[b][0] && type[a][0]!=type[b][1]) addEdge(a,a+n);
	if(type[a][1]!=type[b][0] && type[a][1]!=type[b][1]) addEdge(a+n,a);
	if(type[b][0]!=type[a][0] && type[b][0]!=type[a][1]) addEdge(b,b+n);
	if(type[b][1]!=type[a][0] && type[b][1]!=type[a][1]) addEdge(b+n,b);
}

void setDiff(int a,int b)
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(type[a][i]==type[b][j])
			{
				int nowA=a+n*i;
				int nextA=a+n*(i!=1);

				int nowB=b+n*j;
				int nextB=b+n*(j!=1);
				addEdge(nowA,nextB);
				addEdge(nowB,nextA);
			}
		}
	}
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
	for(int i=0;i<2*n;i++)
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
	int T;
	int a,b,c,cas=1;
	input(T);
	while(T--)
	{
		printf("Case #%d: ",cas++);
		init();
		input(n>>m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			--a;
			for(int j=0;j<2;j++)
			{
				type[i][j]=(a+j)%3;
			}
		}

		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			--a;--b;
			if(c==0) setSame(a,b);
			else setDiff(a,b);
		}

		if(zSat()) puts("yes");
		else puts("no");
	}
	return 0;
}



