//Result:2012-08-06 13:10:52	Accepted	3874	2078MS	7376K	2090 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010
#define QUERY 200100

typedef long long llint;

inline int lowbit(int x){return x&(-x);}

llint baum[SIZE];

void add(int pos,int val)
{
	while(pos<SIZE)
	{
		baum[pos]+=val;
		pos+=lowbit(pos);
	}
}

llint getsum(int pos)//1...pos
{
	llint res=0;
	while(pos>0)
	{
		res+=baum[pos];
		pos-=lowbit(pos);
	}
	return res;
}

llint getsum(int a,int b)
{
	return getsum(b)-getsum(a-1);
}

struct query
{
	int st,end,nr;
	query(){}
	query(int ist,int iend,int inr)
	{
		st=ist;end=iend;nr=inr;
	}
	friend bool operator < (const query& a,const query& b)
	{
		return a.st<b.st;
	}
	inline llint getans(){return getsum(st,end);}
};

query ask[QUERY];
int array[SIZE];
int ind,n;
llint ans[QUERY];
deque<int> g[SIZE];
map<int,int> hash;

void addval(int val,int pos,int toh)
{
	if(g[toh].empty())
	{
		add(pos,val);
		array[pos]=val;
	}
	g[toh].push_back(pos);
}

void getnext(int val)
{
	int toh=hash[val];
	if(val<0 || g[toh].empty()) return;

	g[toh].pop_front();
	if(!g[toh].empty())
	{
		array[g[toh][0]]=val;
		add(g[toh][0],val);
	}
}



int main()
{
	int T,a,b,q;
	input(T);
	while(T--)
	{
		for(int i=0;i<SIZE;i++) g[i].clear();
		hash.clear();
		scanf("%d",&n);
		ind=0;
		memset(baum,0,sizeof(baum));
		memset(array,-1,sizeof(array));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(hash.find(a)==hash.end()) hash[a]=ind++;
			addval(a,i,hash[a]);
		}
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&a,&b);
			ask[i]=query(a,b,i);
		}
		sort(ask+1,ask+q+1);

		int start=0;
		for(int i=1;i<=q;i++)
		{
			int nr=ask[i].nr;
			ans[nr]=ask[i].getans();
			while(i+1<=q && start<ask[i+1].st)
			{
				getnext(array[start]);
				start++;
			}
		}
		for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	}
	return 0;
}
