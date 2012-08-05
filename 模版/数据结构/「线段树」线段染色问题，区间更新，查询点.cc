#include <cstdio>
#include <cstring>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010
#define UNSET -1
#define COLOR 32

inline int left(int x)
{
	return (x<<1)+1;
}
inline int right(int x)
{
	return left(x)+1;
}


int ans;

struct node
{
	int l,r,color;
	node(){}
	node(int il,int ir,int ic)
	{
		l=il;r=ir;color=ic;
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

node stree[SIZE<<2];
int l,t,q;
const int ROOT=0;
bitset<COLOR> colorlist;

void init_stree(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r,1);
	if(l<r)
	{
		int mid=(l+r)>>1;
		init_stree(l,mid,left(pos));
		init_stree(mid+1,r,right(pos));
	}
}

void setcolor(int l,int r,int color,int pos)
{
	if(l>r) return;
	if(stree[pos].equal(l,r))
	{
		stree[pos].color=color;
	}
	else
	{
		int mid=stree[pos].getmid();
		if(stree[pos].color!=UNSET)
		{
			//标记向下扩展
			//Very Important!
			//是stree[pos].l,mid与mid+1,stree[pos].r！！！
			setcolor(stree[pos].l,mid,stree[pos].color,left(pos));
			setcolor(mid+1,stree[pos].r,stree[pos].color,right(pos));
		}
		stree[pos].color=UNSET;
		if(r<=mid) setcolor(l,r,color,left(pos));
		else if(l>mid) setcolor(l,r,color,right(pos));
		else
		{
			setcolor(l,mid,color,left(pos));
			setcolor(mid+1,r,color,right(pos));
		}
	}
}

void newcolor(int x)
{
	if(!colorlist[x])
	{
		colorlist[x]=1;
		ans++;
	}
}

void query(int l,int r,int pos)
{
	if(l>r) return;
	if(stree[pos].color!=UNSET) newcolor(stree[pos].color);
	else
	{
		int mid=stree[pos].getmid();
		if(r<=mid) query(l,r,left(pos));
		else if(l>mid) query(l,r,right(pos));
		else
		{
			query(l,mid,left(pos));
			query(mid+1,r,right(pos));
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	char cmd[4];
	int a,b,c;
	scanf("%d%d%d",&l,&t,&q);
	init_stree(0,l);

	while(q--)
	{
		scanf("%s",cmd);
		if(*cmd=='C')
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a>b) swap(a,b);
			setcolor(a-1,b-1,c,ROOT);
		}
		else
		{
			scanf("%d%d",&a,&b);
			if(a>b) swap(a,b);
			colorlist.reset();
			ans=0;
			query(a-1,b-1,ROOT);
			printf("%d\n",ans);
		}
	}
	return 0;
}

	
