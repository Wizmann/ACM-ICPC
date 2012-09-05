//Result:2012-07-06 13:46:59	Accepted	3887	1078MS	4840K	1939 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010

struct node 
{
	int dest,next;
	node(){}
	node(int i_dest,int i_next)
	{
		dest=i_dest;next=i_next;
	}
};

int l[SIZE],r[SIZE],ans[SIZE];
int baum[SIZE<<1];
int cnt,ind;

int head[SIZE];
node g[SIZE<<1];
int n,root;

inline int lowbit(int x)
{
	return x & (-x);
}


void init()
{
	memset(ans,0,sizeof(ans));
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(baum,0,sizeof(baum));
	memset(head,-1,sizeof(head));
	memset(g,0,sizeof(g));
	cnt=1;
	ind=0;
}

void addEdge(int a,int b)
{
	g[ind]=node(b,head[a]);
	head[a]=ind++;
}
	

void dfs()
{
	bitset<SIZE> visit;
	stack<int> st;
	st.push(root);
	while(!st.empty())
	{
		int now=st.top();
		if(!visit[now])
		{
			l[now]=cnt++;
			visit[now]=1;
		}
		bool pushed=false;
		for(int i=head[now];i!=-1;i=g[i].next)
		{
			int next=g[i].dest;
			if(!visit[next])
			{
				st.push(next);
				head[now]=g[i].next;
				pushed=true;
			}
		}

		if(pushed) continue;
		else if(visit[now])
		{
			r[now]=cnt++;
			st.pop();
		}
	}
}

int sum(int x)
{
	int res=0;
	while(x)
	{
		res+=baum[x];
		x-=lowbit(x);
	}
	return res;
}

void modify(int x,int val)
{
	int res=0;
	while(x<cnt)
	{
		baum[x]+=val;
		x+=lowbit(x);
	}
}

void slove()
{
	for(int i=1;i<=n;i++)
	{
		ans[i]=sum(r[i])-sum(l[i]-1);
		modify(l[i],1);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(scanf("%d%d",&n,&root)!=EOF && n+root)
	{
		init();
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}
		dfs();
		slove();
		for(int i=1;i<=n;i++)
		{
			if(i>1) printf(" ");
			printf("%d",ans[i]);
		}
		puts("");
	}
	return 0;
}

