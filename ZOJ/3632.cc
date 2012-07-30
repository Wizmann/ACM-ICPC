//Result:2012-07-30 14:26:48	 Accepted	3632	C++	760	7608	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 50010
#define INF 1LL<<60

typedef long long llint;

inline int left(int x){return (x<<1)+1;}
inline int right(int x){return left(x)+1;}

struct node
{
	int l,r;
	llint val;
	node(){}
	node(int il,int ir,llint ival)
	{
		l=il;r=ir;val=ival;
	}
	
	bool equal(int il,int ir)
	{
		return l==il && r==ir;
	}
	
	int getmid()
	{
		return (l+r)>>1;
	}
};

node stree[SIZE<<3];
const int ROOT=0;
int n;
llint gold[SIZE];
llint day[SIZE];
llint dp[SIZE];

void init(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r,INF);
	if(l!=r)
	{
		int mid=(l+r)>>1;
		init(l,mid,left(pos));
		init(mid+1,r,right(pos));
	}
}

llint get_mini(int l,int r,int pos=ROOT)
{
	if(stree[pos].equal(l,r)) return stree[pos].val;
	else
	{
		int mid=stree[pos].getmid();
		if(r<=mid) return get_mini(l,r,left(pos));
		else if(l>mid) return get_mini(l,r,right(pos));
		else
		{
			llint a=get_mini(l,mid,left(pos));
			llint b=get_mini(mid+1,r,right(pos));
			return min(a,b);
		}
	}
}

void insert(int l,int r,llint val,int pos=ROOT)
{
	stree[pos].val=min(stree[pos].val,val);
	if(!stree[pos].equal(l,r))
	{
		int mid=stree[pos].getmid();
		if(r<=mid) insert(l,r,val,left(pos));
		else if(l>mid) insert(l,r,val,right(pos));
		else
		{
			insert(l,mid,val,left(pos));
			insert(mid+1,r,val,right(pos));
		}
	}
}

llint DP()
{
	insert(n,n,0);
	for(int i=n-1;i>=0;i--)
	{
		//print(i<<' '<<i+1<<' '<<i+day[i]);
		dp[i]=get_mini(i+1,i+day[i])+gold[i];
		insert(i,i,dp[i]);
	}
	return dp[0];
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n))
	{
		init(0,n);
		for(int i=0;i<n;i++) scanf("%lld",gold+i);
		gold[n]=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",day+i);
			day[i]=min(llint(n-i),day[i]);
		}
		day[n]=1;

		memset(dp,0,sizeof(dp));
		printf("%lld\n",DP());
	}
	return 0;
}


