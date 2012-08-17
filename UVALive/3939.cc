//Result:3939	Plucking fruits	Accepted	C++	0.108	2012-08-13 12:05:51
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100

struct node
{
	int st,end,dis,id;
	node(){}
	node(int ist,int iend,int idis,int iid=-1)
	{
		id=iid;
		st=ist;end=iend;dis=idis;
	}
	friend bool operator < (const node &a,const node &b)
	{
		return a.dis>b.dis;
	}
};

node g[SIZE],ask[SIZE];
int n,m,r;
bitset<SIZE> ans;
int ptr;

int father[SIZE];
int findfather(int x)
{
	if(father[x]==x) return x;
	else return father[x]=findfather(father[x]);
}

void makeG(int val)
{
	while(ptr<m && g[ptr].dis>=val)
	{
		father[findfather(g[ptr].st)]=findfather(g[ptr].end);
		ptr++;
	}
}

static inline bool cnc(int a,int b)
{
	return findfather(a)==findfather(b);
}

void slove()
{
	ptr=0;
	for(int i=0;i<SIZE;i++) father[i]=i;
	ans.reset();
	for(int i=0;i<r;i++)
	{
		int val=ask[i].dis;
		makeG(val);
		if(cnc(ask[i].st,ask[i].end))
		{
			ans[ask[i].id]=1;
		}
	}
	for(int i=0;i<r;i++)
	{
		if(ans[i]) puts("yes");
		else puts("no");
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c;
	int cas=1;
	while(input(n>>m>>r))
	{
		printf("Case %d:\n",cas++);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[i]=node(a,b,c);
		}
		sort(g,g+m);
		for(int i=0;i<r;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			ask[i]=node(a,b,c,i);
		}
		sort(ask,ask+r);
		slove();
	}
	return 0;
}
