//Result:wizmann	3928	Accepted	664K	297MS	C++	1528B
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20480

struct BIT
{
	int baum[SIZE];
	void init(){memset(baum,0,sizeof(baum));}
	inline int lowbit(int x){return x&(-x);}
	void add(int pos,int val)
	{
		while(pos<SIZE)
		{
			baum[pos]+=val;
			pos+=lowbit(pos);
		}
	}
	int sum(int pos)
	{
		int res=0;
		while(pos>0)
		{
			res+=baum[pos];
			pos-=lowbit(pos);
		}
		return res;
	}
	int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};

struct node
{
	int pos,skill;
	node(){}
	node(int ipos,int iskill)
	{
		pos=ipos;skill=iskill;
	}
	friend bool operator < (const node& a,const node& b)
	{
		return a.skill<b.skill;
	}
};

int main()
{
	freopen("input.txt","r",stdin);
	BIT bit;
	int T,n,a;
	node player[SIZE];
	int lson[SIZE],rson[SIZE];
	input(T);
	while(T--)
	{
		input(n);
		memset(lson,0,sizeof(lson));
		memset(rson,0,sizeof(rson));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			player[i]=node(i,a);
		}
		long long ans=0;
		sort(player+1,player+n+1);
		bit.init();
		for(int i=1;i<=n;i++)
		{
			int pos=player[i].pos;
			lson[pos]=bit.sum(1,pos-1);
			rson[pos]=bit.sum(pos+1,n);
			bit.add(pos,1);
		}
		bit.init();
		for(int i=n;i>=1;i--)
		{
			int pos=player[i].pos;
			ans+=lson[pos]*bit.sum(pos+1,n);
			ans+=rson[pos]*bit.sum(1,pos-1);
			bit.add(pos,1);
		}
		print(ans);
	}
	return 0;
}
