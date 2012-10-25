//Result:2012-10-15 21:04:44	 Accepted	3656	C++	1010	9044	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE=512;
const int NODE=1024;
const int EDGE=1000000;
               

struct node
{
	int val,next;
	node(){}
	node(int ival,int inext)
	{
		val=ival;next=inext;
	}
};

int n,ind;
int head[NODE];
node g[EDGE];

char instack[NODE];
stack<int> st;
int dfn[NODE],scc[NODE],num[NODE],low[NODE];
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
	while(!st.empty())
	{
		st.pop();
	}
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

int B[SIZE][SIZE];

inline void addEdge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind++;
}

bool makeG(int x)
{
	init();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int val=B[i][j]&(1<<x);
			if(val) val=1;
			else val=0;

			int nri=i;
			int nrj=j;
			int _nri=i+n;
			int _nrj=j+n;
			
			if(i==j)
			{
				if(val) return false;
			}
			else if(i%2==1 && j%2==1)
			{
				if(!val) addEdge(nri,_nri);
				else addEdge(_nri,nrj);
			}
			else if(i%2==0 && j%2==0)
			{
				if(val) addEdge(_nri,nri);
				else addEdge(nri,_nrj);
			}
			else
			{
				if(val)
				{
					addEdge(nri,_nrj);
					addEdge(_nri,nrj);
				}
				else
				{
					addEdge(nri,nrj);
					addEdge(_nri,_nrj);
				}
			}
		}
	}
	return true;
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
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&B[i][j]);
			}
		}
		bool flag=true;
		for(int i=0;i<32;i++)
		{
			if(makeG(i))
			{
				if(!zSat())
				{
					flag=false;
					break;
				}
			}
			else
			{
				flag=false;
				break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
