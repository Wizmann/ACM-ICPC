#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

#define left(x) ((x<<1)+1)
#define right(x) (left(x)+1)
#define START 0
#define SIZE 100010

typedef struct node
{
	int l,r;
	int sum;
	int lmax,lmin;
	int rmax,rmin;
	int smax,smin;
}node;

node stree[SIZE<<2];
int data[SIZE];
int n;

inline int min(int a,int b,int c,int d,int e)
{
	if(a>b) a=b;if(a>c) a=c;if(a>d) a=d;if(a>e) a=e;
	return a;
}

inline int max(int a,int b,int c,int d,int e)
{
	if(a<b) a=b;if(a<c) a=c;if(a<d) a=d;if(a>e) a=e;
	return a;
}

void update(int pos)
{
	int l=left(pos),r=right(pos);
	stree[pos].sum=stree[l].sum+stree[r].sum;
	//每一个节点的和是左儿子的和加上右儿子的和
	stree[pos].lmax=std::max(stree[l].sum+stree[r].lmax,stree[l].lmax);
	//每一个节点，从最左端开始的最大能得到值：MAX(左儿子的和＋右儿子的左端最大值，左儿子的左端最大值）
	stree[pos].lmin=std::min(stree[l].sum+stree[r].lmin,stree[l].lmin);
	//同上。。。
	stree[pos].rmax=std::max(stree[r].sum+stree[l].rmax,stree[r].rmax);
	//再同上。。。
	stree[pos].rmin=std::min(stree[r].sum+stree[l].rmin,stree[r].rmin);
	//再再同上。。。
	stree[pos].smin=min(stree[l].smin,stree[r].smin,stree[l].rmin+stree[r].lmin,stree[pos].lmin,stree[pos].rmin);
	//每一个节点的区间最小值：MIN(
	//左儿子的区间最小值
	//右儿子的区间最小值
	//左儿子的右端最小值＋右儿子的左端最小值
	//左端最小值，右端最小值）
	stree[pos].smax=max(stree[l].smax,stree[r].smax,stree[l].rmax+stree[r].lmax,stree[pos].lmax,stree[pos].rmax);
	//同上

}

void init(int pos,int l,int r)
{
	stree[pos].l=l;
	stree[pos].r=r;
	if(l==r)
	{
		stree[pos].sum=stree[pos].smax=stree[pos].smin=data[l];
		stree[pos].lmin=stree[pos].lmax=stree[pos].rmin=stree[pos].rmax=data[l];
	}
	else
	{
		int m=(l+r)>>1;
		init(left(pos),l,m);
		init(right(pos),m+1,r);
		update(pos);
	}
}

void modify(int pos,int p,int val)
{
	if(stree[pos].l==stree[pos].r&&stree[pos].l==p)
	{
		stree[pos].sum=stree[pos].smin=stree[pos].smax=val;
		stree[pos].lmin=stree[pos].lmax=stree[pos].rmin=stree[pos].rmax=val;
	}
	else
	{
		int m=(stree[pos].l+stree[pos].r)>>1;
		if(p<=m) modify(left(pos),p,val);
		else modify(right(pos),p,val);
		
		update(pos);
	}
}
		

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&data[i]);
	init(START,1,n);
	
	int ask;
	int pos,val;
	scanf("%d",&ask);
	while(ask--)
	{
		scanf("%d%d",&pos,&val);
		modify(START,pos,val);
		
		if(stree[START].sum==stree[START].smax)
		{
			printf("%d\n",stree[START].sum-stree[START].smin);
		}
		else
		{
			printf("%d\n",std::max(stree[START].smax,stree[START].sum-stree[START].smin));
			//这里是处理环形的重要代码
			//如果是1~n部分的，就是stree[START].smax，最大子段和
			//如果是4~n+n~2部分的（举例），就是stree[START].sum-stree[START].smin，减去最小子段，必为负数。。。
		}
	}
	return 0;
}
