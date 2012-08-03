//Result:2012-08-01 17:24:08	Accepted	4325	640MS	3444K	2562 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010
#define left(x) ((x<<1)+1)
#define right(x) (left(x)+1)

const int ROOT=0;

struct node
{
	int l,r;
	int val;
	node(){}
	node(int il,int ir,int ival)
	{
		l=il;r=ir;
		val=ival;
	}
	
	bool under_cover(int il,int ir)
	{
		//i'm the old lover undercover.
		return il<=l && ir>=r;
	}
	
	bool equal(int x)
	{
		return x==l && x==r;
	}
	
	int getmid()
	{
		return (l+r)>>1;
	}
};

int n,q;
node stree[SIZE<<2];
int flower[SIZE][2],query[SIZE];
int ind;
map<int,int> hash;

void init_stree(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r,0);
	if(l!=r)
	{
		int mid=(l+r)>>1;
		init_stree(l,mid,left(pos));
		init_stree(mid+1,r,right(pos));
	}
}

void insert(int l,int r,int val,int pos=ROOT)
{
	if(stree[pos].under_cover(l,r))
	{
		stree[pos].val++;
		return;
	}
	else
	{
		if(stree[pos].val>0)
		{
			stree[left(pos)].val+=stree[pos].val;
			stree[right(pos)].val+=stree[pos].val;
			stree[pos].val=0;
		}
		int mid=stree[pos].getmid();
		if(l<=mid) insert(l,r,val,left(pos));
		if(r>mid) insert(l,r,val,right(pos));
	}
}


int ask(int x,int pos=ROOT)
{
	if(stree[pos].equal(x)) return stree[pos].val;
	else
	{
		if(stree[pos].val>0)
		{
			stree[left(pos)].val+=stree[pos].val;
			stree[right(pos)].val+=stree[pos].val;
			stree[pos].val=0;
		}
		int mid=stree[pos].getmid();
		if(x<=mid) return ask(x,left(pos));
		else return ask(x,right(pos));
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b;
	input(T);
	int sweap[SIZE<<1];
	int sw;
	int cas=1;
	while(T--)
	{
		printf("Case #%d:\n",cas++);
		hash.clear();
		memset(sweap,-1,sizeof(sweap));
		sw=1;
		ind=0;
		input(n>>q);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			flower[i][0]=a;flower[i][1]=b;
			sweap[sw++]=a;
			sweap[sw++]=b;
		}
		for(int i=0;i<q;i++)
		{
			scanf("%d",&a);
			query[i]=a;
			sweap[sw++]=a;
		}
		sort(sweap+1,sweap+sw);
		for(int i=1;i<sw;i++)
		{
			if(sweap[i]!=sweap[i-1])
			{
				//print(sweap[i]<<"<-"<<ind);
				hash[sweap[i]]=ind++;
			}
		}
		init_stree(0,ind);
		for(int i=0;i<n;i++)
		{
			insert(hash[flower[i][0]],hash[flower[i][1]],1);
		}
		for(int i=0;i<q;i++)
		{
			printf("%d\n",ask(hash[query[i]]));
		}
	}
	return 0;
}

