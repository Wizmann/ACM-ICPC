/*
由于在2-SAT问题中，最多只对两个元素进行限制，所以可能的限制关系有：
A[x] => addEdge(a+n,a)
NOT A[x] => addEdge(a,a+n)
A[x] OR A[y] => addEdge(a+n,b),addEdge(b+n,a)
A[x] OR NOT A[y] => addEdge(a+n,b+n),addEdge(b,a)
NOT A[x] or NOT A[y] => addEdge(a,b+n),addEdge(b,a+n)
A[x] XOR A[y] => addEdge(a,b+n),addEdge(a+n,b),addEdge(b,a+n),addEdge(b+n,a)
NOT (A[x] XOR A[y]) 
A[x] XOR NOT A[y]
*/

//Result:wizmann	2296	Accepted	428K	16MS	C++	2487B	2012-10-15 20:57:02
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 512
#define EDGE NODE*NODE

struct point
{
	int x,y;
	point(){}
	point(int ix,int iy){x=ix;y=iy;}
};

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

int n,m,ind;
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

point array[NODE];

inline void addEdge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind++;
}

void makeG(int x)
{
	init();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) if(i!=j)
		{
			if(abs(array[i].x-array[j].x)>=x) continue;
			else
			{
				int d=array[i].y-array[j].y;
				if(abs(d)>=2*x) continue;
				if(d>=x) addEdge(i+n,j+n);//i在j上，i窗口为下的时候，j窗口必为下
				else if(d>0) addEdge(i+n,i);//i窗口为下的时候，j点在i窗口内，所以i窗口不能为下
				else if(d==0)
				{
					addEdge(i,j+n);
					addEdge(i+n,j);
				}
				else if(d>-x) addEdge(i,i+n);
				else if(d>-2*x) addEdge(i,j);
			}
		}
	}
}

bool zSat(int x)
{
	makeG(x);
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

int slove()
{
	int l=0,r=20000;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(zSat(mid)) l=mid+1;
		else r=mid-1;
	}
	return r;
}

int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b;
	input(T);
	while(T--)
	{
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			array[i]=point(a,b);
		}
		print(slove());
	}
	return 0;
}



