#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define UINT unsigned int
#define SIZE 40500
#define START 0

typedef struct star
{
	UINT x,y,val;
	
	inline void setstar(UINT a,UINT b,UINT c)
	{
		x=a;y=b;val=c;
	}
}star;

typedef struct node
{
	UINT x,no;
	bool add;
	
	inline void setnode(UINT a,bool b,UINT c)
	{
		x=a;add=b;no=c;
	}
	
	friend bool operator < (const node s1,const node s2)
	{
		if(s1.x==s2.x)
		{
			if(s1.add==true||s2.add==false) return false;
			else return true;
		}
		else return s1.x<s2.x;
	}
}node;

typedef struct leaf
{
	UINT l,r;
	UINT cover,res;
}leaf;

star stars[SIZE];
node scan[SIZE<<2];
leaf stree[SIZE<<6];
UINT nr,n,w,h;

void add(UINT pos,UINT left,UINT right,UINT l,UINT r,UINT val)
{
	if(left==l&&right==r)
	{
		stree[pos].cover+=val;
		stree[pos].res+=val;
	}
	else
	{
		UINT mid=(l/2)+(r/2)+(l%2+r%2)/2;
		if(right<=mid)
		{
			if(stree[pos].l==0) stree[pos].l=++nr;
			add(stree[pos].l,left,right,l,mid,val);
		}
		else if(left>=mid)
		{
			if(stree[pos].r==0) stree[pos].r=++nr;
			add(stree[pos].r,left,right,mid,r,val);
		}
		else
		{
			if(stree[pos].l==0) stree[pos].l=++nr;
			add(stree[pos].l,left,mid,l,mid,val);
			if(stree[pos].r==0) stree[pos].r=++nr;
			add(stree[pos].r,mid,right,mid,r,val);
		}
	}
	UINT t=0;
	if(stree[pos].l) t=stree[stree[pos].l].res;
	if(stree[pos].r) t=max(t,stree[stree[pos].r].res);
	
	stree[pos].res=stree[pos].cover+t;
}

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%u",&n)!=EOF)
	{
		scanf("%u%u",&w,&h);
		for(UINT i=1;i<=n;i++)
		{
			UINT a,b,c;
			scanf("%u%u%u",&a,&b,&c);
			stars[i].setstar(a,b,c);
			scan[i*2-1].setnode(a,true,i);
			scan[i*2].setnode(a+w,false,i);
			//插入扫描线，是离散化的一种。。。
		}
		sort(scan+1,scan+(n<<1)+1);//以X坐标为基排序
		UINT ans=0;
		nr=0;
		memset(stree,0,sizeof(stree));
		for(UINT i=1;i<=(n<<1);i++)
		{
			UINT t=scan[i].no;
			if(scan[i].add)
			{
				add(START,stars[t].y,stars[t].y+h,0,INT_MAX,stars[t].val);
				ans=max(ans,stree[START].res);
			}
			else
			{
				add(START,stars[t].y,stars[t].y+h,0,INT_MAX,-stars[t].val);
			}
		}
		printf("%u\n",ans);
	}
	return 0;
}
			
			
