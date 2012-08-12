//Result:wizmann	1823	Accepted	1016K	3485MS	C++	2699B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 16160

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
	int now,lson,rson,val;

	node(){}
	node(int il,int ir)
	{
		l=il;r=ir;
		val=0;
		now=lson=rson=this->cover();
	}

	bool equal(int il,int ir)
	{
		return l==il && r==ir;
	}

	int getmid()
	{
		return (l+r)>>1;
	}
	
	bool has_next()
	{
		if(l==r) return false;
		else return true;
	}
	
	int cover()
	{
		return (r-l+1);
	}
};

node stree[SIZE<<2];
const int ROOT=0;
int n,q;

void stree_init(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r);
	if(l<r)
	{
		int mid=(l+r)>>1;
		stree_init(l,mid,left(pos));
		stree_init(mid+1,r,right(pos));
	}
}

void stree_cover(int l,int r,int val,int pos=ROOT)
{
	if(stree[pos].equal(l,r))
	{
		stree[pos].val=val;
		if(val==0)
		{
			stree[pos].now=stree[pos].rson=stree[pos].lson=stree[pos].cover();
		}
		else
		{
			stree[pos].now=stree[pos].rson=stree[pos].lson=0;
		}
	}
	else
	{
		if(stree[pos].val!=-1)
		{
			stree_cover(stree[left(pos)].l,stree[left(pos)].r,stree[pos].val,left(pos));
			stree_cover(stree[right(pos)].l,stree[right(pos)].r,stree[pos].val,right(pos));
			stree[pos].val=-1;
		}

		int mid=stree[pos].getmid();
		if(mid>=r) stree_cover(l,r,val,left(pos));
		else if(mid<l) stree_cover(l,r,val,right(pos));
		else
		{
			stree_cover(l,mid,val,left(pos));
			stree_cover(mid+1,r,val,right(pos));
		}
		stree[pos].now=max(max(stree[left(pos)].now,stree[right(pos)].now),stree[left(pos)].rson+stree[right(pos)].lson);
		if(stree[left(pos)].lson==stree[left(pos)].cover())
		{
			stree[pos].lson=stree[left(pos)].lson+stree[right(pos)].lson;
		}
		else stree[pos].lson=stree[left(pos)].lson;

		if(stree[right(pos)].rson==stree[right(pos)].cover())
		{
			stree[pos].rson=stree[right(pos)].rson+stree[left(pos)].rson;
		}
		else stree[pos].rson=stree[right(pos)].rson;
	}
	//printf("L:%d R:%d  VAL:%d  SPACE:%d  LSPA:%d   RSPA:%d\n",stree[pos].l,stree[pos].r,stree[pos].val,stree[pos].now,stree[pos].lson,stree[pos].rson);
}


int main()
{
	freopen("input.txt","r",stdin);
	int cmd,a,b;
	while(input(n>>q))
	{
		stree_init(1,n);
		while(q--)
		{
			scanf("%d",&cmd);
			if(cmd<=2)
			{
				scanf("%d%d",&a,&b);
				//print(">>"<<a<<' '<<a+b-1);
				stree_cover(a,a+b-1,cmd&1);
				//puts("-----------------------------");
			}
			else
			{
				printf("%d\n",stree[ROOT].now);
			}
		}
	}
	return 0;
}
