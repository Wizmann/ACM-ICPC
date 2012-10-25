//Result:2012-10-16 21:46:57	Accepted	3622	1140MS	680K	2838 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define NODE 256
#define EDGE NODE*NODE*2

const double eps=1e-6;

inline double mul(double x)
{
	return x*x;
}

struct point
{
	int x,y;
	point(){}
	point(int ix,int iy)
	{
		x=ix;y=iy;
	}
};

struct node
{
	int val,next;
	node(){}
	node(int ival,int inext)
	{
		val=ival;next=inext;
	}
};

inline double pntDis(const point& a,const point& b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

int n;
point array[NODE][2];
int ind;
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

inline void addEdge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind++;
	//print(a<<"-->"<<b);
}

bool check(int a,int b,int ap,int bp,double x)
{
	double dis=pntDis(array[a][ap],array[b][bp]);
	if(dis>=2*x) return true;
	else return false;
}


void makeG(double x)
{
	init();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++) if(i!=j)
		{
			if(!check(i,j,0,0,x))
			{
				addEdge(i,j+n);
				addEdge(j,i+n);
			}
			if(!check(i,j,1,0,x))
			{
				addEdge(i+n,j+n);
				addEdge(j,i);
			}
			if(!check(i,j,0,1,x))
			{
				addEdge(i,j);
				addEdge(j+n,i+n);
			}
			if(!check(i,j,1,1,x))
			{
				addEdge(i+n,j);
				addEdge(j+n,i);
			}
		}
	}
}

bool zSat(double x)
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


double slove()
{
	double l=0,r=20000000;
	while(fabs(r-l)>eps)
	{
		double mid=(l+r)/2;
		if(zSat(mid)) l=mid;
		else r=mid;
	}
	return r;
}

int main()
{
	freopen("input.txt","r",stdin);
	double a,b;
	while(input(n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a,&b);
			array[i][0]=point(a,b);
			scanf("%lf%lf",&a,&b);
			array[i][1]=point(a,b);
		}
		printf("%.2f\n",slove());
	}
	return 0;
}

