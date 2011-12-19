//RESULT:  BOJ-1454 	Accepted	462MS	8056K	G++	1710B	2011-06-04 09:59:57	Wizmann 

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define left(x) ((x<<1)+1)
#define right(x) ((x<<1)+2)
#define SIZE 80100
#define START 0

int bird[SIZE];

typedef struct node
{
	int l,r,val;
	
	inline void setnode(int a,int b,int c)
	{
		l=a;r=b;val=c;
	}
}node;

inline int mid(int a,int b){return (a+b)>>1;}
node stree[SIZE*8];

void init(int pos,int l,int r)
{
	stree[pos].l=l;
	stree[pos].r=r;
	stree[pos].val=-1;
	
	if(l<r)
	{
		int m=mid(l,r);
		init(left(pos),l,m);
		init(right(pos),m+1,r);
	}
}

int find(int pos,int l,int r,int val)
{
	if(l<=r)
	{
		if(stree[pos].val<val) return stree[pos].r;
		else
		{
			int m=mid(stree[pos].l,stree[pos].r);
			if(r<=m) return find(left(pos),l,r,val);
			else if(l>=m+1) return find(right(pos),l,r,val);
			else
			{
				int t=find(left(pos),l,m,val);
				if(t==m)
				{
					int q=find(right(pos),m+1,r,val);
					if(q>0) return q;
					else return t;
				}
				else return t;
			}
		}
	}
	else return -1<<20;
}

void make(int pos,int r,int val)
{
	if(r>=stree[pos].l&&r<=stree[pos].r)
	{
		if(val>stree[pos].val) stree[pos].val=val;
		
		int m=mid(stree[pos].l,stree[pos].r);
		if(r<=m) make(left(pos),r,val);
		else if(r>=m+1) make(right(pos),r,val);
	}
}
//Muti-Cases of data...Fxxk...
int main()
{
	freopen("input.txt","r",stdin);
	int n,a;
	while(scanf("%d",&n),n)
	{
		memset(stree,-1,sizeof(stree));
		memset(bird,0,sizeof(bird));
		long long res=0;
		init(START,0,n-1);
		for(int i=0;i<n;i++) scanf("%d",&bird[i]);
		for(int i=n-1;i>=0;i--)
		{
			a=bird[i];
			res+=(find(START,i,n-1,a)-i);
			make(START,i,a);
		}
		printf("%lld\n",res);
	}
	return 0;
}
	
