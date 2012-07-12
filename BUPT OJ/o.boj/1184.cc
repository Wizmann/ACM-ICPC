//Result:1184	Accepted	3480MS	33028K	G++	 2058B	2012-07-12 21:21:27	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 2000005
#define INF 1<<30

int n,m;
int num[SIZE];

inline int left(int x)
{
	return (x<<1)+1;
}
inline int right(int x)
{
	return (x<<1)+2;
}

struct node
{
	int l,r;
	int mini,maxi;
	node(){}
	node(int i_l,int i_r)
	{
		l=i_l;r=i_r;
		mini=INF;maxi=-INF;
	}
	
	inline void setmaxi(int x)
	{
		maxi=max(maxi,x);
	}
	inline void setmini(int x)
	{
		mini=min(mini,x);
	}
	inline int getmid()
	{
		return (l+r)>>1;
	}
	
	inline bool equal(int i_l,int i_r)
	{
		return i_l==l and i_r==r;
	}
};

node stree[SIZE];

void init(int nr=0,int l=0,int r=n-1)
{
	stree[nr]=node(l,r);
	if(l<r)
	{	
		int mid=(l+r)>>1;
		init(left(nr),l,mid);
		init(right(nr),mid+1,r);
	}
}

void insert(int nr,int val,int pos)
{
	stree[pos].setmaxi(val);
	stree[pos].setmini(val);
	
	if(stree[pos].l==stree[pos].r) return;
	else
	{
		int mid=stree[pos].getmid();
		if(nr<=mid) insert(nr,val,left(pos));
		else insert(nr,val,right(pos));
	}
}

void query(int pos,int l,int r,int &maxi,int &mini)
{
	int mid=stree[pos].getmid();
	if(stree[pos].equal(l,r))
	{
		maxi=stree[pos].maxi;
		mini=stree[pos].mini;
	}
	else if(r<=mid) query(left(pos),l,r,maxi,mini);
	else if(l>mid) query(right(pos),l,r,maxi,mini);
	else
	{
		int lmaxi=-INF,lmini=INF;
		int rmaxi=-INF,rmini=INF;
		
		query(left(pos),l,mid,lmaxi,lmini);
		query(right(pos),mid+1,r,rmaxi,rmini);
		
		maxi=max(lmaxi,rmaxi);
		mini=min(lmini,rmini);
	}
}
	

int main()
{
	freopen("input.txt","r",stdin);
	int a;
	input(n>>m);
	init();
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		insert(i,a,0);
	}
	int l=0,r=0;
	int ans=-1;
	while(1)
	{
		int maxi=-INF,mini=INF;
		query(0,l,r,maxi,mini);
		if(maxi-mini<=m)
		{
			r++;
			ans=max(ans,r-l);
		}
		else l++;

		if(r==n) break;
	}
	print(ans);
	return 0;
}


