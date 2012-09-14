//Result:2012-09-08 19:36:05	Accepted	4272	0MS	560K	1701 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define pb push_back

inline int lowbit(int x)
{
	return x&(-x);
}

int n;
int sz;
int array[SIZE];
vector<int> g[SIZE];
int head[SIZE];
map<int,int> hash;

struct BIT
{
	int baum[SIZE];
	inline void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void add(int x,int val)
	{
		while(x<SIZE)
		{
			baum[x]+=val;
			x+=lowbit(x);
		}
	}
	int sum(int x)
	{
		int res=0;
		while(x>0)
		{
			res+=baum[x];
			x-=lowbit(x);
		}
		return res;
	}
	int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};

BIT bit;

bool slove()
{
	int kill=0;
	bit.init();
	for(int i=1;i<=n;i++) bit.add(i,1);
	for(int i=1;i<=n;i++)
	{
		if(!array[i]) continue;
		int now=array[i];
		int a=g[now][head[now]];
		int b=g[now][head[now]+1];
		if(bit.sum(a,b)<=5+2)
		{
			head[now]+=2;
			kill+=2;
			bit.add(b,-1);
			array[a]=0;
			array[b]=0;
		}
		else break;
	}
	if(kill==n) return true;
	else return false;
}


int main()
{
	freopen("6.txt","r",stdin);
	int a;
	while(input(n))
	{
		sz=1;
		for(int i=0;i<SIZE;i++) g[i].clear();
		memset(head,0,sizeof(head));
		hash.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(hash.find(a)==hash.end())
			{
				hash[a]=sz++;
			}
			g[hash[a]].pb(i);
			array[i]=hash[a];
		}
		bool flag=true;
		for(int i=0;i<sz;i++)
		{
			if(g[i].size()%2==1)
			{
				flag=false;
				break;
			}
		}
		if(flag && slove()) puts("1");
		else puts("0");
	}
	return 0;
}


