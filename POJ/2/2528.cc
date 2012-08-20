//Result: Wizmann	2528	Accepted	22536K	891MS	G++	2040B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <iostream>

#define START 0
#define left(x) ((x<<1)+1)
#define right(x) (left(x)+1)

using namespace std;

typedef struct node
{
	int l,r;
	
	void setnode(int a,int b)
	{
		l=a;r=b;
	}
}node;

typedef struct leaf
{
	int l,r,m,val;
	
	void setleaf(int a,int b)
	{
		l=a;r=b;
		m=(l+r)>>1;
		val=-1;
	}
}leaf;

short hash[10000010];
node array[10010];
leaf stree[10000*8];
int n;
set<int> toHash;
set<int>::iterator iter;

void init(int pos,int l,int r)
{
	stree[pos].setleaf(l,r);
	
	if(l<r)
	{
		int m=stree[pos].m;
		init(left(pos),l,m);
		init(right(pos),m+1,r);
	}
}

void ins(int pos,int l,int r,int val)
{
	if(stree[pos].l==l&&stree[pos].r==r) stree[pos].val=val;
	else
	{
		int m=stree[pos].m;
		if(stree[pos].val!=-1)
		{
			ins(left(pos),stree[pos].l,m,stree[pos].val);
			ins(right(pos),m+1,stree[pos].r,stree[pos].val);
			stree[pos].val=-1;
		}
		
		if(r<=m) ins(left(pos),l,r,val);
		else if(l>=m+1) ins(right(pos),l,r,val);
		else
		{
			ins(left(pos),l,m,val);
			ins(right(pos),m+1,r,val);
		}
	}
}

void query(int pos,int l,int r)
{
	if(stree[pos].val!=-1) toHash.insert(stree[pos].val);
	else if(l<r)
	{
		int m=stree[pos].m;
		query(left(pos),l,m);
		query(right(pos),m+1,r);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		memset(hash,0,sizeof(hash));
		memset(array,0,sizeof(array));
		memset(stree,-1,sizeof(stree));
		toHash.clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			array[i].setnode(a,b);
			toHash.insert(a);
			toHash.insert(b);
		}
		
		iter=toHash.begin();
		int pad=1;
		while(iter!=toHash.end())
		{
			hash[*iter]=pad++;
			iter++;
		}
		toHash.clear();
		
		pad--;
		init(START,1,pad);
		for(int i=0;i<n;i++)
		{
			ins(START,hash[array[i].l],hash[array[i].r],i);
		}
		query(START,1,pad);
		printf("%d\n",toHash.size());
	}
	return 0;
}
			
		
