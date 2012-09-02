//Result:2012-08-29 16:33:31	Accepted	4398	156MS	3660K	2044 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#include <map>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010
#define INF 1<<28

struct _link
{
	int val,next;
	_link(){}
	_link(int ival,int inext)
	{
		val=ival;next=inext;
	}
};

struct node
{
	int nr,npos;
	node(){}
	node(int inr,int inpos)
	{
		nr=inr;npos=inpos;
	}
	friend bool operator < (const node &a,const node &b)
	{
		if(a.npos!=b.npos) return a.npos<b.npos;
		else return a.nr<b.nr;
	}
};

_link g[SIZE<<1];
int head[SIZE];
map<int,int> hash;
int ptr,ind,n,k;
set<node> pq;
int array[SIZE];

void addG(int nr,int pos)
{
	if(head[nr]==-1)
	{
		g[ind]=_link(INF,-1);
		head[nr]=ind++;
	}
	g[ind]=_link(pos,head[nr]);
	head[nr]=ind++;
}

inline int getPos(int nr)
{
	return g[head[nr]].val;
}

inline void getNext(int nr)
{
	if(g[head[nr]].val==INF) return;
	head[nr]=g[head[nr]].next;
}

int slove()
{
	int ans=0;
	set<node>::iterator iter;
	
	for(int i=0;i<n;i++)
	{
		array[i]=hash[array[i]];
		iter=pq.find(node(array[i],getPos(array[i])));
		if(iter==pq.end())
		{
			ans++;
			getNext(array[i]);
			pq.insert(node(array[i],getPos(array[i])));
			pq.erase(--pq.end());
		}
		else
		{
			getNext(iter->nr);
			node nn=node(iter->nr,getPos(iter->nr));
			pq.erase(iter);
			pq.insert(nn);
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n>>k))
	{
		pq.clear();
		hash.clear();
		ptr=ind=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=k;i++)
		{
			hash[i]=++ptr;
			addG(hash[i],INF);
		}
		for(int i=0;i<n;i++) scanf("%d",array+i);
		for(int i=n-1;i>=0;i--)
		{
			int a=array[i];
			if(hash.find(a)==hash.end()) hash[a]=++ptr;
			addG(hash[a],i);
		}

		for(int i=1;i<=k;i++)
		{
			int nr=hash[i];
			int pos=getPos(hash[i]);
			pq.insert(node(nr,pos));
		}
		print(slove());
	}
	return 0;
}


